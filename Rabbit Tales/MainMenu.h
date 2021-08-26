#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class MainMenu
{
private:
	bool Quit = false;

public:
	MainMenu();
	~MainMenu();
	void gotoxy(int x, int y, string String, int Color = 7);
	void gotoxys(int x, int y);
	bool getQuit();
	void TheMainMenu();
	void Instruction();
};