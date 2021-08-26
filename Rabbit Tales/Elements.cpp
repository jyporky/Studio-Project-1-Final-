#include "Elements.h"

Elements::Elements(void)
{
	ElementalType = rand() % 4 + 1;
	if (ElementalType == 1)
	{
		ElementalName = "Water";
	}
	else if (ElementalType == 2)
	{
		ElementalName = "Fire";
	}
	else if (ElementalType == 3)
	{
		ElementalName = "Earth";
	}
	else if (ElementalType == 4)
	{
		ElementalName = "Air";
	}
}

Elements::Elements(int answerforelements)
{
	ElementalType = answerforelements;
	if (ElementalType == 1)
	{
		ElementalName = "Water";
	}
	else if (ElementalType == 2)
	{
		ElementalName = "Fire";
	}
	else if (ElementalType == 3)
	{
		ElementalName = "Earth";
	}
	else if (ElementalType == 4)
	{
		ElementalName = "Air";
	}
}

Elements::~Elements(void)
{
}

int Elements::getelement()
{
	return ElementalType;
}

string Elements::getelementname()
{
	return ElementalName;
}

void Elements::printoutskill()
{
	if (ElementalType == 1)
	{
		cout << " Water slap\n\n\t\t\t\tYellow liquid\n\n\t\t\t\tMeditate" << endl;
	}
	else if (ElementalType == 2)
	{
		cout << " Volcano\n\n\t\t\t\tFury\n\n\t\t\t\tRevenge" << endl;
	}
	else if (ElementalType == 3)
	{
		cout << " Quake\n\n\t\t\t\tTectonic Smash\n\n\t\t\t\tHardening" << endl;
	}
	else
	{
		cout << " Gale Blade\n\n\t\t\t\tBreeze\n\n\t\t\t\tHurricane" << endl;
	}
}

string Elements::abilitydescription(int abilitynumber)
{
	string description;
	abilitynumber = abilitynumber + ((ElementalType - 1) * 3);
	if (abilitynumber == 1)
	{
		description = " Makes loud sound,\n| what else\n\n| dmg=120% atk\n| -20 mana";
	}
	else if (abilitynumber == 2)
	{
		description = " Up to your\n| imagination\n\n| opp def-10%\n| dmg= 130%atk\n| -40 mana";
	}
	else if (abilitynumber == 3)
	{
		description = " Ohmmmmmmmmmmm\n\n| HP+20%\n| -30 mana";
	}
	else if (abilitynumber == 4)
	{
		description = " Kaboom?\n\n| opp def-50%   def=120%\n| -60 mana";
	}
	else if (abilitynumber == 5)
	{
		description = " REEEEEEEEEEEEEE\n\n| dmg=110% atk\n| -10 mana";
	}
	else if (abilitynumber == 6)
	{
		description = " I'm angy\n\n| def=120%\n| dmg= 120%\n|-30 mana";
	}
	else if (abilitynumber == 7)
	{
		description = " Holy shit\n|the ground is shaking\n\n| dmg=130% atk\n| -20 mana";
	}
	else if (abilitynumber == 8)
	{
		description = " *Confused screaming*\n\n| dmg=150% atk\n| def=110%\n| -60 mana";
	}
	else if (abilitynumber == 9)
	{
		description = " Harden for\n| good defense\n\n| def=130%\n| HP+30%\n| -50 mana";
	}
	else if (abilitynumber == 10)
	{
		description = " Wind blade?\n\n| dmg=120% atk\n| HP+5%\n| -20 mana";
	}
	else if (abilitynumber == 11)
	{
		description = " The calm\n| before the storm\n\n| atk+5%\n| HP+10%\n| -20 mana";
	}
	else if (abilitynumber == 12)
	{
		description = " Blow them away\n\n| dmg=140% atk\n| -30 mana";
	}
	return description;
}

