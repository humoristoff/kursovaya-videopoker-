#include "game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int getBet(int balance) {
    int bet;
    while (true) {
        cout << "Ваш баланс: $" << balance << "\n";
        cout << "Введите ставку: $";
        cin >> bet;

        if (bet > 0 && bet <= balance) {
            return bet;
        }
        cout << "Неверная ставка. Введите сумму от 1 до " << balance << ".\n";
    }
}

void chooseCardsToReplace(Card hand[], int size, Card deck[], int& deckIndex) {
    cout << "\nВведите номера карт (1-5), которые хотите оставить, через пробел.\n";
    cout << "Пример: 2 4 (оставит вторую и четвертую карты). Остальные заменятся.\n";

    bool keep[5] = { false };
    string input;
    cin.ignore();
    getline(cin, input);

    istringstream iss(input);
    int index;
        while (iss >> index) {
            if (index >= 1 && index <= 5) {
                keep[index - 1] = true;
            }
        }

    for (int i = 0; i < size; ++i) {
        if (!keep[i] && deckIndex < 52) {
            hand[i] = deck[deckIndex++];
        }
    }
}

void printHistory(GameResult history[], int count) {
    if (count == 0) {
        cout << "История игр пуста.\n";
        return;
    }
    cout << "Последние игры:\n";
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". Комбинация: " << history[i].combination
            << ", Ставка: $" << history[i].bet
            << ", Выигрыш: $" << history[i].win << "\n";
    }
}