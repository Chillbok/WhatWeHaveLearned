#include <iostream>
#include "stdio.h"
#include "windows.h"

using namespace std;
int main()
{
	int nNumber[24];
	int nInsideNumber = 0;
	int nLineNumber = 0;
	int nInsideNumPlus = 0;


	nInsideNumber = 0;
	nInsideNumPlus = 1;
	nLineNumber = 1;
	

	nNumber[nInsideNumber] = nInsideNumPlus;
	while (nInsideNumber < 25)
	{
		if (nLineNumber < 6)
		{
			cout << nInsideNumPlus;
			cout << "\t";
			nLineNumber++;
		}
		else if (nLineNumber == 6)
		{
			cout << endl;
			nLineNumber = 1;
			continue;
		}
		nInsideNumber++;
		nInsideNumPlus++;

	}
	

	return 0;
}
