#include "ui.h"
#include <iostream>
#include <windows.h>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << R"( ╔════════════════════════════════════════════════════════════╗
 ║                                                            ║
 ║                                                            ║
 ║                                                            ║
 ║                                                            ║
 ║  8b,dPPYba,   ,adPPYba,  88   ,d8  ,adPPYba,  8b,dPPYba,   ║
 ║  88P'    "8a a8"     "8a 88 ,a8"  a8P_____88  88P'   "Y8   ║
 ║  88       d8 8b       d8 8888[    8PP"""""""  88           ║
 ║  88b,   ,a8" "8a,   ,a8" 88"Yba,  "8b,    aa  88           ║
 ║  88YbbdP"'     "YbbdP"'  88   Y8a  "Ybbd8"'   88           ║
 ║  88                                                        ║
 ║  88                                                        ║
 ║                                                            ║
 ╚════════════════════════════════════════════════════════════╝
)" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "\t\t||         1. Играть         ||\n";
    cout << "\t\t||       2. Правила игры     ||\n";
    cout << "\t\t||       3. История игр      ||\n";
    cout << "\t\t||         4. Выйти          ||\n";
}

void printRules() {
    cout << "Правила игры в покер:\n";
    cout << "1. Игрок получает 5 карт.\n";
    cout << "2. Он может выбрать карты для замены.\n";
    cout << "3. Игрок побеждает, если соберёт определенную комбинацию карт.\n";
    cout << "4. Ставки увеличиваются в зависимости от комбинации.\n";
    cout << "5. История последних 5 игр доступна из меню.\n";
}

void printHand(Card hand[], int size) {
    for (int i = 0; i < size; ++i) {
        printCard(hand[i]);
    }
    cout << endl;
}