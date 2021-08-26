#include "MainMenu.h"


MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::gotoxy(int x, int y, string String, int color)
{
	COORD screen;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	screen.X = x; screen.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, screen);
	SetConsoleTextAttribute(hConsoleOutput, color);
	std::cout << String;
	SetConsoleTextAttribute(hConsoleOutput, 7);
}

void MainMenu::gotoxys(int x, int y)
{
	COORD screen;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	screen.X = x; screen.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, screen);
}

bool MainMenu::getQuit()
{
	return Quit;
}


void MainMenu::Instruction()
{
	string Temp;
	gotoxys(20, 2);
	cout << "HOW TO PLAY" << endl;
	cout << "	---------------------------------------  ";
	gotoxy(14, 6, "W key: Move/Navigate Up");
	gotoxy(14, 8, "S Key: Move/Navigate Down");
	gotoxy(14, 10, "A Key: Move/Navigate Left");
	gotoxy(14, 12, "D Key: Move/Navigate Right");
	gotoxy(14, 16, "Press Any Keys to continue.");
	cout << "                                         " << endl;
	cout << "	---------------------------------------  ";
	cout << R"(       

                                                                                                                   
                    (\____/)            
                    ( O . O)           _\/_ 
                    /     /    !!!     \  /
                   o(_____)             \/)";
	Temp = _getch();
}



void MainMenu::TheMainMenu()
{
	bool InMainMenu = true;
	string Imput;
	int CurrentArrow = 1;
	while (InMainMenu == true)
	{
		gotoxy(0, 2, R"(______      _     _     _ _)", 15);    gotoxy(32, 2, R"(_____     _)", 10);
		gotoxy(0, 3, R"(| ___ \    | |   | |   (_) |)", 15);   gotoxy(31, 3, R"(|_   _|   | |(\_/))", 10);
		gotoxy(0, 4, R"(| |_/ /__ _| |__ | |__  _| |_)", 15);  gotoxy(33, 4, R"(| | __ _| |(o.o)  ___)", 10);
		gotoxy(0, 5, R"(|    // _` | '_ \| '_ \| | __|)", 15); gotoxy(33, 5, R"(| |/ _` | |/ _ \/ __|)", 10);
		gotoxy(0, 6, R"(| |\ \ (_| | |_) | |_) | | |)", 15);   gotoxy(33, 6, R"(| | (_| | |  __/\__ \)", 10);
		gotoxy(0, 7, R"(\_| \_\__,_|_.__/|_.__/|_|\__|)", 15); gotoxy(33, 7, R"(\_/\__,_|_|\___||___/)", 10);


		/*
______      _     _     _ _     _____     _
| ___ \    | |   | |   (_) |   |_   _|   | |(\_/)
| |_/ /__ _| |__ | |__  _| |_    | | __ _| |(o.o)  ___
|    // _` | '_ \| '_ \| | __|   | |/ _` | |/ _ \/ __|
| |\ \ (_| | |_) | |_) | | |_    | | (_| | |  __/\__ \
\_| \_\__,_|_.__/|_.__/|_|\__|   \_/\__,_|_|\___||___/
		*/


		gotoxy(23, 10, "PLAY", 7);
		gotoxy(20, 12, "HOW TO PLAY", 7);
		gotoxy(23, 14, "EXIT", 7);

		gotoxys(0, 11);
		cout << R"(	
      {\_/}
      (•.•)
      /^ ^\)";


		gotoxys(40, 12);
		cout << R"({\_/})";
		gotoxys(40, 13);
		cout << "(•.•)";
		gotoxys(40, 14);
		cout << R"(/^ ^\)";


		bool Selecting = true;
		bool HowToPlay = false;
		while (Selecting == true)
		{
			if (CurrentArrow == 1)
			{
				gotoxy(19, 12, " ", 7);
				gotoxy(22, 10, ">", 7);
				gotoxy(22, 14, " ", 7);
			}
			else if (CurrentArrow == 2)
			{
				gotoxy(22, 10, " ", 7);
				gotoxy(22, 14, " ", 7);
				gotoxy(19, 12, ">", 7);
			}
			else if (CurrentArrow == 3)
			{
				gotoxy(19, 12, " ", 7);
				gotoxy(22, 10, " ", 7);
				gotoxy(22, 14, ">", 7);
			}

			Imput = _getch();


			if (Imput == "w")
			{
				CurrentArrow--;
				if (CurrentArrow == 0)
				{
					CurrentArrow = 3;
				}
			}
			else if (Imput == "s")
			{
				CurrentArrow++;
				if (CurrentArrow == 4)
				{
					CurrentArrow = 1;
				}
			}
			else if (Imput == "\r")
			{
				if (CurrentArrow - 1 == 0)
				{
					Selecting = false;
					InMainMenu = false;
				}

				else if (CurrentArrow - 1 == 1)
				{
					Selecting = false;
					HowToPlay = true;
				}

				else if (CurrentArrow - 1 == 2)
				{
					Selecting = false;
					InMainMenu = false;
					Quit = true;

				}
			}


			for (int i = 10; i < 15; i++)
			{
				gotoxy(18, i, " ");
			}
		}

		for (int i = 0; i < 30; i++)
		{
			gotoxy(0, i, "                                                         ");
		}

		if (HowToPlay == true)
		{
			Instruction();
		}

		for (int i = 0; i < 30; i++)
		{
			gotoxy(0, i, "                                                         ");
		}

	}

	system("CLS");
}