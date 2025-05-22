#pragma once
#include "card.h"
#include <string>

using namespace std;

string evaluateHand(Card hand[], int size, int& winMultiplier);
bool isStraight(Card hand[], int size);
bool isFlush(Card hand[], int size);
bool isFourOfAKind(Card hand[], int size);
bool isFullHouse(Card hand[], int size);
bool isThreeOfAKind(Card hand[], int size);
bool isTwoPair(Card hand[], int size);
bool isPair(Card hand[], int size);