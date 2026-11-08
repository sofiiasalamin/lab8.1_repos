#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

size_t FindPair(const string& s, size_t pos)    // pos = позиція початку пошуку
{
    size_t p1 = s.find("SQ", pos);              // p1 = позиція найближчого "SQ"
    size_t p2 = s.find("QS", pos);              // p2 = позиція найближчого "QS"

    return min(p1, p2);                         // npos є найбільшим значенням,
    // тому min поверне пару, що трапилась раніше
}

bool Contains(const string& s)
{
    return FindPair(s, 0) != string::npos;
}

string Change(string& s)
{
    size_t pos = 0;

    while ((pos = FindPair(s, pos)) != string::npos)
    {
        s.replace(pos, 2, "***");
        pos += 3;                               // пропускаємо вставлені зірочки
    }

    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    if (Contains(str))
        cout << "String contains pair SQ or QS" << endl;
    else
        cout << "String does not contain pair SQ or QS" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}