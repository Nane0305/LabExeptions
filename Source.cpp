
#include <iostream>
#include <string>

using namespace std;

int StrToInt(const char* str)
{
    char s[20];
    int t, i;
    long long res = 0;
    int len = strlen(str);

    try
    {
        t = 1;
        if (str[0] == '-')
            t = -1;

        i = len - 1;
        while (i >= 0)
        {
            if (str[i] == '-')
            {
                if (i == 0) break;
                else throw "Error of minus";
            }

            if (str[i] < '0') throw "Error";
            if (str[i] > '9') throw "Error";

            res = res + (str[i] - '0') * t;

            t *= 10;
            i--;
        }

        if (res > INT32_MAX)
            throw "Error: out of max int";
        if (res < INT32_MIN)
            throw "Error: out of min int";
        return res;
    }

    catch (const char* a)
    {
        cout << a << endl;
        return 0;
    }
}

void main()
{
    string str;
    cout << "Enter line->";
    getline(cin, str);
    cout << StrToInt(str.c_str()) << endl;
}