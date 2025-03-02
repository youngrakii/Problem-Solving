#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int data = 0;
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            data++;
        else if (s[i] == ')')
            data--;

        if (data < 0)
            return false;

    }
    return data == 0;
}