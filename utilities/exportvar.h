#ifndef EXPORTVAR_H
#define EXPORTVAR_H

#include "link.h"
#include "calc.h"

typedef struct {
	FILE* stream;
	unsigned int pnt;
	unsigned int size;
	unsigned char *data;
	unsigned char *name;
	bool read;
	bool write;
	bool bin;
	int eof;
} MFILE;

MFILE *ExportVar(LPCALC, TCHAR *, symbol83P_t *);
MFILE *ExportApp(LPCALC, TCHAR *, apphdr_t *);
MFILE *ExportRom(TCHAR *lpszFile, LPCALC lpCalc);
MFILE * ExportOS(TCHAR *lpszFile, unsigned char *buffer, int size);
#ifdef _LINUX
MFILE *mopen(const char *filename, const char * mode);
#else
MFILE *mopen(const TCHAR *filename, const TCHAR * mode);
#endif
int mclose(MFILE *);
int meof(MFILE *);
int mgetc(MFILE *);
int mputc(int, MFILE *);
int msize(MFILE *);

TCHAR type_ext[][4] = {
	_T("8xn"),
	_T("8xl"),
	_T("8xm"),
	_T("8xy"),
	_T("8xs"),
	_T("8xp"),
	_T("8xp"),
	_T("8xi"),
	_T("8xd"),
	_T(""),
	_T("8xy"),
	_T("8xy"),
	_T("8xc"),
	_T("8xl"),
	_T(""),
	_T("8xw"),
	_T("8xz"),
	_T("8xt"),
	_T(""),
	_T("8xb"),
	_T("8xk"),
	_T("8xv"),
	_T(""),
	_T("8xg"),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T(""),
	_T("8xy"),
	_T(""),
	_T(""),
	_T("")
};

#endif
