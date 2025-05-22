#pragma once
#include "card.h"
#include <string>

using namespace std;

struct GameResult {
    string combination;
    int bet;
    int win;
};

int getBet(int balance);
void chooseCardsToReplace(Card hand[], int size, Card deck[], int& deckIndex);
void printHistory(GameResult history[], int count);