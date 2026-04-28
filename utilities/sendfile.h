#ifndef _SENDFILE_H
#define _SENDFILE_H

#include "link.h"

#ifdef __cplusplus
extern "C" {
#endif

LINK_ERR SendFile(const LPCALC lpCalc, LPCTSTR lpszFileName, SEND_FLAG Destination);

#ifdef __cplusplus
}
#endif

#endif