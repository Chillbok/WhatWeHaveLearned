#include <iostream>
using namespace std;

void Top_1(char* star, char* space);
void Bottom_1(char* star, char* space);
void Top_2(char* star, char* space);
void Bottom_2(char* star, char* space);

int main()
{
	int i = 0;
	char star[6] = "*****";
	char space[5] = "    ";

	Top_1(star, space);
	Bottom_1(star, space);
	Top_2(star, space);
	Bottom_2(star, space);

	return 0;
}

void Top_1(char* star, char* space)
{
	int i = 0;
	for (i = 0; i != 5; i++)
	{
		cout << &space[i] << &star[4 - i] << &star[4 - i] << &space[i] << endl;
	}
}

void Bottom_1(char* star, char* space)
{
	int i = 0;
	for (i = 0; i != 5; i++)
	{
		cout << &space[4 - i] << &star[i] << &star[i] << &space[4 - i] << endl;
	}
}

void Top_2(char* star, char* space)
{
	int i = 0;
	for (i = 0; i != 5; i++)
	{
		cout << &star[i] << &space[4 - i] << &space[4 - i] << &star[i] << endl;
	}
}

void Bottom_2(char* star, char* space)
{
	int i = 0;
	for (i = 0; i != 5; i++)
	{
		cout << &star[4 - i] << &space[i] << &space[i] << &star[4 - i] << endl;
	}
}