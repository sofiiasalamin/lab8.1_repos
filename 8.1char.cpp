#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* FindPair(char* s)                 // s = вказівник на початок рядка
{
    char* p1 = strstr(s, "SQ");         // p1 = вказівник на найближче "SQ"
    char* p2 = strstr(s, "QS");         // p2 = вказівник на найближче "QS"

    if (p1 == NULL) return p2;
    if (p2 == NULL) return p1;
    return (p1 < p2) ? p1 : p2;         // пара, що трапилась раніше
}

bool Contains(char* s)                  // s = вказівник на початок рядка
{
    return FindPair(s) != NULL;
}

char* Change(char* s)                   // s = вказівник на початок рядка
{
    char* t = new char[strlen(s) * 3 / 2 + 1];
    char* p;                            // p = вказівник на знайдену пару
    int pos = 0;                        // pos = позиція початку пошуку
    *t = 0;

    while ((p = FindPair(s + pos)) != NULL)
    {
        strncat(t, s + pos, p - s - pos);   // частина до пари
        strcat(t, "***");
        pos = p - s + 2;                    // pos = наступний символ після пари
    }
    strcat(t, s + pos);                     // залишок рядка

    strcpy(s, t);

    return t;
}

int main()
{
    char str[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Contains(str))
        cout << "String contains pair SQ or QS" << endl;
    else
        cout << "String does not contain pair SQ or QS" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
