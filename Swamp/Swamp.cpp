#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <Windows.h>
#include <fstream>

class Memory {
protected:
    std::wstring _name = L"[name]";
public:

    void Name(std::wstring name) {
        _name = name;
    }
    std::wstring Name() {
        return _name;
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
    : public Memory {
    wchar_t** _map;
    int _x;
    int _y;

public:
    Map(int x, int y) {
        _x = int(abs(_x));
        _y = int(abs(_y));
        _map = new wchar_t* [_x];
        for (int i = 0;i < _x;i++) _map[i] = new wchar_t[_y];

        for (int i = 0;i < _x;i++) for (int j = 0;j < _y;j++)  _map[i][j] = L' ';
    }

    int x_() { return _x; }
    int y_() { return _y; }
    
    wchar_t map_(int x, int y) { return (x > 0 && x < _x&& y>0 && y < _y) ? _map[x][y] : wchar_t(); }
    void map_(int x, int y,wchar_t v) {
        if (0 < x && x < _x && 0 < y && y < _y)
            _map[x][y] = v;
    }
    void import_(std::string dir) {
        std::wifstream f(dir);
        std::wstring str;
        int j = 0;
        if (f) {
            getline(f, str);
            for (int i = 0;i < _x && i < str.size();i++) _map[i][j]=str[i];
            j++;
        }
        f.close();
    }
    std::wstring line(int y) {
        if (0 < y && y < _y) {
            std::wstring str;
            str.resize(_x);
            for (int i = 0;i < _x;i++) str[i] = _map[i][y];
            return str;
        }
    }
    ~Map() {
        for (int i = 0;i < _x;i++) delete[] _map[i];
        delete[] _map;
    }

};

int main()
{
    Obgect pawn;
    Map map(16,32);
    map.import_("text.txt");
    pawn.Pos(8,8);
    pawn.Name(L"Obgect");
    map.Name(L"Map");
    std::vector<Obgect> coin;
    coin.resize(10);

    for (int i = 0;i < coin.size();i++) {
        coin[i].Pos(rand() % 61, rand() % 16);
        coin[i].Sym(L'X');
    }

    int coins = 0;
    while (true) {
        _wsystem(L"cls");
        pawn.Sym(L'@');
        if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W')) {
            if (map.map_(pawn.X(),pawn.Y() - 1) == L' ' || map.map_(pawn.X(), pawn.Y() - 1) == L'X')
                pawn.Slide(0, -1);
        }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
            if (map.map_(pawn.X() - 1, pawn.Y()) == L' ' || map.map_(pawn.X() - 1, pawn.Y() ) == L'X')
                pawn.Slide(-1, 0);
        }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
            if (map.map_(pawn.X(), pawn.Y() + 1) == L' ' || map.map_(pawn.X(), pawn.Y() + 1) == L'X')
                pawn.Slide(0, 1);
        }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
            if (map.map_(pawn.X() + 1, pawn.Y()) == L' ' || map.map_(pawn.X() + 1, pawn.Y()) == L'X')
                pawn.Slide(1, 0);
        }
        if (GetAsyncKeyState(VK_ESCAPE)) {
            _wsystem(L"pause");
            break;
        }
        
        map.map_(pawn.X(),pawn.Y(),pawn.Sym());

        for (int i = 0;i < map.y_();i++) std::wcout << map.line(i) <<'\n';
        //ux.Out();
        //Sleep(40);
    }
    


    return 0;
}
