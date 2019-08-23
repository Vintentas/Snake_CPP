
// SnakeDlg.h : файл заголовка
//

#include "snake_info.h"
#include "My_Snake.h"

#include "vector"

#pragma once


// диалоговое окно CSnakeDlg
class CSnakeDlg : public CDialogEx
{
// Создание
public:
	CSnakeDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNAKE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	
public:
	afx_msg void OnBnClickedexet();
	afx_msg void OnBnClickednewgame();
	afx_msg void OnMy11();
	afx_msg void OnMy12();
	afx_msg void OnMy221();
	afx_msg void OnMy222();
	afx_msg void OnMy223();
	afx_msg void OnMy224();
	afx_msg void OnMy225();
	afx_msg void OnMy226();
	afx_msg void OnMy227();
	afx_msg void OnMy231();
	afx_msg void OnMy232();
	afx_msg void OnMy233();
	afx_msg void OnMy31();
	afx_msg void OnMy32();

	void set_timer_game();			//ф-ция запуска таймера
	void Snake_take_food();			//Ф-ция проверки - съела ли змея еду
	void Snake_take_snake();			//Ф-ция проверки - съела ли змея себя

	int _point;						//Учет игровых очков
	snake_info S_info;				//Класс окна информации
	CRect my_game_field;			//Переменная игрового поля
	My_Snake Snake;					//Класс для работы со змеей
	int InstallTimer;				//Переменная проверки установки таймера

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
};
