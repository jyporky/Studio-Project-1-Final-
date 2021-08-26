#pragma once
#include <string>


class Shop
{
private:
	int CarrotAmount;
	std::string Inventory;
	int ItemAmt[9];
	std::string TheItemNames[9];
	std::string ElementType;
	std::string fourthskill = " ";
	std::string cosmetics = "";
	int money = 0;
	// Setting up arrays, ignore dis
	int ShopItems[5] = { 0,0,0,0,0 };
	int ItemPrice[5] = { 0,0,0,0,0 };
public:
	Shop();
	~Shop();
	void TheShop(bool& SkillsBought, std::string ElementalType, int& CarrotAmt, std::string& Inv, int ItemAmt[9],
		std::string ItemName[9], bool EnterShopYet);

	void PrintHead1();
	void PrintHead2();
	void Printhead3();
	void PrintHead4();
	void Printhead5();
	void Printhead6();
	void Printhead7(int time);
	void Printhead8(int time);


	void gotoxy(int x, int y, std::string String, int ColorType = 7);
	void gotoxy(int x, int y);
	void MoveHead(int& i);
	void PrintBottom();
	void PrintHead();
	std::string PrintInventory(std::string TheInventory);
	std::string getfourthskill();
	int getequipmenttype();
	void addmoney();
};