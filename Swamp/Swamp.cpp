#include <iostream>
#include "./Kiwii/ScreenText.h"
#include "./Kiwii/Time Act.h"
#include <sstream>
#include <vector>
#include <array>

class Memory {
protected:
    int pointer;

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
        std::wcout << "     \t" << Write(L"&Memory", (long long)&pointer);
        std::wcout << "     \t"<<Write(L"_name", _name);
    }
};

class Obgect
    :public Memory {
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
        std::wcout << "     \t" << Write(L"&Memory", (long long)&pointer);
        std::wcout << "     \t" << Write(L"_name", _name);
        std::wcout << "     \t" << Write(L"_pos.X", _pos.X);
        std::wcout << "     \t" << Write(L"_pos.Y", _pos.Y);
        std::wcout << "     \t" << Write(L"_symbol", _symbol);
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

class Map
    :public Memory {
protected:
    //std::array<wchar_t,8>_map;

    std::vector<std::vector<wchar_t>>_map;

    int _x;
    int _y;
public:
    Map(int x, int y) {
        _x = x;
        _y = y;

        _map.resize(_y);
        for (int i = 0;i < _y;i++)_map[i].resize(_x);
    }

    wchar_t GetSym(int x, int y) {
        if (0 <= y && y < _y && 0 <= x && x < _x) return _map[y][x];
        else return L'\0';
    }
    std::wstring GetLine(int y) {
        std::wstring line = L"";

        for (int i = 0;i < _map[y].size();i++) line += _map[y][i];

        return line;
    }

    int X() {
        return _x;
    }
    int Y() {
        return _y;
    }

    void SetClassObgect(Obgect clas) {
        if (0 <= clas.Y() && clas.Y() < _y && 0 <= clas.X() && clas.X() < _x)
            _map[clas.Y()][clas.X()]=clas.Sym();
    }
    void SetLine(int y, std::wstring string) {
        for (int i = 0;i < _map[y].size();i++) _map[y][i] = string[i];
    }
    void SetSym(int x, int y,wchar_t ch) {
        if (0 <= y && y < _y && 0 <= x && x < _x) _map[y][x]=ch;
    }

    virtual void Info() {
        std::wcout << "Info:\t\"Map\" is class location\n";
        std::wcout << "     \t" << Write(L"&Memory", (long long)&pointer);
        std::wcout << "     \t" << Write(L"_name", _name);
        std::wcout << "     \t" << Write(L"_x", _x);
        std::wcout << "     \t" << Write(L"_y", _y);
        std::wcout << "     \t" << Write(L"_map", (long long)&_map);
    }
};

int main()
{
    kiwii::ScreenText ux;

    Obgect pawn;
    Map map_(32,16);

    //ux.SetupS(24, 8);

    pawn.Pos(15,14);
    pawn.Name(L"Obgect");
    map_.Name(L"Map");
    std::vector<Obgect> coin;
    coin.resize(10);

    for (int i = 0;i < coin.size();i++) {
        coin[i].Pos(rand() % 61, rand() % 16);
        coin[i].Sym(L'X');
    }

    int coins = 0;
    //0xFFFFFFFFFFFFFFFF
    //std::wstring map[32];
    while (true) {
        _wsystem(L"cls");
        pawn.Sym(L'@');
        if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W')) {
            if (map_.GetSym(pawn.X(),pawn.Y() - 1) == L' ' || map_.GetSym(pawn.X(), pawn.Y() - 1) == L'X')
                pawn.Slide(0, -1);
        }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
            if (map_.GetSym(pawn.X() - 1, pawn.Y()) == L' ' || map_.GetSym(pawn.X() - 1, pawn.Y() ) == L'X')
                pawn.Slide(-1, 0);
        }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
            if (map_.GetSym(pawn.X(), pawn.Y() + 1) == L' ' || map_.GetSym(pawn.X(), pawn.Y() + 1) == L'X')
                pawn.Slide(0, 1);
        }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
            if (map_.GetSym(pawn.X() + 1, pawn.Y()) == L' ' || map_.GetSym(pawn.X() + 1, pawn.Y()) == L'X')
                pawn.Slide(1, 0);
        }
        if (GetAsyncKeyState(VK_ESCAPE)) {
            _wsystem(L"pause");
        }
        if (GetAsyncKeyState(VK_F1)) {
            pawn.Info();
            map_.Info();
            _wsystem(L"pause");
        }
        map_.SetLine(0x00, L"#------#-----#----------#------#");
        map_.SetLine(0x01, L"|      |     |          |      |");
        map_.SetLine(0x02, L"|      |     |          |      |");
        map_.SetLine(0x03, L"|      #     |          #--# #-#");
        map_.SetLine(0x04, L"|            |          |      |");
        map_.SetLine(0x05, L"|      #     |          |      |");
        map_.SetLine(0x06, L"|      |     |          |      |");
        map_.SetLine(0x07, L"#------# #---#-#  #-#   #--# #-#");
        map_.SetLine(0x08, L"|                   |          |");
        map_.SetLine(0x09, L"|                   |          |");
        map_.SetLine(0x0a, L"|                   |          |");
        map_.SetLine(0x0b, L"|      # #----------#-# #--# #-#");
        map_.SetLine(0x0c, L"|      |                |      |");
        map_.SetLine(0x0d, L"|      |                |      |");
        map_.SetLine(0x0e, L"|      |                |      |");
        map_.SetLine(0x0f, L"#------#----------------#------#");
        
        map_.SetClassObgect(pawn);

        for (int i = 0;i < map_.Y();i++) std::wcout << map_.GetLine(i) <<'\n';
        //ux.Out();
        //Sleep(40);
    }
    


    return 0;
}
