#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int y)
{
    if (y < 1918)
    {
        if (y % 4 == 0)
        {
            return ("12.09." + to_string(y));
        }
        else
        {
            return ("13.09." + to_string(y));
        }
    }
    else if (y > 1918)
    {
        if (y % 400 == 0)
        {
            return ("12.09." + to_string(y));
        }
        else if (y % 100 == 0)
        {
            return ("13.09." + to_string(y));
        }
        else if (y % 4 == 0)
        {
            return ("12.09." + to_string(y));
        }
        else
        {
            return ("13.09." + to_string(y));
        }
    }
    else
    {
        return ("26.09." + to_string(y));
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
