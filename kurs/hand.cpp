#include "hand.h"
#include <algorithm>

using namespace std;

string evaluateHand(Card hand[], int size, int& winMultiplier) {
    sort(hand, hand + size, compareCards);

    bool flush = isFlush(hand, size);
    bool straight = isStraight(hand, size);


    if (flush && straight) {

        if (hand[0].rank == TEN && hand[4].rank == ACE) {
            winMultiplier = 100;
            return "Роял флеш";
        }
        winMultiplier = 50;
        return "Стрит-флеш";
    }

    else if (isFourOfAKind(hand, size)) {
        winMultiplier = 25;
        return "Каре";
    }

    else if (isFullHouse(hand, size)) {
        winMultiplier = 15;
        return "Фулл-хаус";
    }

    else if (flush) {
        winMultiplier = 10;
        return "Флеш";
    }

    else if (straight) {
        winMultiplier = 5;
        return "Стрит";
    }

    else if (isThreeOfAKind(hand, size)) {
        winMultiplier = 3;
        return "Тройка";
    }

    else if (isTwoPair(hand, size)) {
        winMultiplier = 2;
        return "Две пары";
    }

    else if (isPair(hand, size)) {
        winMultiplier = 1;
        return "Пара";
    }

    winMultiplier = 0;
    return "Нет комбинации";
}

bool isStraight(Card hand[], int size) {
    bool normal_straight = true;
    for (int i = 1; i < size; ++i) {
        if (hand[i].rank != hand[i - 1].rank + 1) {
            normal_straight = false;
            break;
        }
    }
    if (normal_straight) return true;

    if (hand[0].rank == TWO &&
        hand[1].rank == THREE &&
        hand[2].rank == FOUR &&
        hand[3].rank == FIVE &&
        hand[4].rank == ACE) {
        return true;
    }

    return false;
}

bool isFlush(Card hand[], int size) {
    Suit suit = hand[0].suit;
    for (int i = 1; i < size; ++i) {
        if (hand[i].suit != suit) {
            return false;
        }
    }
    return true;
}

bool isFourOfAKind(Card hand[], int size) {
    for (int i = 0; i <= size - 4; ++i) {
        if (hand[i].rank == hand[i + 1].rank &&
            hand[i].rank == hand[i + 2].rank &&
            hand[i].rank == hand[i + 3].rank) {
            return true;
        }
    }
    return false;
}

bool isFullHouse(Card hand[], int size) {
    if ((hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank &&
        hand[3].rank == hand[4].rank) ||
        (hand[0].rank == hand[1].rank &&
            hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)) {
        return true;
    }
    return false;
}

bool isThreeOfAKind(Card hand[], int size) {
    for (int i = 0; i <= size - 3; ++i) {
        if (hand[i].rank == hand[i + 1].rank &&
            hand[i].rank == hand[i + 2].rank) {
            return true;
        }
    }
    return false;
}

bool isTwoPair(Card hand[], int size) {
    int pairs = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (hand[i].rank == hand[i + 1].rank) {
            pairs++;
            i++;
        }
    }
    return pairs == 2;
}

bool isPair(Card hand[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (hand[i].rank == hand[i + 1].rank) {
            return true;
        }
    }
    return false;
}