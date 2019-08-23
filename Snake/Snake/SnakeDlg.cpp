
// SnakeDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Snake.h"
#include "SnakeDlg.h"
#include "afxdialogex.h"

#include "snake_info.h"
#include "My_Snake.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:

//	afx_msg void OnDestroy();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)


//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// диалоговое окно CSnakeDlg



CSnakeDlg::CSnakeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SNAKE_DIALOG, pParent)
	, _point(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);				//Замена иконки приложения на свою.
}

void CSnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CSnakeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(my_exet, &CSnakeDlg::OnBnClickedexet)
	ON_BN_CLICKED(my_new_game, &CSnakeDlg::OnBnClickednewgame)
	ON_COMMAND(my_1_1, &CSnakeDlg::OnMy11)
	ON_COMMAND(my_1_2, &CSnakeDlg::OnMy12)
	ON_COMMAND(my_2_2_1, &CSnakeDlg::OnMy221)
	ON_COMMAND(my_2_2_2, &CSnakeDlg::OnMy222)
	ON_COMMAND(my_2_2_3, &CSnakeDlg::OnMy223)
	ON_COMMAND(my_2_2_4, &CSnakeDlg::OnMy224)
	ON_COMMAND(my_2_2_5, &CSnakeDlg::OnMy225)
	ON_COMMAND(my_2_2_6, &CSnakeDlg::OnMy226)
	ON_COMMAND(my_2_2_7, &CSnakeDlg::OnMy227)
	ON_COMMAND(my_2_3_1, &CSnakeDlg::OnMy231)
	ON_COMMAND(my_2_3_2, &CSnakeDlg::OnMy232)
	ON_COMMAND(my_2_3_3, &CSnakeDlg::OnMy233)
	ON_COMMAND(my_3_1, &CSnakeDlg::OnMy31)
	ON_COMMAND(my_3_2, &CSnakeDlg::OnMy32)

	ON_WM_TIMER()
ON_WM_DESTROY()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// обработчики сообщений CSnakeDlg

