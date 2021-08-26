#pragma once
#include "Elements.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
class Stats : public Elements
{
protected:
	int health = 100;
	int atk = 100;
	int mana = 100;
	int def = 100;
	int yourlevel = 1;
	int totalxp = 0;
	int money = 4;
	string entityname;
	string entitylooks;
public:
	Stats();
	Stats(int answerfromuser);
	~Stats();
	void creationofenemies();
	void finalboss(int user);
	string getenemyname();
	void statisticsforplayer();
	float gethp();
	float getatk();
	float getmana();
	float getdef();
	void sethp(float change, float defensive, float adv, int attacker);
	void recoverhp(float recover, int level);
	void recovermana(float recover);
	void setatk(float change);
	void setmana(float change);
	void setdef(float change);
	void restorestats(int change, int level);
	int xpsystem(string enemy);
	void level(int xp);
	int getlevel();
	string getlooks();
	void scalestats(int level);
	void maxhp(int level);
	void firstenemy();
	int GetHalfHp();
	int maxedhp();
	int maxeddef();
	int maxedatk();
	int maxedmana();
	int getmoney();
	void addmoney();
};