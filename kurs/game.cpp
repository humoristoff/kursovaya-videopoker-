#include "game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int getBet(int balance) {
    int bet;
    while (true) {
        cout << "��� ������: $" << balance << "\n";
        cout << "������� ������: $";
        cin >> bet;

        if (bet > 0 && bet <= balance) {
            return bet;
        }
        cout << "�������� ������. ������� ����� �� 1 �� " << balance << ".\n";
    }
}

void chooseCardsToReplace(Card hand[], int size, Card deck[], int& deckIndex) {
    cout << "\n������� ������ ���� (1-5), ������� ������ ��������, ����� ������.\n";
    cout << "������: 2 4 (������� ������ � ��������� �����). ��������� ���������.\n";

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
        cout << "������� ��� �����.\n";
        return;
    }
    cout << "��������� ����:\n";
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". ����������: " << history[i].combination
            << ", ������: $" << history[i].bet
            << ", �������: $" << history[i].win << "\n";
    }
}