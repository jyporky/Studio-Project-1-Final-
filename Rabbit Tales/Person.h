#pragma once
#include <cstdlib>
#include <Windows.h>
#include <iostream>

using namespace std;

class Person
{
private:
	int x = 0;
	int y = 9;
	int moveto = 0;
	int mmap = 0;
	bool EnterShop = false;
	bool FightingEnemy = false;
	bool AtShop = false;
	bool GoShop = true;
	int StageClear = 0;

public:
	Person();
	~Person();
	void Print(int ColorType);
	void Movement();
	int getmmap();
	bool getEnterShop();
	void SetEnterShop(bool Set);
	bool getFightingEnemy();
	void SetFightingEnemy(bool Set);
	int GetStageClear();
	void AddStageClear();
	void setmap();
};