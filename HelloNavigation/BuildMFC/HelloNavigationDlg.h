
// HelloNavigationDlg.h : header file
//

#pragma once
extern "C" void startHelloNavigation(void* phy_fb, int width, int height, int color_bytes, struct EXTERNAL_GFX_OP* gfx_op);
extern "C" void sendTouch2HelloNavigation(int x, int y, bool is_down);
extern "C" void sendKey2HelloNavigation(unsigned int key);

typedef struct
{
	unsigned int dwMsgId;
	unsigned int dwParam1;
	unsigned int dwParam2;
}OUTMSGINFO;

typedef struct tagMYBITMAPINFO {
	BITMAPINFOHEADER    bmiHeader;
	DWORD				biRedMask;
	DWORD				biGreenMask;
	DWORD				biBlueMask;
} MYBITMAPINFO;

// CHelloNavigationDlg dialog
class CHelloNavigationDlg : public CDialogEx
{
// Construction
public:
	CHelloNavigationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HelloNavigation_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()

private:
	static void draw_pixel(int x, int y, unsigned int rgb);
	static void fill_rect(int x0, int y0, int x1, int y1, unsigned int rgb);
	static UINT ThreadHelloNavigation(LPVOID pParam);
	static CHelloNavigationDlg* m_the_dialog;
	static CRITICAL_SECTION m_criSection;
};
