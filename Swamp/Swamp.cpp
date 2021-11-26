#include <iostream>
#include "./Kiwii/ScreenText.h"
#include <sstream>
#include <conio.h>

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

    wchar_t Symbol() {
        return _symbol;
    }
};

int main()
{
    //kiwii::ScreenText ux;

    //ux.SetupS(24, 8);
    Obgect a;
    a.Pos(3,3);
    std::wstring map[8] =
    {
        L"#---------------------#",
        L"|                     |",
        L"|                     |",
        L"|                     |",
        L"|                     |",
        L"|                     |",
        L"|                     |",
        L"#---------------------#",
    };
    while (true) {
        system("cls");

        if (GetAsyncKeyState(VK_UP)) {
            if (map[a.Y() - 1][a.X()] == L' ')
                a.Pos(a.X(), (a.Y() - 1));
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            if (map[a.Y()][(a.X() - 1)] == L' ')
                a.Pos((a.X() - 1), a.Y());
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            if (map[a.Y() + 1][a.X()] == L' ')
                a.Pos(a.X(), (a.Y() + 1));
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            if (map[a.Y()][(a.X() + 1)] == L' ')
                a.Pos((a.X() + 1), a.Y());
        }
        if (GetAsyncKeyState(VK_SHIFT)) {
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

        map[0] = L"#---------------------#";
        map[1] = L"|                     |";
        map[2] = L"|                     |";
        map[3] = L"|                     |";
        map[4] = L"|                     |";
        map[5] = L"|                     |";
        map[6] = L"|                     |";
        map[7] = L"#---------------------#";

        map[a.Y()][a.X()] = a.Symbol();


        for (int i = 0;i < 8;i++) {


            std::wcout << map[i]<<'\n';
        }
        //ux.Out();
    }

    return 0;
}
