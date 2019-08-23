
// Snake.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSnakeApp:
// О реализации данного класса см. Snake.cpp
//

class CSnakeApp : public CWinApp
{
public:
	CSnakeApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSnakeApp theApp;