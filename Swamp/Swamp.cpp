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

class KeyManager
    : public Memory {
public:
    static enum Key : unsigned short {
        Lbutton = 0x01,
        Rbutton = 0x02,
        Cancel  = 0x03,
        Mbutton = 0x04,

        Back    = 0x08,
        Tab = 0x09,

        Clear   = 0x0C,
        Return  = 0x0D,

        Shift   = 0x10,
        Control = 0x11,
        Menu    = 0x12,
        Pause   = 0x13,
        Capital = 0x14,

        Kana    = 0x15,
        Hangeul = 0x15,
        Hangul  = 0x16,
        Ime_On  = 0x17,
        Junja   = 0x18,
        Final   = 0x19,
        Hanja   = 0x19,
        Ime_Off = 0x1A,

        Escape  = 0x1B,

        Convert = 0x1C,
        Monconvert  = 0x1D,
        Accept  = 0x1E,
        ModeChange  = 0x1F,

        Space   = 0x20,
        Priton  = 0x21,
        Next    = 0x22,
        End = 0x23,
        Home    = 0x24,
        Left    = 0x25,
        Right   = 0x26,
        Up  = 0x27,
        Down    = 0x28,
        Select  = 0x29,
        Print   = 0x2A,
        Execute = 0x2B,
        Snapshot    = 0x2C,
        Insert  = 0x2D,
        Delete  = 0x2E,
        Help    = 0x2F,

        Num0  = 0x30,
        Num1  = 0x31,
        Num2  = 0x32,
        Num3  = 0x33,
        Num4  = 0x34,
        Num5  = 0x35,
        Num6  = 0x36,
        Num7  = 0x37,
        Num8  = 0x38,
        Num9  = 0x39,

        
        A   = 0x41,
        B   = 0x42,
        C   = 0x43,
        D   = 0x44,
        E   = 0x45,
        F   = 0x46,
        G   = 0x47,
        H   = 0x48,
        I   = 0x49,
        J   = 0x4A,
        K   = 0x4B,
        L   = 0x4C,
        M   = 0x4D,
        N   = 0x4E,
        O   = 0x4F,
        P   = 0x50,
        Q   = 0x51,
        R   = 0x52,
        S   = 0x53,
        T   = 0x54,
        U   = 0x55,
        V   = 0x56,
        W   = 0x57,
        X   = 0x58,
        Y   = 0x59,
        Z   = 0x5A,

        Lwin    = 0x58,
        Rwin    = 0x59,
        Apps    = 0x5A,

        Sleep   = 0x5F,

        Numpad0 = 0x60,
        Numpad1 = 0x61,
        Numpad2 = 0x62,
        Numpad3 = 0x63,
        Numpad4 = 0x64,
        Numpad5 = 0x65,
        Numpad6 = 0x66,
        Numpad7 = 0x67,
        Numpad8 = 0x68,
        Numpad9 = 0x69,
        Multiple    = 0x6A,
        Add = 0x6B,
        Substract   = 0x6B,
        Sustract    = 0x6D,
        Decimal = 0x6E,
        Divide  = 0x6F,

        F1  = 0x70,
        F2  = 0x71,
        F3  = 0x72,
        F4  = 0x73,
        F5  = 0x74,
        F6  = 0x75,
        F7  = 0x76,
        F8  = 0x77,
        F9  = 0x78,
        F10 = 0x79,
        F11 = 0x7A,
        F12 = 0x7B,
        F13 = 0x7C,
        F14 = 0x7D,
        F15 = 0x7E,
        F16 = 0x7F,
        F17 = 0x80,
        F18 = 0x81,
        F19 = 0x82,
        F20 = 0x83,
        F21 = 0x84,
        F22 = 0x85,
        F23 = 0x86,
        F24 = 0x87,

        Numlock = 0x90,
        Scroll  = 0x91,

        ONumpad_return    = 0x92,

        OFJ_jisho    = 0x92,
        OFJ_masshou  = 0x93,
        OFJ_touroku  = 0x94,
        OFJ_loya = 0x95,
        OFJ_roya = 0x96,

        Lshift  = 0xA0,
        Rshift  = 0xA1,
        Lcontrol    = 0xA2,
        Rcontrol    = 0xA3,
        Lmenu   = 0xA4,
        Rmenu   = 0xA5,

        O_1 = 0xBA,
        O_plus  = 0xBB,
        O_comma = 0xBC,
        O_minus = 0xBD,
        O_period    = 0xBE,
        O_2 = 0xBF,
        O_3 = 0xC0,

        O_4 = 0xDB,
        O_5 = 0xDC,
        O_6 = 0xDD,
        O_7 = 0xDE,
        O_8 = 0xDF,

        O_ax    = 0xE1,

    };
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
        map_.SetLine(0x04, L"|            |                 |");
        map_.SetLine(0x05, L"|      #     |          #      |");
        map_.SetLine(0x06, L"|      |     |          |      |");
        map_.SetLine(0x07, L"#------# #---#-#  #-#   #------#");
        map_.SetLine(0x08, L"|                   |          |");
        map_.SetLine(0x09, L"|                   |          |");
        map_.SetLine(0x0a, L"|                   |          |");
        map_.SetLine(0x0b, L"|      #---# #------#-# #--# #-#");
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
