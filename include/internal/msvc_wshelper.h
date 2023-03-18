#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Only for MSVC
#ifndef _MSC_VER
#error This file is only for MSVC
#endif

typedef unsigned char GoUint8;  // To match Go's uint8 type

void Launch();

GoUint8 Connect(char* c_url);

void Disconnect();

GoUint8 IsConnected();

GoUint8 Send(char* c_msg);

char* Receive();

#ifdef __cplusplus
}
#endif