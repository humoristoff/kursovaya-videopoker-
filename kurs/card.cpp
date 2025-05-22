#include "card.h"
#include <iostream>
#include <string>

using namespace std;

void printCard(const Card& card) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const char* ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    const char* suits[] = { "ч", "б", "к", "п" };

    switch (card.suit) {
    case HEARTS:
    case DIAMONDS:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        break;
    case CLUBS:
    case SPADES:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;
    }

    cout << ranks[card.rank - 2] << suits[card.suit] << " ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

bool compareCards(const Card& a, const Card& b) {
    return a.rank < b.rank;
}