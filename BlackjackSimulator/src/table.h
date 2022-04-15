#pragma once

#include "bj.h"

class Table
{
public:
	Table(size_t shoeSize, float penetration, bool hitsOnSoft17);
	~Table();

	void PlayRound();

	void Print(bool hideDealerCard);

private:
	size_t shoeSize;
	float penetration;
	size_t indexOfPenetration;
	bool hitsOnSoft17;

	Shoe* shoe;
	std::vector<card> discarded;

	std::vector<card> playerHand;
	std::vector<card> dealerHand;

	void CleanTable();
};