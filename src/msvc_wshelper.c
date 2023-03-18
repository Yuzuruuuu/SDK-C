#ifdef _MSC_VER

#include "internal/msvc_wshelper.h"

#include <stdio.h>
#include <string.h>
#include <windows.h>

static STARTUPINFO si;
static PROCESS_INFORMATION pi;
static SECURITY_ATTRIBUTES sa;
static HANDLE hStdInRead = NULL;
static HANDLE hStdInWrite = NULL;
static HANDLE hStdOutRead = NULL;
static HANDLE hStdOutWrite = NULL;

static void Read(char* buffer, DWORD* bytesRead) {
  ReadFile(hStdOutRead, buffer, 1048576, (LPDWORD)(&bytesRead), NULL);
}

static void Write(char* buffer) {
  DWORD bytesWritten;
  WriteFile(hStdInWrite, buffer, (DWORD)(strlen(buffer)+1), &bytesWritten, NULL);
}

void Launch() {
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  // Set security attributes for pipe handles
  sa.nLength = sizeof(sa);
  sa.bInheritHandle = TRUE;  // Allow child process to inherit handles
  sa.lpSecurityDescriptor = NULL;

  // Create pipes for stdin and stdout
  CreatePipe(&hStdInRead, &hStdInWrite, &sa,
             0);  // Read handle, write handle, security attributes, buffer size
  CreatePipe(&hStdOutRead, &hStdOutWrite, &sa, 0);

  // Set startup info for child process
  si.dwFlags = STARTF_USESTDHANDLES;  // Use custom handles for stdin and stdout
  si.hStdInput = hStdInRead;          // Set stdin handle
  si.hStdOutput = hStdOutWrite;       // Set stdout handle
  si.hStdError = hStdOutWrite;        // Set stderr handle

  // Create child process
  CreateProcess("wshelper.exe",  // Path to executable
                "",              // Command line arguments
                NULL,            // Process security attributes
                NULL,            // Thread security attributes
                TRUE,            // Inherit handles flag
                0,               // Creation flags
                NULL,            // Environment block
                NULL,            // Current directory
                &si,             // Startup info structure
                &pi);            // Process info structure

  // Close unused pipe handles in parent process
  CloseHandle(hStdInRead);
  CloseHandle(hStdOutWrite);
}

void Terminate() {
  // Close pipe handles in parent process
  CloseHandle(hStdInWrite);
  CloseHandle(hStdOutRead);

  // Close process and thread handles
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
}

GoUint8 Connect(char* c_url) {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  sprintf(buffer, "connect %s\n", c_url);
  Write(buffer);

  memset(buffer, 0, sizeof(buffer));

  DWORD bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer, &bytesRead);
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

  DWORD bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer, &bytesRead);
  }
}

GoUint8 IsConnected() {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  sprintf(buffer, "is_connected\n");
  Write(buffer);

  memset(buffer, 0, sizeof(buffer));

  DWORD bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer, &bytesRead);
  }

  int result;
  sscanf(buffer, "%d", &result);

  return (GoUint8)(result == 1);
}

GoUint8 Send(char* c_msg) {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  sprintf(buffer, "%s\n", c_msg);
  Write(buffer);

  memset(buffer, 0, sizeof(buffer));

  DWORD bytesRead = 0;
  while (bytesRead == 0) {
    Read(buffer, &bytesRead);
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

  DWORD bytesRead = 0;
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

#endif