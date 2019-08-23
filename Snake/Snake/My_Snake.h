#pragma once
#include "vector"


class My_Snake
{
	int XY;								//направление перемещения: 0-вверх, 1-вправо, 2-вниз, 3-влево															
	int My_speed;							//скорость змейки, 1 - 3, 0 - игра на паузе
	int My_game;							//если	0 - ничего не происходит
										//		1 - запуск игры
										//		2 - игра в процессе
										//		3 - игра закончена
	
	CPen pen_color_black;				// перо рисования
	CPen pen_color_red;
	CPen pen_color_blue;
	CPen pen_color_green;
	CPen pen_color_purple;
	CPen pen_color_cyan;
	CPen pen_color_yelloy;

	int Where_Food;						//Проверка: 1 - еда на поле, 0 - еды нет на поле

public:
	CPen *My_Pen_Snake;
	CPoint Food;					//Координаты еды
	std::vector <CPoint> coord;		//вектор, хранящие точки частей тела змейки, размер вектора определяет длину змейки
	const int *const move = &XY;	//константные указатели на переменные
	const int *const speed = &My_speed;
	const int *const game = &My_game;
	const int *const have_food = &Where_Food;

	My_Snake();
	~My_Snake();
	
	void New_snake(CPoint);			//ф-ция новой змейки
	void Nothing();					//ничего не происходит
	void New_game();				//запускает новую игру
	void Go_game();					//игра в процессе
	void Game_over();				//конец игры

	void Go_riglt();				//изменение перемещения
	void Go_left();
	void Go_up();
	void Go_bottom();

	void color_black();				//установка цвета змеи
	void color_red();
	void color_blue();
	void color_green();
	void color_purple();
	void color_cyan();
	void color_yelloy();

	void set_speed(int);			//установка скорости змеи

	CPoint New_food(CPoint);		//Еда на поле
	void Eat_food();				//Еда съедина


};




