#include <iostream>
using namespace std;

int x;
int y;
int i;
int j;

void NinetoNine()
{
	i = 0;
	j = 0;

	for (;;)
	{
		if (j == 3 || j == 6 || j == 9)
		{
			cout << endl;
		}

		if (j == 9)
		{
			j = 0;
			i++;
			cout << endl;
		}

		cout << i + 1 << " X " << j + 1 << " = " << (i + 1) * (j + 1) << "\t";

		j++;

		if (i == 8 && j == 9)
		{
			break;
		}

	}
}
int main()
{
	NinetoNine();


	return 0;
}
