#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */

// v1 Hashing v1
// vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
//     unordered_map<string, int> M;
//     for(string str: stringList)
//     {
//         if(M.insert({str, 1}).second == 0)
//             M[str]++;
//     }
//     vector<int>results;
//     for(string st: queries)
//     {
//         results.push_back(M[st]);
//     }
//     return results;
// }

// v2 multimap. No need, if you count freq, you're still creating duplicates. Those duplicates can be checked via count()
// vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
//     multimap<string, int>M;
//     for(string str: stringList)
//     {
//         M.insert({});
//     }
    
// }

// v3 multiset
// vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
//     multiset<string>S;
//     for(string str: stringList)
//         S.insert(str);
//     vector<int> results;
//     for(string st: queries)
//         results.push_back(S.count(st));
//     return results;
// }

// v4 hashing without fancy insert checks
vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    unordered_map<string, int> M;
    for(string str: stringList)
        if(M.find(str) != M.end())
            M[str]++;
        else
            M[str] = 1;
    vector<int> results;
    for(string str: queries)
        results.push_back(M[str]);
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stringList_count_temp;
    getline(cin, stringList_count_temp);

    int stringList_count = stoi(ltrim(rtrim(stringList_count_temp)));

    vector<string> stringList(stringList_count);

    for (int i = 0; i < stringList_count; i++) {
        string stringList_item;
        getline(cin, stringList_item);

        stringList[i] = stringList_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(stringList, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
