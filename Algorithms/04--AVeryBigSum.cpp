#include <bits/stdc++.h>

using namespace std;

int main()
{
    int long n, sum;
    cin >> n;
    int a[n];

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum;

    return 0;
}
