#include <iostream>
using namespace std;

void LT1_star(int i)
{
	char star[6] = "*****";
	char space[5] = "    ";
	cout << &star[4 - i] << endl;
}

void LT1_starP(char* star)
{
	int i;

	for (i = 0; i != 5; i++)
	{
		cout << &star[4 - i] << endl;
	}
}
void LB1_starP()
{
	int i;
	for (i = 0; i != 5; i++)
	{
		
	}
}

void RT1_starP()
{
}

void RB1_starP()
{
}



int main()
{
	int i;
	char star[6] = "*****";
	char space[5] = "    ";

	for (i = 0; i < 5; i++)//연산 더 높은 버전
	{
		LT1_star(i);
	}

	LT1_starP(star);//연산 더 적은 버전
	return 0;
}

/*
반복을 이용해서 함수를 호출하면서 i값을 매개변수로 보내주는 방법

함수를 호출하면서 star와 space의 포인터를 매개변수로 보내서
함수의 내부에서 반복을 하는 방법
*/