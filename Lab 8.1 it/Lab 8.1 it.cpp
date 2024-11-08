#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція для знаходження позиції четвертої крапки з кінця
int FindFourthDotFromEnd(char* str) {
    int count = 0;
    int index = -1;
    int len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '.') {
            count++;
            if (count == 4) {
                index = i;
                break;
            }
        }
    }
    return index;
}

// Функція для заміни кожної крапки на пару зірочок "**"
char* ReplaceDots(char* str) {
    size_t len = strlen(str);
    // Виділяємо новий рядок достатнього розміру для збереження модифікованого рядка
    char* tmp = new char[len * 2];
    char* t = tmp; // Вказівник на новий рядок для запису результату

    for (size_t i = 0; i < len; i++) {
        if (str[i] == '.') {
            // Додаємо замість крапки дві зірочки
            *t++ = '*';
            *t++ = '*';
        }
        else {
            // Копіюємо інші символи без змін
            *t++ = str[i];
        }
    }
    *t = '\0'; // Завершуємо рядок нуль-символом
    strcpy(str, tmp); // Копіюємо результат назад у початковий рядок
    return tmp;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Знаходимо індекс четвертої крапки з кінця
    int fourthDotIndex = FindFourthDotFromEnd(str);
    if (fourthDotIndex != -1) {
        cout << "The index of the fourth dot from the end is: " << fourthDotIndex << endl;
    }
    else {
        cout << "Less than four dots in the string." << endl;
    }

    // Змінюємо рядок, замінюючи кожну крапку на пару зірочок
    char* modifiedStr = ReplaceDots(str);
    cout << "Modified string (with dots replaced): " << modifiedStr << endl;

    delete[] modifiedStr; // Звільняємо пам'ять
    return 0;
}
