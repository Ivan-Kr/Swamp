#include <iostream>
#include "./Kiwii/ScreenText.h"
#include <sstream>
#include <conio.h>
#include <vector>

class Obgect {
    _COORD _pos;
    wchar_t _symbol = L'!';

public:
    short X() {
        return _pos.X;
    }
    short Y() {
        return _pos.Y;
    }
    void Pos(short x, short y) {
        _pos.X = x;
        _pos.Y = y;
    }

    void Slide(short x, short y) {
        _pos.X += x;
        _pos.Y += y;
    }

    void Symbol(wchar_t symbol) {
        _symbol=symbol;
    }
    wchar_t Symbol() {
        return _symbol;
    }
};

class Item {
    bool is_laid = 0;


};

class Inventory {

};

int main()
{
    //kiwii::ScreenText ux;

    //ux.SetupS(24, 8);
    Obgect a;
    a.Pos(5,5);
    std::vector<Obgect> coin;
    coin.resize(10);

    for (int i = 0;i < coin.size();i++) {
        coin[i].Pos(rand() % 61, rand() % 16);
        coin[i].Symbol(L'X');
    }

    int coins = 0;

    std::wstring map[16];
    while (true) {
        system("cls");
        a.Symbol(L'@');
        if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W')) {
            if (map[a.Y() - 1][a.X()] == L' ' || map[a.Y() - 1][a.X()] == L'X')
                a.Slide(0, -1);
        }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
            if (map[a.Y()][(a.X() - 1)] == L' ' || map[a.Y()][(a.X() - 1)] == L'X')
                a.Slide(-1, 0);
        }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
            if (map[a.Y() + 1][a.X()] == L' ' || map[a.Y()+1][(a.X())] == L'X')
                a.Slide(0, 1);
        }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
            if (map[a.Y()][(a.X() + 1)] == L' ' || map[a.Y()][(a.X() + 1)] == L'X')
                a.Slide(1, 0);
        }
        if (GetAsyncKeyState(VK_ESCAPE)) {
            system("pause");
        }

        /*if (_kbhit()) {
            switch (_getwch())
            {
            case L'w':
                if(map[a.Y() - 1][a.X()]==L' ')
                    a.Pos(a.X(),(a.Y() - 1));
                break;
            case L'a':
                if (map[a.Y()][(a.X() - 1)] == L' ')
                    a.Pos((a.X() - 1), a.Y());
                break;
            case L's':
                if (map[a.Y() + 1][a.X()] == L' ')
                    a.Pos(a.X(), (a.Y() + 1));
                break;
            case L'd':
                if (map[a.Y()][(a.X() + 1)] == L' ')
                    a.Pos((a.X() + 1), a.Y());
                break;
            default:
                break;
            }
        }

        */

        map[0] = L":::::::#------------#------------#-----------------------#::";
        map[1] = L":::::::|            |            |                       |::";
        map[2] = L":::::::|            |            |                       |::";
        map[3] = L"#------#    #-------#-#  #-#     #---------#-#  #---#  #-#::";
        map[4] = L"|                          |               |        |  |::::";
        map[5] = L"|      #    #--------------#---# #---# #---#        |  |::::";
        map[6] = L"|      |                         |:::| |            |  |::::";
        map[7] = L"#-#  #-#---------#            #--#---# #------------#  #---#";
        map[8] = L"|      |             #-----#                        |      |";
        map[9] = L"|      #---#   #           |                        |      |";
        map[10]= L"|          |   |    #------#-----#----------#  #----#--#   |";
        map[11]= L"#------#   #   |                 |                         |";
        map[12]= L":::::::|       |                 |      #-----------#------#";
        map[13]= L":::::::#-------#------#----#     #      |:::::::::::::::::::";
        map[14]= L"::::::::::::::::::::::|                 |:::::::::::::::::::";
        map[15]= L"::::::::::::::::::::::#-----------------#:::::::::::::::::::";

        for (int i = 0;i < coin.size();i++) 
            if (a.Y() == coin[i].Y() && a.X() == coin[i].X()) {
                do {
                    coin[i].Pos(rand() % 61, rand() % 16);
                    } while (map[coin[i].Y()][coin[i].X()] != L' ');
                coins++;
            };

        for (int i = 0;i < coin.size();i++) while(map[coin[i].Y()][coin[i].X()] != L' ') coin[i].Pos(rand() % 61, rand() % 16);

        

        for (int i = 0;i < coin.size();i++) map[coin[i].Y()][coin[i].X()] = L'X';
        
        map[a.Y()][a.X()] = a.Symbol();

        for (int i = 0;i < 16;i++) std::wcout << map[i]<<'\n';
        std::wcout << "Coins = " << coins;
        //ux.Out();
        Sleep(40);
    }

    return 0;
}
