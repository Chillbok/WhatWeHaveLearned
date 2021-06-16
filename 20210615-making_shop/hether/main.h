#pragma once

#include <iostream>
#include <windows.h>
#include <time.h>
#include "CBuy.h"
#include "CSell.h"
#include "CInchant.h"
using namespace std;

struct tagPlayer    //플레이어 구조체
{
    int Money;
    int InchantPt;
};

//함수 오버로딩
void Opening();
bool MainGame();
void EndGame();
void Management();
void Turn_the_Page();