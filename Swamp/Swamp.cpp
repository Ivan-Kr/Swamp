#include <iostream>
#include "./Kiwii/ScreenText.h"
#include <sstream>
#include <vector>

class Memory {
protected:
    std::wstring _name = L"[name]";
    std::wstring Write(std::wstring name, std::wstring what) {
        return L"Have:\t" + name+L" = \""+what+L"\"\n";
    }
    std::wstring Write(std::wstring name, wchar_t what) {
        return L"Have:\t" + name + L" = '" + what + L"'\n";
    }
    template<typename T>
    std::wstring Write(std::wstring name, T what) {
        return L"Have:\t"+name + L" = " + std::to_wstring(what) + L"\n";
    }
public:
    void Name(std::wstring name) {
        _name = name;
    }
    std::wstring Name() {
        return _name;
    }
    
    virtual void Info() {
        std::wcout << "Info:\t\"Memory\" is main class or father of all classes\n";
        std::wcout << "     \t"<<Write(L"_name", _name);
        _wsystem(L"pause");
    }
};

class Obgect
    :public Memory{
protected:

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

    virtual void Info() {
        std::wcout << "Info:\t\"Obgect\" is movement class\n";
        std::wcout << "     \t" << Write(L"_name", _name);
        std::wcout << "     \t" << Write(L"_pos.X", _pos.X);
        std::wcout << "     \t" << Write(L"_pos.Y", _pos.Y);
        std::wcout << "     \t" << Write(L"_symbol", _symbol);
        _wsystem(L"pause");
    }

    void Sym(wchar_t symbol) {
        _symbol=symbol;
    }
    wchar_t Sym() {
        return _symbol;
    }
};

class Item
    : public Obgect {
    bool is_laid = 0;
    int nPlace=1;
public:

};

class Map {
    std::vector<std::vector<wchar_t>> _map;

    int _x;
    int _y;
public:
    Map(int x, int y) {
        _x = x;
        _y = y;

        _map.resize(_y);
        for (int i = 0;i < _y;i++)_map[i].resize(_x);
    }

    void SetLine(int y, std::wstring string) {
        for (int i = 0;i < y;i++) _map[y][i] = string[i];
    }
    void SetLines(std::wstring string) {
        for (int i = 0;i < string.size();i++) _map[i/_x][i%_x] = string[i];
    }
};

int main()
{
    kiwii::ScreenText ux;

    //ux.SetupS(24, 8);
    Obgect a;
    a.Pos(15,15);
    a.Name(L"Obgect");
    std::vector<Obgect> coin;
    coin.resize(10);

    for (int i = 0;i < coin.size();i++) {
        coin[i].Pos(rand() % 61, rand() % 16);
        coin[i].Sym(L'X');
    }

    int coins = 0;

    std::wstring map[32];
    while (true) {
        _wsystem(L"cls");
        a.Sym(L'@');
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
            _wsystem(L"pause");
        }
        if (GetAsyncKeyState(VK_F1)) {
            a.Info();
        }

        map[0]  = L":::::::#------------#------------#-----------------------#::";
        map[1]  = L":::::::#------------#------------#-----------------------#::";
        map[2]  = L":::::::|            |            |                       |::";
        map[3]  = L":::::::|            |            |                       |::";
        map[4]  = L":::::::|            |            |                       |::";
        map[5]  = L":::::::|            |            |                       |::";
        map[6]  = L"#------#    #-------#-#  #-#     #---------#-#  #---#  #-#::";
        map[7]  = L"#------#    #-------#-#  #-#     #---------#-#  #---#  #-#::";
        map[8]  = L"|                          |               |        |  |::::";
        map[9]  = L"|                          |               |        |  |::::";
        map[10] = L"|      #    #--------------#---# #---# #---#        |  |::::";
        map[11] = L"|      #    #--------------#---# #---# #---#        |  |::::";
        map[12] = L"|      |                         |:::| |            |  |::::";
        map[13] = L"|      |                         |:::| |            |  |::::";
        map[14] = L"#-#  #-#---------#            #--#---# #------------#  #---#";
        map[15] = L"#-#  #-#---------#            #--#---# #------------#  #---#";
        map[16] = L"|      |             #-----#                        |      |";
        map[17] = L"|      |             #-----#                        |      |";
        map[18] = L"|      #---#   #           |                        |      |";
        map[19] = L"|      #---#   #           |                        |      |";
        map[20] = L"|          |   |    #------#-----#----------#  #----#--#   |";
        map[21] = L"|          |   |    #------#-----#----------#  #----#--#   |";
        map[22] = L"#------#   #   |                 |                         |";
        map[23] = L"#------#   #   |                 |                         |";
        map[24] = L":::::::|       |                 |      #-----------#------#";
        map[25] = L":::::::|       |                 |      #-----------#------#";
        map[26] = L":::::::#-------#------#----#     #      |:::::::::::::::::::";
        map[27] = L":::::::#-------#------#----#     #      |:::::::::::::::::::";
        map[28] = L"::::::::::::::::::::::|                 |:::::::::::::::::::";
        map[29] = L"::::::::::::::::::::::|                 |:::::::::::::::::::";
        map[30] = L"::::::::::::::::::::::#-----------------#:::::::::::::::::::";
        map[31] = L"::::::::::::::::::::::#-----------------#:::::::::::::::::::";
        
        
        map[a.Y()][a.X()] = a.Sym();

        for (int i = 0;i < 32;i++) std::wcout << map[i] <<'\n';
        //ux.Out();
        Sleep(40);
    }

    return 0;
}
