#include "TXLib.h"
#include "struct.cpp"

bool checkFocus(int MinX, int MaxX, int MinY, int MaxY);
void checkMenuFocus();
void drawMenu (int screenW, int screenH, HDC fon_menu);
void startWorkspace ();


bool checkFocus(int MinX, int MaxX, int MinY, int MaxY)
{
    if (
        txMouseX() >= MinX && //  iuou iaoiaeony ia eiiiea
        txMouseX() <= MaxX &&
        txMouseY() <= MaxY &&
        txMouseY() >= MinY
        )
    {
        return true;
    }

    return false;
}

void checkMenuFocus()
{
    if (checkFocus(40, 560, 810, 850))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "Caioneaao i?ia?aiio" );
    }

    else if (checkFocus(40, 560, 880, 920))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "Nio?aiaiea ?aai-oi" );
    }

    else if (checkFocus(40, 560, 940, 980))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "Caa?ocea aua?aiiie ieaie?iaee" );
    }

    else if (checkFocus(exitButton.x, exitButton.y, exitButton.x1, exitButton.y1))
    {
        txTextOut(txMouseX(), txMouseY() - 20, "����� ������ �����" );
    }
}

void drawMenu (int screenW, int screenH, HDC fon_menu)
{
    txSetColor(TX_BLACK);
    txClear();

    Win32::TransparentBlt (txDC(), 0, 0, screenW, screenH, fon_menu, 0, 0, 1950, 1400, -1);
    //txBitBlt (txDC(), 0, 0, screenW, screenH, fon_menu, 0, 0);

    txSelectFont("Harlow Solid Italic", 40);
    txSetColor(TX_WHITE);
    txTextOut (40, 810, "����� ����������");
    txTextOut (40, 940, "���������");
    txTextOut (40, 1000, "���������");
    txTextOut (exitButton.x, exitButton.y, "�����");
}


void startWorkspace () {     //DODELAT!!!!



}
