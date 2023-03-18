#ifdef _MSC_VER

#include "internal/msvc_wshelper.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strsafe.h>
#include <tchar.h>
#include <windows.h>

#define RECV_BUF_SIZE 1048576

static HANDLE hReadStdin = NULL;
static HANDLE hWriteStdin = NULL;
static HANDLE hReadStdout = NULL;
static HANDLE hWriteStdout = NULL;

static bool Write(const char* msg);
static bool Read(char* buffer);

void Launch() {
  SECURITY_ATTRIBUTES sa;
  sa.nLength = sizeof(SECURITY_ATTRIBUTES);
  sa.lpSecurityDescriptor = NULL;
  sa.bInheritHandle = TRUE;

  if (!CreatePipe(&hReadStdin, &hWriteStdin, &sa, 0)) {
    printf("CreatePipe stdin failed\n");
  }

  if (!CreatePipe(&hReadStdout, &hWriteStdout, &sa, 0)) {
    printf("CreatePipe stdout failed\n");
  }

  if (!SetHandleInformation(hWriteStdin, HANDLE_FLAG_INHERIT, 0)) {
    printf("SetHandleInformation stdin failed\n");
  }

  if (!SetHandleInformation(hReadStdout, HANDLE_FLAG_INHERIT, 0)) {
    printf("SetHandleInformation stdout failed\n");
  }

  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  si.dwFlags = STARTF_USESTDHANDLES;
  si.hStdOutput = hWriteStdout;
  si.hStdError = hWriteStdout;
  si.hStdInput = hReadStdin;

  char cmd[] = "wshelper.exe";
  if (!CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
    printf("CreateProcess failed\n");
  }

  CloseHandle(hWriteStdout);
  CloseHandle(hReadStdin);
}

GoUint8 Connect(char* c_url) {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  sprintf(buffer, "connect %s\n", c_url);
  Write(buffer);

  memset(buffer, 0, sizeof(buffer));

  size_t bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer);
  }

  int result;
  sscanf(buffer, "%d", &result);

  return (GoUint8)(result == 0);
}

void Disconnect() {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  sprintf(buffer, "disconnect\n");
  Write(buffer);

  memset(buffer, 0, sizeof(buffer));

  size_t bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer);
  }
}

GoUint8 IsConnected() {
  printf("IsConnected\n");

  static char buffer[1024];
  int result;

  while (true) {
    memset(buffer, 0, sizeof(buffer));
    Write("is_connected\n");
    Read(buffer);
    printf("Read:%s\n", buffer);
    getchar();

    if (sscanf(buffer, "%d", &result) == 1) {
      break;
    }
  }

  return (GoUint8)(result == 1);
}

GoUint8 Send(char* c_msg) {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  sprintf(buffer, "%s\n", c_msg);
  Write(buffer);

  memset(buffer, 0, sizeof(buffer));

  size_t bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer);
  }

  int result;
  sscanf(buffer, "%d", &result);

  return (GoUint8)(result == 0);
}

char* Receive() {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  sprintf(buffer, "receive\n");
  Write(buffer);

  memset(buffer, 0, sizeof(buffer));

  size_t bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer, &bytesRead);
  }

  int result;
  sscanf(buffer, "%d", &result);

  if (buffer[0] == '0') {
    return NULL;
  }

  char* c_msg = (char*)malloc(strlen(buffer) + 1);
  strcpy(c_msg, buffer);

  return c_msg;
}

static bool Write(const char* msg) {
  DWORD dwWritten;
  return WriteFile(hWriteStdin, msg, (DWORD)strlen(msg), &dwWritten, NULL);
}

static bool Read(char* buffer) {
  DWORD dwRead;
  return (bool)ReadFile(hReadStdout, buffer, RECV_BUF_SIZE, &dwRead, NULL);
}

#endif