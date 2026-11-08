#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// Перевіряє, чи символи a і b утворюють пару "SQ" або "QS"
bool IsPair(char a, char b)
{
    return (a == 'S' && b == 'Q') || (a == 'Q' && b == 'S');
}

// Підраховує кількість пар "SQ" або "QS", що не перекриваються (рекурсивно)
int Count(const char* str, int i)
{
    if (str[i] == 0 || str[i + 1] == 0)
        return 0;

    if (IsPair(str[i], str[i + 1]))
        return 1 + Count(str, i + 2);
    else
        return Count(str, i + 1);
}

// Перевіряє, чи є пара сусідніх букв "SQ" або "QS"
bool HasPair(const char* str)
{
    return Count(str, 0) > 0;
}

// Записує в dest змінений рядок: кожну пару "SQ" або "QS" замінює на "***"
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] == 0)
    {
        *t = '\0';
        return dest;
    }

    if (IsPair(str[i], str[i + 1]))
    {
        *t++ = '*';
        *t++ = '*';
        *t++ = '*';
        *t = '\0';
        return Change(dest, str, t, i + 2);
    }
    else
    {
        *t++ = str[i];
        *t = '\0';
        return Change(dest, str, t, i + 1);
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char str[101];

    cout << "Введіть рядок:" << endl;
    cin.getline(str, 100);

    if (HasPair(str))
        cout << "Рядок містить " << Count(str, 0) << " пар \"SQ\" або \"QS\"" << endl;
    else
        cout << "Рядок не містить пар \"SQ\" або \"QS\"" << endl;

    // кожна пара збільшує довжину на 1 символ (2 -> 3)
    char* dest1 = new char[strlen(str) + Count(str, 0) + 1];
    dest1[0] = '\0';

    char* dest2;

    dest2 = Change(dest1, str, dest1, 0);

    cout << "Змінений рядок (вхідний): " << str << endl;
    cout << "Змінений рядок (результат): " << dest2 << endl;

    delete[] dest1;

    return 0;
}