string Elements::abilitydescription2(string name)
{
	string description;
	if (name == "Flamey Sword")
	{
		description = " Mana cost: 70 \n| Dmg 210 %\n| Decreases their defense (5%)";
	}
	else if (name == "Fireboom")
	{
		description = " Place a mine on\n| explodes for Dmg 350%\n| Mana Cost: 100\n";
	}
	else if (name == "Tsunami")
	{
		description = " Peace is never an option\n| Mana Cost: 60\n| Deals 220% Water Damage";
	}
	else if (name == "Flood")
	{
		description = " You are one with water\n| Mana Cost: 20\n| Deals 130% Water Damage to an enemy";
	}
	else if (name == "Storm")
	{
		description = " You will never sleep\n| Mana Cost: 40\n| Deals 170% Air Damage to an enemy,\n| and heal 10% hp";
	}
	else if (name == "Thunderbolt")
	{
		description = " AND THEN IT ALL CAME ZEUS!\n| HE HURLED HIS THUNDERBOLT\n| Mana Cost: 60\n| Deals 200% Air Damage to an enemy";
	}
	else if (name == "Thorns")
	{
		description = " You become cactus\n| Strangle an enemy and deal\n| 140% Earth Damage";
	}
	else if (name == "Full defense")
	{
		description = " When HARDENING is not enough\n| *Insert Lenny Face\n| 90% Immune to\n| damage";
	}
	return description;
}

int Elements::abilitymanacost(int abilitynumber)
{
	int manacost = 20;
	abilitynumber = abilitynumber + ((ElementalType - 1) * 3);
	if (abilitynumber == 1)
	{
		manacost = 20;
	}
	else if (abilitynumber == 2)
	{
		manacost = 40;
	}
	else if (abilitynumber == 3)
	{
		manacost = 30;
	}
	else if (abilitynumber == 4)
	{
		manacost = 60;
	}
	else if (abilitynumber == 5)
	{
		manacost = 10;
	}
	else if (abilitynumber == 6)
	{
		manacost = 20;
	}
	else if (abilitynumber == 7)
	{
		manacost = 20;
	}
	else if (abilitynumber == 8)
	{
		manacost = 60;
	}
	else if (abilitynumber == 9)
	{
		manacost = 50;
	}
	else if (abilitynumber == 10)
	{
		manacost = 20;
	}
	else if (abilitynumber == 11)
	{
		manacost = 20;
	}
	else if (abilitynumber == 12)
	{
		manacost = 30;
	}
	return manacost;
}

void Elements::creationofenemies()
{
}

void Elements::finalboss(int user)
{
}

string Elements::getenemyname()
{
	return " ";
}

void Elements::statisticsforplayer()
{
}

float Elements::gethp()
{
	return 0;
}

float Elements::getatk()
{
	return 0;
}

float Elements::getmana()
{
	return 0;
}

float Elements::getdef()
{
	return 0;
}

void Elements::sethp(float change, float defensive, float adv, int attacker)
{
}

void Elements::recoverhp(float recover, int level)
{
}

void Elements::recovermana(float recover)
{
}

void Elements::setatk(float change)
{
}

void Elements::setmana(float change)
{
}

void Elements::setdef(float change)
{
}

void Elements::restorestats(int change, int level)
{
}

int Elements::xpsystem(string enemy)
{
	return 0;
}

void Elements::level(int xp)
{
}

int Elements::getlevel()
{
	return 0;
}

string Elements::getlooks()
{
	return " ";
}

void Elements::scalestats(int level)
{
}

void Elements::maxhp(int level)
{
}

void Elements::firstenemy()
{
}

int Elements::GetHalfHp()
{
	return 0;
}

int Elements::maxedhp()
{
	return 0;
}

int Elements::maxeddef()
{
	return 0;
}

int Elements::maxedatk()
{
	return 0;
}

int Elements::maxedmana()
{
	return 0;
}

int Elements::getmoney()
{
	return 0;
}

void Elements::addmoney()
{
}