BOOL CSnakeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();									 //----начальные условия

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// ввTODO: добавьте дополнительную инициализацию
	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	
	//---------------------------Игровое поле------------------------//
	//------------Инициализируем переменную игрового окна------------//
	
	CWnd * uk_my_game_field = GetDlgItem(my_field);
	uk_my_game_field->GetWindowRect(&my_game_field);
	ScreenToClient(&my_game_field);
	my_game_field.DeflateRect(10,10,10,10);
	

	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CSnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSnakeDlg::OnPaint()			//Функция перерисовывания окна
{
	CPaintDC dc(this);	// Получить контекст устройства
	
	////Сетка
	//CPoint A;
	//CPen New_pen(PS_SOLID, 1, RGB(0, 200, 200));
	//dc.SelectObject(New_pen);
	//for (int i = my_game_field.TopLeft().x; i < my_game_field.BottomRight().x; i+=10)
	//{
	//	A.x = i;
	//	A.y = my_game_field.TopLeft().y;
	//	dc.MoveTo(A);
	//	A.y = my_game_field.BottomRight().y;
	//	dc.LineTo(A);
	//}
	//for (int i = my_game_field.TopLeft().y; i < my_game_field.BottomRight().y; i += 10)
	//{
	//	A.y = i;
	//	A.x = my_game_field.TopLeft().x;
	//	dc.MoveTo(A);
	//	A.x = my_game_field.BottomRight().x;
	//	dc.LineTo(A);
	//}

	//CPen New_pen2(PS_SOLID, 1, RGB(200, 0, 200));
	//dc.SelectObject(New_pen2);

	//A = my_game_field.CenterPoint();
	//A.x = my_game_field.TopLeft().x;
	//dc.MoveTo(A);
	//A.x = my_game_field.BottomRight().x;
	//dc.LineTo(A);

	//A = my_game_field.CenterPoint();
	//A.y = my_game_field.TopLeft().y;
	//dc.MoveTo(A);
	//A.y = my_game_field.BottomRight().y;
	//dc.LineTo(A);





	if (*Snake.game == 1)						//Создание новой игры
	{
		dc.SelectObject(Snake.My_Pen_Snake);			//Цвет змеи
		Snake.New_snake(my_game_field.CenterPoint());	//Нарисовать змею по координатам
		for (int i = 0; i < Snake.coord.size(); dc.MoveTo(Snake.coord[i]), dc.LineTo(Snake.coord[i]), i++);
		Snake.Go_game();

	}
	
	else if (*Snake.game == 2)					//перерисовывание в процессе игры
	{
		//Рисуем змею
		dc.SelectObject(Snake.My_Pen_Snake);
		for (int i = 0; i < Snake.coord.size(); dc.MoveTo(Snake.coord[i]), dc.LineTo(Snake.coord[i]), i++);

		//Рисуем еду
		CPen New_pen(PS_SOLID, 7, RGB(0, 0, 0));
		dc.SelectObject(New_pen);
		
		if (*Snake.have_food == 0)			//Проверка наличия еды на поле
		{
			CPoint B = my_game_field.TopLeft();
			int X = rand() % 32;
			int Y = rand() % 40;
			B.x += X * 10;
			B.y += Y * 10;
			dc.MoveTo(Snake.New_food(B));
			dc.LineTo(B);
		}
		else
		{
			dc.MoveTo(Snake.Food);
			dc.LineTo(Snake.Food);
		}
	}
	else if (*Snake.game == 3)					//конец игры
	{
		CString S;
		S.Format("Вы набрали %d очков", _point);

		dc.TextOut(150, 200, "GAME OVER");
		dc.TextOut(125, 230, S);
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSnakeDlg::OnBnClickedexet()				//Кнопка - выход
{
	
	
	int iResults;
	iResults = MessageBox("Вы уверены, что хотите выйти?",
		"Выход?",
		MB_YESNO + MB_ICONQUESTION);

	if (iResults == IDYES)
	{
		OnOK();
	}
}


void CSnakeDlg::OnBnClickednewgame()			//Кнопка - новая игра
{
	_point = 0;
	Snake.New_game();
	Snake.Eat_food();
	set_timer_game();
	Invalidate();

}


void CSnakeDlg::OnMy11()			//Новая игра
	{ OnBnClickednewgame(); }


void CSnakeDlg::OnMy12()			//Выход
	{ OnBnClickedexet(); }


void CSnakeDlg::OnMy221()			//Цвет черный
{ 
	Snake.color_black();
	Invalidate();
}


void CSnakeDlg::OnMy222()			//Цвет синий
	{ 
	Snake.color_blue();
    Invalidate();
    }


void CSnakeDlg::OnMy223()			//Цвет красный
{
	Snake.color_red();
	Invalidate();
}


void CSnakeDlg::OnMy224()			//Цвет зеленый
{
	Snake.color_green();
	Invalidate();
}


void CSnakeDlg::OnMy225()			//Цвет пурпурнвй
{ 
	Snake.color_purple(); 
	Invalidate();
}


void CSnakeDlg::OnMy226()			//Цвет голубой
{
	Snake.color_cyan(); 
	Invalidate();
}


void CSnakeDlg::OnMy227()			//Цвет желтый
{
	Snake.color_yelloy(); 
	Invalidate();
}


void CSnakeDlg::OnMy231()			//Скорость 1
{
	Snake.set_speed(1);
	if (*Snake.game == 2) set_timer_game();
}


void CSnakeDlg::OnMy232()			//Скорость 2
{
	Snake.set_speed(2);
	if (*Snake.game == 2) set_timer_game();
}


void CSnakeDlg::OnMy233()			//Скорость 3
{ 
	Snake.set_speed(3);
	if (*Snake.game == 2) set_timer_game();
}



void CSnakeDlg::OnMy31()			//Информация о игре
	{ S_info.DoModal(); }


void CSnakeDlg::OnMy32()			//Информация о программе	
{	//Создать объект класса CAboutDlg
	CAboutDlg dlg;	
	//Вывести диалоговую панель About
	dlg.DoModal();
}


void CSnakeDlg::Snake_take_food()	//Проверка - съела ли змея еду
{
	CPoint A;

	for (int i = Snake.coord[0].x-5; i < Snake.coord[0].x + 5; i++)
	{
		for (int j = Snake.coord[0].y - 5; j < Snake.coord[0].y + 5; j++)
		{
			A.x = i; A.y = j;
			if (Snake.Food == A)
			{
				Snake.coord.push_back(Snake.coord.back());
				Snake.Eat_food();
				
				switch (*Snake.speed)
				{
				case 1:
					_point += 10;
					break;
				case 2:
					_point += 50;
					break;
				case 3:
					_point += 100;
					break;
				}
								
				break;
			}
		}
	}
}


void CSnakeDlg::Snake_take_snake()	//Проверка - съела ли змея себя - конец игры
{
	CPoint A;
	for (int k = 1; k < Snake.coord.size(); k++)
	{		
		for (int i = Snake.coord[0].x - 5; i < Snake.coord[0].x + 5; i++)
		{
			for (int j = Snake.coord[0].y - 5; j < Snake.coord[0].y + 5; j++)
			{
				A.x = i; A.y = j;
				if (Snake.coord[0] == Snake.coord[k])
				{
					Snake.Game_over();
					KillTimer(1);
					break;
				}
			}
		}
	}
}

void CSnakeDlg::set_timer_game()	//Устанока таймера движения
{

	if (InstallTimer == TRUE)
	{
		KillTimer(1);
	}

	if (*Snake.speed == 1)
	{
		InstallTimer = SetTimer(1, 100, NULL);
	}

	else if (*Snake.speed == 2)
	{ 
		InstallTimer = SetTimer(1, 60, NULL);
	}

	else
	{
		InstallTimer = SetTimer(1, 20, NULL);
	}
}


void CSnakeDlg::OnTimer(UINT_PTR nIDEvent)		
{
	
	switch (*Snake.move)				//передвижение змеи
	{
	case 0:	//движение вверх
		{
		CPoint B(0, -10);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
			{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
			}
		else
			{
			B = my_game_field.BottomRight();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].y = B.y-1;
			}
		break;
		}

	case 1:	//движение вправо
		{
		CPoint B(10, 0);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
		{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
		}
		else
		{
			B = my_game_field.TopLeft();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].x = B.x;
		}
		break;
		}
		
	case 2:	//движение вниз
		{
		CPoint B(0, 10);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
		{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
		}
		else
		{
			B = my_game_field.TopLeft();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].y = B.y;
		}
		break;
		}
		
	case 3:	//движение влево
		{
		CPoint B(-10, 0);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
		{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
		}
		else
		{
			CPoint B = my_game_field.BottomRight();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].x = B.x-1;
		}
		break;
		}
	}
	
	Snake_take_food();		//проверка еды
	Snake_take_snake();		//проверка конца игры

	Invalidate();
	CDialogEx::OnTimer(nIDEvent);
}



void CSnakeDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	KillTimer(1);
	// TODO: добавьте свой код обработчика сообщений
}


BOOL CSnakeDlg::PreTranslateMessage(MSG* pMsg)				//Вместо OnKeyDown - управление змей
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RIGHT:
			if (*Snake.move != 3)
				Snake.Go_riglt();
			break;
		case VK_DOWN:
			if (*Snake.move != 0)
				Snake.Go_bottom();
			break;
		case VK_LEFT:
			if (*Snake.move != 1)
				Snake.Go_left();
			break;
		case VK_UP:
			if (*Snake.move != 2)
				Snake.Go_up();
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

