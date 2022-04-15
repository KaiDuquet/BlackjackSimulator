#include <iostream>

#include "table.h"

int main()
{
	size_t shoeSize = 6;
	float penetration = 0.75f;
	bool hitsOnSoft17 = false;

	Table table{shoeSize, penetration, hitsOnSoft17};

	table.PlayRound();
}