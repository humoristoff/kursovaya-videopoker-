#include "deck.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

void generateDeck(Card deck[], int size) {
    int index = 0;
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r) {
            deck[index].suit = static_cast<Suit>(s);
            deck[index].rank = static_cast<Rank>(r);
            ++index;
        }
    }
}

void shuffleDeck(Card deck[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(deck[i], deck[j]);
    }
}