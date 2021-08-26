#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;
class Elements
{
public:
	int ElementalType;
	string ElementalName;
public:
	Elements(void);
	Elements(int answerforelements);
	~Elements(void);
	int getelement();
	string getelementname();
	void printoutskill();
	string abilitydescription(int abilitynumber);
	string abilitydescription2(string name);
	int abilitymanacost(int abilitynumber);
	virtual void creationofenemies();
	virtual void finalboss(int user);
	virtual string getenemyname();
	virtual void statisticsforplayer();
	virtual float gethp();
	virtual float getatk();
	virtual float getmana();
	virtual float getdef();
	virtual void sethp(float change, float defensive, float adv, int attacker);
	virtual void recoverhp(float recover, int level);
	virtual void recovermana(float recover);
	virtual void setatk(float change);
	virtual void setmana(float change);
	virtual void setdef(float change);
	virtual void restorestats(int change, int level);
	virtual int xpsystem(string enemy);
	virtual void level(int xp);
	virtual int getlevel();
	virtual string getlooks();
	virtual void scalestats(int level);
	virtual void maxhp(int level);
	virtual void firstenemy();
	virtual int GetHalfHp();
	virtual int maxedhp();
	virtual int maxeddef();
	virtual int maxedatk();
	virtual int maxedmana();
	virtual int getmoney();
	virtual void addmoney();
};