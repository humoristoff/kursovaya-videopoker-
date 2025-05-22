#include "card.h"
#include "deck.h"
#include "hand.h"
#include "game.h"
#include "ui.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(0,"");

    srand(static_cast<unsigned>(time(0)));
    int balance = 100;
    const int HAND_SIZE = 5;
    Card hand[HAND_SIZE];
    GameResult history[5];
    int historyCount = 0;

    bool running = true;

    while (running) {
        clearScreen();
        printMenu();

        int choice;
        cout << "\n\t\t\tВыберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            clearScreen();
            int bet = getBet(balance);
            balance -= bet;

            const int DECK_SIZE = 52;
            Card deck[DECK_SIZE];
            generateDeck(deck, DECK_SIZE);
            shuffleDeck(deck, DECK_SIZE);
            int deckIndex = 0;

            for (int i = 0; i < HAND_SIZE; ++i) {
                hand[i] = deck[deckIndex++];
            }

            cout << "Ваши карты:\n";
            printHand(hand, HAND_SIZE);

            chooseCardsToReplace(hand, HAND_SIZE, deck, deckIndex);

            cout << "\nВаши новые карты:\n";
            printHand(hand, HAND_SIZE);

            int winMultiplier = 0;
            string combination = evaluateHand(hand, HAND_SIZE, winMultiplier);
            int win = bet * winMultiplier;

            cout << "Комбинация: " << combination << "\n";
            cout << "Вы выиграли $" << win << "\n";

            balance += win;

            if (historyCount < 5) {
                history[historyCount++] = { combination, bet, win };
            }
            else {
                for (int i = 1; i < 5; ++i) {
                    history[i - 1] = history[i];
                }
                history[4] = { combination, bet, win };
            }

            cout << "Баланс: $" << balance << "\n";
            cout << "\nНажмите Enter для возврата в меню...";
            cin.ignore();
            cin.get();
            break;
        }
        case 2:
            clearScreen();
            printRules();
            cout << "\nНажмите Enter для возврата в меню...";
            cin.ignore();
            cin.get();
            break;
        case 3:
            clearScreen();
            printHistory(history, historyCount);
            cout << "\nНажмите Enter для возврата в меню...";
            cin.ignore();
            cin.get();
            break;
        case 4:
            running = false;
            break;
        default:
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ошибка ввода. Повторите.\n";
            }
            break;
        }
    }

    cout << "Спасибо за игру!\n";
    return 0;
}