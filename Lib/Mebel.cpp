#pragma once

#include "Button.cpp"
#include "TXLib.h"

struct Mebel
{
    const char* adressMebeli;
    bool risovat;
    int MOUSE_X;
    int MOUSE_Y;
    HDC pctr;
    int width;
    int height;
    int awidth;
    int aheight;
};

//Clear workspace
void decor_destruction (Mebel* Tomb, int count_mebel);
//Draw all workspace parts
void draw_all_mebel(Mebel* Tomb, int count_mebel);

void decor_destruction (Mebel* Tomb, int count_mebel)
{
    for (int i=0; i<count_mebel; i++)
    {
        Tomb[i] = {false, 0, 0};
    }
}

void draw_all_mebel(Mebel* Tomb, int count_mebel)
{
    for (int i=0; i<count_mebel; i++)
    {
        if (Tomb[i].risovat)
        {
            Win32::TransparentBlt (txDC(), Tomb[i].MOUSE_X, Tomb[i].MOUSE_Y, Tomb[i].awidth, Tomb[i].aheight, Tomb[i].pctr, 0, 0, Tomb[i].width, Tomb[i].height, TX_WHITE);
        }
    }
}

void checkalka( int nomer_kartinki, Mebel* Tomb)
{
    int screenW = GetSystemMetrics (SM_CXSCREEN);
    int screenH = GetSystemMetrics (SM_CYSCREEN);

    if (txMouseButtons() & 1)
    {
        bool many = false;

        for (int p = 0; p < nomer_kartinki; p++)
        {
            if (Tomb[nomer_kartinki].MOUSE_Y < screenH-300 &&
                Tomb[nomer_kartinki].MOUSE_X >= Tomb[p].MOUSE_X + Tomb[p].awidth &&
                Tomb[nomer_kartinki].MOUSE_X + Tomb[nomer_kartinki].awidth <= Tomb[p].MOUSE_X &&
                Tomb[nomer_kartinki].MOUSE_Y >= Tomb[p].MOUSE_Y + Tomb[p].awidth &&
                Tomb[nomer_kartinki].MOUSE_Y + Tomb[nomer_kartinki].awidth <= Tomb[p].MOUSE_Y
                && Tomb[p].risovat)
            {
                many = true;
            }
        }

        Tomb[nomer_kartinki].risovat = !many;
    }
}
