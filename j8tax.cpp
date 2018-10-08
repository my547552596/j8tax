#include "j8tax.h"

BOOL appin::InitInstance() {
	GdiplusStartup(&m_gdiplusToken, &m_gdiplusInput, NULL);

	m_pMainWnd = new j8tax();
	m_pMainWnd->UpdateWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);

	return true;
}

BOOL appin::ExitInstance() {
	delete m_pMainWnd;

	m_pMainWnd = new Atwo();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	Sleep(2000);

	delete m_pMainWnd;
	m_pMainWnd = NULL;

	GdiplusShutdown(m_gdiplusToken);

	return false;
}

BEGIN_MESSAGE_MAP(j8tax, CFrameWnd)
	ON_EN_CHANGE(1427, guanlian)
	ON_EN_CHANGE(1428, jisuan)
END_MESSAGE_MAP()

j8tax::j8tax() {
	Create(
		NULL,
		_T("工薪税费计算器（北京） v2.0"),
		WS_CAPTION | WS_SYSMENU,
		CRect(0, 0, 420, 180)
	);
	CenterWindow();

	HICON m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	CRect junei;
	GetClientRect(&junei);
	chuizhijianju = (junei.bottom - 80) / 5;
	shuipingjianju = (junei.right - 360) / 3;

	buju(gerensuodeshui1 = new CStatic(), "个人所得税", gerensuodeshui2 = new CEdit(), "0.00", true, 7);
	buju(shuihouyingde1 = new CStatic(), "税后应得", shuihouyingde2 = new CEdit(), "0.00", true, 6);
	buju(shiyebaoxian1 = new CStatic(), "失业保险", shiyebaoxian2 = new CEdit(), "0.00", true, 5);
	buju(yanglaobaoxian1 = new CStatic(), "养老保险", yanglaobaoxian2 = new CEdit(), "0.00", true, 4);
	buju(zhufanggongjijin1 = new CStatic(), "住房公积金", zhufanggongjijin2 = new CEdit(), "0.00", true, 3);
	buju(yiliaobaoxian1 = new CStatic(), "医疗保险", yiliaobaoxian2 = new CEdit(), "0.00", true, 2);
	buju(gongzijishu1 = new CStatic(), "工资基数", gongzijishu2 = new CEdit(), "0", false, 1);
	buju(shuiqianshouru1 = new CStatic(), "税前收入", shuiqianshouru2 = new CEdit(), "0", false, 0);
}

void j8tax::guanlian() {
	CString str = "0";
	shuiqianshouru2->GetWindowText(str);
	gongzijishu2->SetWindowText(str);
}

void j8tax::jisuan() {
	CString str = "0";
	gongzijishu2->GetWindowText(str);
	double d1 = atof(str), d2, d3;

	if(d1 > 0) {
		str.Format(_T("%.2lf"), d1 * 0.002);
		shiyebaoxian2->SetWindowText(str);

		str.Format(_T("%.2lf"), d1 * 0.08);
		yanglaobaoxian2->SetWindowText(str);

		str.Format(_T("%.2lf"), d1 * 0.02 + 3);
		yiliaobaoxian2->SetWindowText(str);

		str.Format(_T("%.2lf"), d1 * 0.12);
		zhufanggongjijin2->SetWindowText(str);

		d2 = - 3 - d1 * 0.222;
	} else {
		shiyebaoxian2->SetWindowText("0.00");
		yanglaobaoxian2->SetWindowText("0.00");
		yiliaobaoxian2->SetWindowText("0.00");
		zhufanggongjijin2->SetWindowText("0.00");
	}

	try {
		shuiqianshouru2->GetWindowText(str);
	}
	catch(...) {
		str = ":(";
	}

	d2 += atof(str) - 5000;

	if(d2 > 0 && d2 <= 3000) {
		d3 = d2 * 0.03;
	} else if(d2 > 3000 && d2 <= 12000) {
		d3 = d2 * 0.1 - 210;
	} else if(d2 > 12000 && d2 <= 25000) {
		d3 = d2 * 0.2 - 1410;
	} else if(d2 > 25000 && d2 <= 35000) {
		d3 = d2 * 0.25 - 2660;
	} else if(d2 > 35000 && d2 <= 55000) {
		d3 = d2 * 0.3 - 4410;
	} else if(d2 > 55000 && d2 <= 80000) {
		d3 = d2 * 0.35 - 7160;
	} else if(d2 > 80000) {
		d3 = d2 * 0.45 - 15160;
	} else {
		d3 = 0;
	}

	str.Format(_T("%.2lf"), d2 + 5000 - d3);
	shuihouyingde2->SetWindowText(str);

	str.Format(_T("%.2lf"), d3);
	gerensuodeshui2->SetWindowText(str);
}

void j8tax::buju(CStatic *cs, CString str1, CEdit *ce, CString str2, BOOL b, int i) {
	int hang = i / 2 + 1, lie = i % 2 + 1;

	cs->Create(
		str1 + "：",
		WS_CHILD | WS_VISIBLE | SS_CENTER,
		CRect(
			(shuipingjianju + 180) * lie - 180,
			(chuizhijianju + 20) * hang - 20,
			(shuipingjianju + 180) * lie - 90,
			(chuizhijianju + 20) * hang
		),
		this
	);

	ce->Create(
		WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER,
		CRect(
			(shuipingjianju + 180) * lie - 90,
			(chuizhijianju + 20) * hang - 20,
			(shuipingjianju + 180) * lie,
			(chuizhijianju + 20) * hang
		),
		this,
		1427 + i
	);
	ce->SetReadOnly(b);
	ce->SetWindowText(str2);
}

j8tax::~j8tax() {
	delete gerensuodeshui1;
	delete gerensuodeshui2;
	delete gongzijishu1;
	delete gongzijishu2;
	delete shiyebaoxian1;
	delete shiyebaoxian2;
	delete shuihouyingde1;
	delete shuihouyingde2;
	delete shuiqianshouru1;
	delete shuiqianshouru2;
	delete yanglaobaoxian1;
	delete yanglaobaoxian2;
	delete yiliaobaoxian1;
	delete yiliaobaoxian2;
	delete zhufanggongjijin1;
	delete zhufanggongjijin2;
}

appin jobar_20080911142702;