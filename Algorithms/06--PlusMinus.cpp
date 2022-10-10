#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    float pos = 0, neg = 0, z = 0;
    for (int j = 0; j < n; j++)
    {
        pos += (a[j] > 0) ? 1 : 0;
        neg += (a[j] < 0) ? 1 : 0;
        z += (a[j] == 0) ? 1 : 0;
    }
    cout << setprecision(6) << pos / n << endl;
    cout << setprecision(6) << neg / n << endl;
    cout << setprecision(6) << z / n << endl;

    return 0;
}
