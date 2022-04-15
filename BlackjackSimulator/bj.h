#pragma once

#include <stack>

#define DECK_SIZE 52
#define JACK 10
#define QUEEN 10
#define KING 10

typedef unsigned char card;

class Shoe {

public:
	Shoe(size_t deckCount, float deckPenetration);
	~Shoe();

	card nextCard();
private:
	std::stack<card> cards;
	size_t cardsLeft;
	
	void shuffle();
};