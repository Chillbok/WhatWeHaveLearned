pragma once

class CBuy
{
private:
	void Initialize();
	tagPlayer BuyProcess(tagPlayer Player, tagItem*Item);

public:
	tagPlayer Management(tagPlayer Player, tagItem* Item);
};
