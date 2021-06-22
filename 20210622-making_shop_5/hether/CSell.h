#pragma once

#define MAXINCHAN 20

class CSell
{
private:
	void Initialize();
	tagPlayer SellProcess(tagPlayer Player, tagItem* Item);
	int InchanPrice[MAXINXCHAN] = {};

public:
	tagPlayer Management(tagPlayer Player, tagItem* Item);
};
