#include "map.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;
map::map()
{
}

map::~map()
{
}

void setcolor(unsigned short color)
{
    HANDLE tcolor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(tcolor, color);
}

void map::pmap(int mmap)
{
    COORD scrn;
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = 0; scrn.Y = 0;
    SetConsoleCursorPosition(hConsoleOutput, scrn);
    if (mmap == 0)
    {
        setcolor(15); std::cout << "##################################################################################" << std::endl;

        setcolor(6); std::cout << ".................................................................................." << std::endl;

        setcolor(6); std::cout << "..............."; setcolor(10); std::cout << R"(/~~~~~\)"; setcolor(6); std::cout << "....................................."; setcolor(8); std::cout << R"(__/--\)"; setcolor(6); std::cout << "................." << std::endl;

        setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "{       }"; setcolor(6); std::cout << ".................."; setcolor(8); std::cout << R"(/--\)"; setcolor(6); std::cout << ".............";
        setcolor(8); std::cout << R"(/......-----\)"; setcolor(6); std::cout << "..........." << std::endl;

        setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << R"(\_ _ _/)"; setcolor(6); std::cout << "................"; setcolor(8); std::cout << R"(--.....----)"; setcolor(6); std::cout << "....."; setcolor(8); std::cout << R"(----.............---\)"; setcolor(6); std::cout << "......." << std::endl;

        setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "..........| |................."; setcolor(8); std::cout << R"(/...........\___/.....................-\)"; setcolor(6); std::cout << "....." << std::endl;

        setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "| |"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << ".............."; setcolor(8); std::cout << R"(/........................................\)"; setcolor(6); std::cout << "...." << std::endl;

        setcolor(7); std::cout << "**********************************************************************************" << std::endl;

        setcolor(6); std::cout << R"(..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................)" << '\n';

        setcolor(7); std::cout << "**********************************************************************************" << std::endl;

        setcolor(6); std::cout << ".................................................................................." << std::endl;

        setcolor(6); std::cout << "........................"; setcolor(8); std::cout << R"(__/--\)"; setcolor(6); std::cout << "..............................."; setcolor(10); std::cout << R"(/~~~~~\)"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        setcolor(6); std::cout << "......"; setcolor(8); std::cout << R"(/---\)"; setcolor(6); std::cout << "............"; setcolor(8); std::cout << R"(/......-----\)"; setcolor(6); std::cout << "........................"; setcolor(10); std::cout << "{       }"; setcolor(6); std::cout << "......"; setcolor(10); std::cout << "wwwwwww" << std::endl;

        setcolor(6); std::cout << "...."; setcolor(8); std::cout << R"(--.....----)"; setcolor(6); std::cout << "....."; setcolor(8); std::cout << R"(---.............----\)"; setcolor(6); std::cout << "...................."; setcolor(10); std::cout << R"(\_ _ _/)"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        setcolor(6); std::cout << "..."; setcolor(8); std::cout << R"(/...........\___/.....................-\)"; setcolor(6); std::cout << "....................| |........."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        setcolor(6); std::cout << ".."; setcolor(8); std::cout << R"(/........................................\)"; setcolor(6); std::cout << "................."; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "| |"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        setcolor(15); std::cout << "##################################################################################" << std::endl;

        std::cout << " " << std::endl;
    }
    else if (mmap == 1)
    {
        setcolor(15);
        std::cout << "##################################################################################" << std::endl;

        setcolor(6); std::cout << ".................................................................................." << std::endl;

        std::cout << "..........................................................."; setcolor(8); std::cout << R"(__ /---\)"; setcolor(6); std::cout << "..............." << std::endl;

        std::cout << ".............."; setcolor(8); std::cout << R"(/--\)"; setcolor(6); std::cout << "......................."; setcolor(8); std::cout << R"(/--\)"; setcolor(6); std::cout << ".............";
        setcolor(8); std::cout << R"(/........---\)"; setcolor(6); std::cout << "..........." << std::endl;

        std::cout << "..........."; setcolor(8); std::cout << R"(---....---)"; setcolor(6); std::cout << "................."; setcolor(8); std::cout << R"(--.....----.....----.............---\)"; setcolor(6); std::cout << "......." << std::endl;

        std::cout << ".........."; setcolor(8); std::cout << R"(/..........\)"; setcolor(6); std::cout << "..............."; setcolor(8); std::cout << R"(/...........\___/.....................-\)"; setcolor(6); std::cout << "....." << std::endl;

        std::cout << "...................................."; setcolor(8); std::cout << R"(/........................................\)"; setcolor(6); std::cout << "...." << std::endl;

        setcolor(7); std::cout << "**********************************************************************************" << std::endl;

        setcolor(6); std::cout << R"(..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................)" << '\n';

        setcolor(7); std::cout << "**********************************************************************************" << std::endl;

        setcolor(6); std::cout << ".................................................................................." << std::endl;

        setcolor(6); std::cout << "........................"; setcolor(8); std::cout << R"(__/--\)"; setcolor(6); std::cout << "...................................................." << std::endl;

        std::cout << "......"; setcolor(8); std::cout << R"(/---\)"; setcolor(6); std::cout << "............"; setcolor(8); std::cout << R"(/......-----\)"; setcolor(6); std::cout << "..........................";

        setcolor(8); std::cout << R"(/--\)"; setcolor(6); std::cout << "................" << std::endl;

        std::cout << "...."; setcolor(8); std::cout << R"(--.....----)"; setcolor(6); std::cout << "....."; setcolor(8); std::cout << R"(---.............----\)"; setcolor(6); std::cout << "..................";
        setcolor(8); std::cout << R"(---....---)"; setcolor(6); std::cout << "............." << std::endl;

        setcolor(6); std::cout << "..."; setcolor(8); std::cout << R"(/...........\___/.....................-\)"; setcolor(6); std::cout << "..............."; setcolor(8); std::cout << R"(/..........\)"; setcolor(6); std::cout << "............" << std::endl;

        setcolor(6); std::cout << ".."; setcolor(8); std::cout << R"(/........................................\)"; setcolor(6); std::cout << "......................................" << std::endl;

        setcolor(15); std::cout << "##################################################################################" << std::endl;
        std::cout << " " << std::endl;
    }




    else if (mmap == 2)
    {
        setcolor(6);
        setcolor(15);
        std::cout << "##################################################################################" << std::endl;
        setcolor(1);
        std::cout << ".................................................................................." << std::endl;
        //....wwwwwww........wwwwwww........wwwwwww........wwwwwww........wwwwwww...........
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;
        //^^^^
        //....wwwwwww........wwwwwww........wwwwwww........wwwwwww........wwwwwww...........
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;
        //^^^^
        //....wwwwwww........wwwwwww........wwwwwww........wwwwwww........wwwwwww...........
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;
        //^^^^
        setcolor(1);
        std::cout << ".................................................................................." << std::endl;
        setcolor(7);
        std::cout << "**********************************************************************************" << std::endl;
        std::cout << "**********************************************************************************" << std::endl;
        setcolor(6);
        std::cout << R"(..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................)" << '\n';
        setcolor(7);
        std::cout << "**********************************************************************************" << std::endl;
        std::cout << "**********************************************************************************" << std::endl;
        setcolor(1);
        std::cout << ".................................................................................." << std::endl;
        //....wwwwwww........wwwwwww........wwwwwww........wwwwwww........wwwwwww...........
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;
        //^^^^
        //....wwwwwww........wwwwwww........wwwwwww........wwwwwww........wwwwwww...........
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;
        //^^^^
        //....wwwwwww........wwwwwww........wwwwwww........wwwwwww........wwwwwww...........
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........";
        setcolor(10); std::cout << "wwwwwww"; setcolor(1); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;
        //^^^^
        setcolor(1);
        std::cout << ".................................................................................." << std::endl;
        setcolor(15);
        std::cout << "##################################################################################" << std::endl;
        std::cout << " " << std::endl;
    }




    else if (mmap == 3)
    {
        setcolor(15); std::cout << "##################################################################################" << std::endl;

        setcolor(6); std::cout << "..............."; setcolor(10); std::cout << R"(/~~~~~\)"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwwwwwwwwwwwwwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << R"(/~~~~~\)"; setcolor(6); std::cout << "..............." << std::endl;

        setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "{       }"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "wwwwww"; setcolor(7); std::cout << "|--------|"; setcolor(10); std::cout << "wwwwww"; setcolor(6); std::cout << ".......";
        setcolor(10); std::cout << "{       }"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << R"(\_ _ _/)"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwww"; setcolor(7); std::cout << "|--SHOP--|"; setcolor(10); std::cout << "wwwwww"; setcolor(6); std::cout << "........";
        setcolor(10); std::cout << R"(\_ _ _/)"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;

        std::cout << "wwwwwww"; setcolor(6); std::cout << "..........| |.........."; setcolor(10); std::cout << "wwwwww"; setcolor(7); std::cout << "|--------|"; setcolor(10); std::cout << "wwwwww"; setcolor(6); std::cout << "..........| |.........."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "| |"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwww"; setcolor(7); std::cout << "|  ____  |"; setcolor(10); std::cout << "wwwwww";
        setcolor(6); std::cout << "........"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "| |"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;

        setcolor(7); std::cout << "************************************|..|  |..|************************************" << std::endl;
        std::cout << "************************************|__|  |__|************************************" << std::endl;

        setcolor(6); std::cout << R"(..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................
..................................................................................)" << '\n' << std::endl;

        setcolor(7); std::cout << R"(**********************************************************************************)" << std::endl;

        setcolor(6); std::cout << "..............."; setcolor(10); std::cout << R"(/~~~~~\)"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << R"(/~~~~~\)"; setcolor(6); std::cout << "..............." << std::endl;

        setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "{       }"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << ".......";
        setcolor(10); std::cout << "{       }"; setcolor(6); std::cout << "......."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << R"(\_ _ _/)"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........";
        setcolor(10); std::cout << R"(\_ _ _/)"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;

        std::cout << "wwwwwww"; setcolor(6); std::cout << "..........| |.........."; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww";
        setcolor(6); std::cout << "..........| |.........."; setcolor(10); std::cout << "wwwwwww" << std::endl;

        std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "| |"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww";
        setcolor(6); std::cout << "........"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "| |"; setcolor(10); std::cout << "ww"; setcolor(6); std::cout << "........"; setcolor(10); std::cout << "wwwwwww" << std::endl;

        setcolor(15); std::cout << "##################################################################################" << std::endl;
    }
}