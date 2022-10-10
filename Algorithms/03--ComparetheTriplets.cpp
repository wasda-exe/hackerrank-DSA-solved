#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[3], b[3], s[2];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < 3; j++)
    {
        cin >> b[j];
    }
    s[0] = 0;
    s[1] = 0;
    for (int k = 0; k < 3; k++)
    {
        if (a[k] > b[k])
        {
            s[0] += 1;
        }
        else if (a[k] < b[k])
        {
            s[1] += 1;
        }
    }
    cout << s[0] << ' ' << s[1];
    return 0;
}
