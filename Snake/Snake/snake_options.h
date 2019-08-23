#pragma once


// диалоговое окно snake_options

class snake_options : public CDialogEx
{
	DECLARE_DYNAMIC(snake_options)

public:
	snake_options(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~snake_options();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = MY_OPTIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
