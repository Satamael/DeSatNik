#pragma once

/*!
\file
\brief ������

���� ���������� ���� ���, ��������� � �������

\authors DeSatNik team
\version 1.0.0
\date 13.11.2018
\bug �����������, ���� ���
\warning ����������
\name ������� ��������� � �������

*/

#include "Button.cpp"
#include "TXLib.h"
/*!
\brief ������� �������� ������������

������� ��������� �������� ������������ ������


\param[in] double minX1 ������ ����������� ���������� X
\param[in] double maxX1 ������ ������������ ���������� X
\param[in] double minX2 ������ ����������� ���������� X
\param[in] double maxX2 ������ ������������ ���������� X
*/
double oneDimensionalDistance (double minX1, double maxX1, double minX2, double maxX2)
{
    double distance = 0;

    if (minX1  < maxX1 && minX2  < maxX2 &&               //minX1   < maxX1 < minX2  < maxX2
                maxX1  < minX2)
    {
    distance = minX2 - maxX1;
    }
      else if (minX1  < minX2 && maxX1  < maxX2 &&        //minX1   < minX2  < maxX1 < maxX2
                minX2  < maxX1)
    {
    distance = 0;
    }
    else if (minX1  < minX2 && maxX2  < maxX1 &&        //minX1   < minX2  < maxX2 < maxX1
                minX2  < maxX2)
    {
        distance = 0;
    }
        else if (minX2  < minX1 && maxX1  < maxX2 &&        //minX2   < minX1  < maxX1 < maxX2
                minX1  < maxX1) {
        distance = 0;
    } else if (minX2  < minX1 && maxX2  < maxX1 &&        //minX2   < minX1  < maxX2 < maxX1
                minX1  < maxX2)
    {
        distance = 0;
    }
    else if (minX2  < maxX2 && minX1  < maxX1 &&        //minX2   < maxX2  < minX1  < maxX1
                maxX2  < minX1)
    {
        distance = minX1 - maxX2;
    }

    return distance;
}


struct Mebel
{
    const char* adressMebeli; ///\brief ���� � ��������
    bool risovat; ///\brief ���������
    int MOUSE_X; ///\brief X ���������� ����
    int MOUSE_Y; ///\brief Y ���������� ����
    HDC pctr; ///\brief ��������
    int width; ///\brief ������ �������
    int height; ///\brief ������ �������
    int awidth; ///\brief ������ �������
    int aheight; ///\brief ������ �� ������ ������
};

//Clear workspace
/*!
\brief ������� ����������

������� ������� ������� �������


\param[in] Mebel* Tomb ��������� ������
\param[in] int count_mebel ������ �����������
*/
void decor_destruction (Mebel* Tomb, int count_mebel);
//Draw all workspace parts
void draw_all_mebel(Mebel* Tomb, int count_mebel,bool wather, HDC WatherMark);

void decor_destruction (Mebel* Tomb, int count_mebel)
{
    for (int i=0; i<count_mebel; i++)
    {
        Tomb[i] = {false, 0, 0};
    }
}
/*!
\brief ������� ��������� ������

������� ������ ��� ������

\param[in] Mebel* Tomb �������� ������
\param[in] int count_mebel ������ �����������
\param[in] bool wather ��������� �������� �����
\param[in] HDC WatherMark �������� ��� �������� �����
*/
void draw_all_mebel(Mebel* Tomb, int count_mebel,bool wather, HDC WatherMark)
{
    txSetColor(TX_BLACK, 5);
    if(wather== true)
    {
        txTransparentBlt (txDC(), 800, 200, 101, 100, WatherMark, 0, 0);
        //wather=false;
    }

    for (int i=0; i<count_mebel; i++)
    {
        if (Tomb[i].risovat)
        {
            Win32::TransparentBlt (txDC(), Tomb[i].MOUSE_X, Tomb[i].MOUSE_Y, Tomb[i].awidth, Tomb[i].aheight, Tomb[i].pctr, 0, 0, Tomb[i].width, Tomb[i].height, TX_WHITE);

        }
    }
}
/*!
\brief ������� �������� ������������

������� ��������� �������� ������������ ������


\param[in] int nomer_kartinki �����
\param[in] Mebel* Tomb ������
\param[in] int vsego_kart ������
*/
void checkalka( int nomer_kartinki, Mebel* Tomb, int vsego_kart)
{
    int screenW = GetSystemMetrics (SM_CXSCREEN);
    int screenH = GetSystemMetrics (SM_CYSCREEN);

    if (txMouseButtons() & 1)
    {
        if (Tomb[nomer_kartinki].MOUSE_Y + Tomb[nomer_kartinki].aheight > screenH-300)
        {
            Tomb[nomer_kartinki].risovat = false;
        }

        for (int predydushii_nomer = 0; predydushii_nomer < vsego_kart; predydushii_nomer++)
        {
            if (predydushii_nomer != nomer_kartinki &&
                oneDimensionalDistance(Tomb[nomer_kartinki].MOUSE_X + 1,    Tomb[nomer_kartinki].MOUSE_X    + Tomb[nomer_kartinki].awidth,
                                       Tomb[predydushii_nomer].MOUSE_X + 1, Tomb[predydushii_nomer].MOUSE_X + Tomb[predydushii_nomer].awidth) == 0
                and
                Tomb[predydushii_nomer].risovat
                and
                oneDimensionalDistance(Tomb[nomer_kartinki].MOUSE_Y + 1,    Tomb[nomer_kartinki].MOUSE_Y    + Tomb[nomer_kartinki].aheight,
                                       Tomb[predydushii_nomer].MOUSE_Y + 1, Tomb[predydushii_nomer].MOUSE_Y + Tomb[predydushii_nomer].aheight) == 0)
            {
                Tomb[nomer_kartinki].risovat = false;
            }
        }
    }
}
