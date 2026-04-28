#ifndef CORETYPES_H_
#define CORETYPES_H_

#define NumElm(array) (sizeof (array) / sizeof ((array)[0]))

#include <stdint.h>

#ifndef _WINDOWS
#ifndef _LINUX
typedef char TCHAR;
typedef const char *TCHAR *;
#endif
typedef void *LPVOID;
typedef intptr_t INT_PTR;
typedef uint8_t BYTE, *LPBYTE;
typedef uint16_t WORD, *LPWORD;
typedef uint32_t DWORD, *LPDWORD;

#ifndef MAX_PATH
#define MAX_PATH 256
#endif
#endif

typedef unsigned char u_char;
typedef unsigned int u_int;

#ifndef TRUE
#define FALSE (0)
#define TRUE (!FALSE)
#endif

#endif /*CORETYPES_H_*/
