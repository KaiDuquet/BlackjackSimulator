#include <algorithm>

#include "bj.h"

Shoe::Shoe(size_t deckCount):
	deckCount(deckCount)
{
	// The outer loop iterates 4 times (for 4 suits) per deck
	for (size_t j = 0; j < 4 * deckCount; j++) {
		// For every suit of every deck we add the 1 (Ace) through 9
		for (card i = 1; i < 10; i++) {
			cards.push_back(i);
		}
		// The 10, J, Q and K are the same in Blackjack and are worth 10
		for (int i = 0; i < 4; i++) {
			cards.push_back(10);
		}
	}

	Shuffle();
}

Shoe::~Shoe()
{
	cards.clear();
}

card Shoe::NextCard()
{
	card top = cards.back();
	cards.pop_back();
	return top;
}

void Shoe::Shuffle()
{
	std::shuffle(std::begin(cards), std::end(cards), rng);
}

void Shoe::AppendVectorTo(std::vector<card>& target, std::vector<card>& addition)
{
	target.insert(std::end(target), std::begin(addition), std::end(addition));
}

// When a hand has been played the cards will be added to a discard pile. When the shoe needs to be reshuffled this function is called
// and given the pile of cards to be readded to the shoe
void Shoe::AddToShoe(std::vector<card>& pile)
{
	AppendVectorTo(cards, pile);
}