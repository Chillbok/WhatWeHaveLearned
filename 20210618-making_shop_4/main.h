#pragma once

#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;



struct tagPlayer //�÷��̾� ����ü
{
    int Money;
    int InchantPt[INVEN_END];
    int Inventory[INVEN_END];
};

//�Լ� �����ε�
void Openning();
bool MainGame();
void EndGame();
