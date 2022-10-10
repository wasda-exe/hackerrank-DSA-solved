#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// v2
// string timeConversion(string s) {
//     int hh, mm, ss;
//     hh = (s[1] - '0') + 10 * (s[0] - '0');
//     mm = (s[4] - '0') + 10 * (s[3] - '0');
//     ss = (s[7] - '0') + 10 * (s[6] - '0');

//     if(hh == 12) s[8] == 'A' ? (hh = 0):(hh = 12);
//     if(hh < 12)  s[8] == 'P' ? (hh += 12): (hh);

//     s[1] = hh % 10 + '0';
//     s[0] = hh / 10 + '0';
//     s.resize(8);
//     return s;
// }

// v1
string timeConversion(string s)
{
    stringstream oss(s);
    int h, m, sec;
    char c;
    string ap;
    oss >> h >> c >> m >> c >> sec >> ap;

    if (ap == "AM")
    {
        if (h == 12)
        {
            h = 0;
        }
    }
    else if (h == 12)
    {
        h = 12;
    }
    else
    {
        h = h + 12;
    }
    stringstream fss;
    fss << setw(2) << setfill('0') << h << ':'
        << setw(2) << setfill('0') << m << ':'
        << setw(2) << setfill('0') << sec;
    s = fss.str();
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
