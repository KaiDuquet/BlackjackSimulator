#include <iostream>

#include "table.h"

Table::Table(size_t shoeSize, float penetration, bool hitsOnSoft17) :
	shoeSize(shoeSize), penetration(penetration), hitsOnSoft17(hitsOnSoft17)
{
	if (penetration < 0) penetration = 0;
	else if (penetration > 1) penetration = 1;

	shoe = new Shoe(shoeSize);

	indexOfPenetration = (size_t) (shoeSize * DECK_SIZE * penetration);
}

Table::~Table()
{
	delete shoe;
}

void Table::Print(bool hideDealerCard)
{
	std::cout << "Dealer Hand:\t" << dealerHand[0] << " ";
	if (hideDealerCard)
		std::cout << "X";
	else
		std::cout << dealerHand[1];

	std::cout << "\nYour Hand:\t" << playerHand[0] << " " << playerHand[1] << "\n----------------------------------------" << std::endl;
}

void Table::CleanTable()
{
	shoe->AppendVectorTo(discarded, playerHand);
	shoe->AppendVectorTo(discarded, dealerHand);

	playerHand.clear();
	dealerHand.clear();
}

void Table::PlayRound()
{
	playerHand.push_back(shoe->NextCard());
	playerHand.push_back(shoe->NextCard());

	dealerHand.push_back(shoe->NextCard());
	dealerHand.push_back(shoe->NextCard());

	Print(true);
	CleanTable();
}