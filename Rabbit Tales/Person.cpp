#include "Person.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

Person::Person()
{
}

Person::~Person()
{
}

void Person::Print(int ColorType)
{
	COORD scrn;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x; scrn.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, scrn);
	cout << R"({\_/})";
	scrn.X = x; scrn.Y = y + 1;
	SetConsoleCursorPosition(hConsoleOutput, scrn);
	cout << R"((•.•))";
	scrn.X = x; scrn.Y = y + 2;
	SetConsoleTextAttribute(hConsoleOutput, ColorType);
	SetConsoleCursorPosition(hConsoleOutput, scrn);
	cout << R"(/^ ^\)";
	SetConsoleTextAttribute(hConsoleOutput, 7);
}

void Person::Movement()
{
	char input = _getch();

	if (input == 'w')
	{
		y = y - 3;

		if ((y < 8) && (x > 35) && (x < 44) && (mmap == 3))
		{
			EnterShop = true;
		}

		if (y < 8)
		{
			y = 8;
		}
	}
	else if (input == 's')
	{
		y = y + 3;

		if (y > 11)
		{
			y = 11;
		}
	}
	else if (input == 'a')
	{
		x = x - 3;

		if (x < 0)
		{
			x = 0;
		}
	}
	else if (input == 'd')
	{
		x = x + 3;

		if ((x > 62) && (GoShop == true))
		{
			Beep(800, 60);
			Beep(500, 100);
			FightingEnemy = true;
			GoShop = false;
		}

		if (x > 77)
		{
			x = 0;
			Beep(500, 60);
			Beep(700, 100);
			if ((FightingEnemy == false) && (AtShop == false))
			{
				mmap = 3;
				AtShop = true;
			}

			else if ((FightingEnemy == false) && (AtShop == true))
			{
				mmap = rand() % 3;
				AtShop = false;
				GoShop = true;
				AddStageClear();
			}
		}
	}
}

int Person::getmmap()
{
	return mmap;
}

bool Person::getEnterShop()
{
	return EnterShop;
}


void Person::SetEnterShop(bool Set)
{
	EnterShop = Set;
}

bool Person::getFightingEnemy()
{
	return FightingEnemy;
}

void Person::SetFightingEnemy(bool Set)
{
	FightingEnemy = Set;
}

int Person::GetStageClear()
{
	return StageClear;
}

void Person::AddStageClear()
{
	StageClear++;
}

void Person::setmap()
{
	mmap = 3;
}