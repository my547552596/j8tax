#include <afxwin.h>
#include <comdef.h>
#include <gdiplus.h>
#include <math.h>

#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;

class Atwo: public CFrameWnd {
public:
	Atwo();

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP();
};