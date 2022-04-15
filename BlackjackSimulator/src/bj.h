#pragma once

#include <vector>
#include <random>

#define DECK_SIZE 52
#define MIN_DECK_COUNT 1
#define MAX_DECK_COUNT 10

typedef unsigned int card;

class Shoe {

public:
	Shoe(size_t deckCount);
	~Shoe();

	card NextCard();
	void AppendVectorTo(std::vector<card>&, std::vector<card>&);
	void AddToShoe(std::vector<card>&);
private:
	size_t deckCount;

	std::vector<card> cards;
	std::default_random_engine rng{ std::random_device{}() };
	
	void Shuffle();
};