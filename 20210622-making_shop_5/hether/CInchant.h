#pragma once

#define MAXINCHAN 20

class CInchant
{
private:
	//��ȭ Ȯ��: �迭�� �̿��ؼ� �����.
	int InchanPer[MAXINCHAN];
	void Initialize();
	void IncnahtTitle();

	tagPlayer PlayInchant(tagPlayer Player, tagItem* Item);

public:
	tagPlayer Management(tagPlayer Player, tagItem* Item);
};
