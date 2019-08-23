#pragma once


// диалоговое окно snake_info

class snake_info : public CDialogEx
{
	DECLARE_DYNAMIC(snake_info)

public:
	snake_info(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~snake_info();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = MY_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedBitmap2();
};
