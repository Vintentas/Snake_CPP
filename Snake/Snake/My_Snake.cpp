#include "stdafx.h"
#include "My_Snake.h"
#include "vector"


My_Snake::My_Snake()
{
	pen_color_black.CreatePen(PS_SOLID, 7, RGB(0, 0, 0));
	pen_color_red.CreatePen(PS_SOLID, 7, RGB(255, 0, 0));
	pen_color_blue.CreatePen(PS_SOLID, 7, RGB(0, 0, 255));
	pen_color_green.CreatePen(PS_SOLID, 7, RGB(0, 255, 0));
	pen_color_purple.CreatePen(PS_SOLID, 7, RGB(255, 0, 255));
	pen_color_cyan.CreatePen(PS_SOLID, 7, RGB(0, 255, 255));
	pen_color_yelloy.CreatePen(PS_SOLID, 7, RGB(255, 255, 0));

	My_Pen_Snake = &pen_color_black;						//изначально цвет черный

	My_game = 0;											//игра не начата
	My_speed = 1;											//скорость=1

	Where_Food = 0;											//Изначально еды нет
}


My_Snake::~My_Snake()
{
}


//создаем новую змею для игры, длина змеи = 3;
//выбираем направление движения
void My_Snake::New_snake(CPoint A) 
{
	XY = rand() % 4;		
	std::vector <CPoint> new_coord(3);
	coord = new_coord;
	coord[0] = A;

	if (XY==0)
	{
		CPoint B(0,10);
		A += B; coord[1] = A;
		A += B; coord[2] = A;
	}
	else if (XY==1)
	{
		CPoint B(-10,0);
		A += B; coord[1] = A;
		A += B; coord[2] = A;
	}
	else if (XY==2)
	{
		CPoint B(0,-10);
		A += B; coord[1] = A;
		A += B; coord[2] = A;
	}
	else
	{
		CPoint B(10,0);
		A += B; coord[1] = A;
		A += B; coord[2] = A;
	}							
}


//изменения перемещения
void My_Snake::Go_up()
{
	XY = 0;
}
void My_Snake::Go_riglt()
{
	XY = 1;
}
void My_Snake::Go_bottom()
{
	XY = 2;
}
void My_Snake::Go_left()
{
	XY = 3;
}



//изменение парамитра игры My_game:
//		0 - ничего не происходит
//		1 - запуск игры
//		2 - игра в процессе
//		3 - игра на паузе
//		4 - игра закончена
void My_Snake::Nothing()
{
	My_game = 0;
}
void My_Snake::New_game()
{
	My_game = 1;
}
void My_Snake::Go_game()
{
	My_game = 2;
}
void My_Snake::Game_over()
{
	My_game = 3;
}



//Установка цвета змеи
void My_Snake::color_black()
{
	My_Pen_Snake = &pen_color_black;
}
void My_Snake::color_red()
{
	My_Pen_Snake = &pen_color_red;
}
void My_Snake::color_blue()
{
	My_Pen_Snake = &pen_color_blue;
}
void My_Snake::color_green()
{
	My_Pen_Snake = &pen_color_green;
}
void My_Snake::color_purple()
{
	My_Pen_Snake = &pen_color_purple;
}
void My_Snake::color_cyan()
{
	My_Pen_Snake = &pen_color_cyan;
}
void My_Snake::color_yelloy()
{
	My_Pen_Snake = &pen_color_yelloy;
}

//установка скорости змеи
void My_Snake::set_speed(int A)
{
	My_speed = A;
}


CPoint My_Snake::New_food(CPoint A)
{
	if (Where_Food==0)
	{
		Food = A;		
		Where_Food = 1;
	}
	return A;
}


void My_Snake::Eat_food()
{
		Where_Food = 0;
}

