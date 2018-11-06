#include "../bo/xSeal_cpp.h"

#define IDR_MAINFRAME 128

class appin : public CWinApp {
public:
	virtual BOOL ExitInstance();
	virtual BOOL InitInstance();

protected:
	GdiplusStartupInput m_gdiplusInput;
	ULONG_PTR m_gdiplusToken;
};

class j8tax : public CFrameWnd {
public:
	j8tax();
	~j8tax();

protected:
	afx_msg void guanlian();
	afx_msg void jisuan();
	DECLARE_MESSAGE_MAP();

private:
	CStatic *gerensuodeshui1;
	CEdit *gerensuodeshui2;
	CStatic *gongzijishu1;
	CEdit *gongzijishu2;
	CStatic *shiyebaoxian1;
	CEdit *shiyebaoxian2;
	CStatic *shuihouyingde1;
	CEdit *shuihouyingde2;
	CStatic *shuiqianshouru1;
	CEdit *shuiqianshouru2;
	CStatic *yanglaobaoxian1;
	CEdit *yanglaobaoxian2;
	CStatic *yiliaobaoxian1;
	CEdit *yiliaobaoxian2;
	CStatic *zhufanggongjijin1;
	CEdit *zhufanggongjijin2;

	int chuizhijianju, shuipingjianju;
	void buju(CStatic *cs, CString str1, CEdit *ce, CString str2, BOOL b, int i);
};