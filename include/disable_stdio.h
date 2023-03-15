/// @file disable_stdio.h
/// @brief Disables stdio functions

#pragma once

#ifdef NO_STDIO

#undef stdin
#undef stdout
#undef stderr

#define getchar(...) NULL
#define gets(...) NULL
#define gets_s(...) NULL
#define putchar(...) NULL
#define puts(...) NULL

#define getwchar(...) NULL
#define putwchar(...) NULL

#define scanf(...) NULL
#define scanf_s(...) NULL
#define vscanf(...) NULL
#define vscanf_s(...) NULL
#define printf(...) NULL
#define printf_s(...) NULL
#define vprintf(...) NULL
#define vprintf_s(...) NULL

#define wscanf(...) NULL
#define wscanf_s(...) NULL
#define vwscanf(...) NULL
#define vwscanf_s(...) NULL
#define wprintf(...) NULL
#define wprintf_s(...) NULL
#define vwprintf(...) NULL
#define vwprintf_s(...) NULL

#endif