#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������� ��� ����������� ������� �������� ������ � ����
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

// ������� ��� ����� ����� ������ �� ���� ������ "**"
char* ReplaceDots(char* str) {
    size_t len = strlen(str);
    // �������� ����� ����� ����������� ������ ��� ���������� �������������� �����
    char* tmp = new char[len * 2];
    char* t = tmp; // �������� �� ����� ����� ��� ������ ����������

    for (size_t i = 0; i < len; i++) {
        if (str[i] == '.') {
            // ������ ������ ������ �� ������
            *t++ = '*';
            *t++ = '*';
        }
        else {
            // ������� ���� ������� ��� ���
            *t++ = str[i];
        }
    }
    *t = '\0'; // ��������� ����� ����-��������
    strcpy(str, tmp); // ������� ��������� ����� � ���������� �����
    return tmp;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // ��������� ������ �������� ������ � ����
    int fourthDotIndex = FindFourthDotFromEnd(str);
    if (fourthDotIndex != -1) {
        cout << "The index of the fourth dot from the end is: " << fourthDotIndex << endl;
    }
    else {
        cout << "Less than four dots in the string." << endl;
    }

    // ������� �����, �������� ����� ������ �� ���� ������
    char* modifiedStr = ReplaceDots(str);
    cout << "Modified string (with dots replaced): " << modifiedStr << endl;

    delete[] modifiedStr; // ��������� ���'���
    return 0;
}
