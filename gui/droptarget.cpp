#include "droptarget.h"
#include "sendfile.h"
#include "gui.h"

bool DnDFile::OnDropFiles(wxCoord, wxCoord, const wxArrayString& filenames)
{
    size_t nFiles = filenames.GetCount();
    for (int i = 0; i < nFiles; i++ ) {
		// SendFile(lpCalc, filenames[i].fn_str(), SEND_CUR); TODO: Fix
	}

    return true;
}
