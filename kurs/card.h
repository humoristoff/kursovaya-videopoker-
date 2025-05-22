#pragma once
#include <string>
#include <windows.h>

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct Card {
    Rank rank;
    Suit suit;
};

void printCard(const Card& card);
bool compareCards(const Card& a, const Card& b);