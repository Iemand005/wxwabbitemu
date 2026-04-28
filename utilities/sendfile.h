#ifndef _SENDFILE_H
#define _SENDFILE_H

extern "C" {

  #include "link.h"

  LINK_ERR SendFile(const LPCALC lpCalc, LPCTSTR lpszFileName, SEND_FLAG Destination);

}

#endif