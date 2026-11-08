#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// Підраховує кількість пар "SQ" або "QS", що не перекриваються (ітераційний спосіб)
int CountPairs(const char* str)
{
    int k = 0;
    size_t i = 0;

    while (str[i] != 0 && str[i + 1] != 0)
    {
        if ((str[i] == 'S' && str[i + 1] == 'Q') ||
            (str[i] == 'Q' && str[i + 1] == 'S'))
        {
            k++;
            i += 2;
        }
        else
            i++;
    }

    return k;
}

// Перевіряє, чи є пара сусідніх букв "SQ" або "QS"
bool HasPair(const char* str)
{
    return CountPairs(str) > 0;
}

// Замінює кожну пару "SQ" або "QS" на "***" 
char* Change(const char* str)
{
    size_t len = strlen(str);

    // кожна пара збільшує довжину на 1 символ (2 -> 3)
    char* tmp = new char[len + CountPairs(str) + 1];
    char* t = tmp;

    tmp[0] = '\0';

    size_t i = 0;
    while (str[i] != 0)
    {
        if (str[i + 1] != 0 &&
            ((str[i] == 'S' && str[i + 1] == 'Q') ||
                (str[i] == 'Q' && str[i + 1] == 'S')))
        {
            *t++ = '*';
            *t++ = '*';
            *t++ = '*';
            *t = '\0';
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    return tmp;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    char str[101];

    cout << "Ведіть рядок:" << endl;
    cin.getline(str, 100);

    if (HasPair(str))
        cout << "Рядок містить пару \"SQ\" або \"QS\"" << endl;
    else
        cout << "Рядок не містить пари \"SQ\" або \"QS\"" << endl;

    char* dest = Change(str);

    cout << "Змінений рядок (вхідний): " << str << endl;
    cout << "Змінений рядок (результат): " << dest << endl;

    delete[] dest;

    return 0;
}