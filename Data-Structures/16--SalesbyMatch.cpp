// v1 unordered map with itrs based loops
// int sockMerchant(int n, vector<int> ar) {
//     unordered_map <int, int> um;
//     for(auto val: ar)
//     {
//         um[val] += 1;
//     }
//     int pairs = 0;

// v2 unordered map with forbased loops
//     // auto itr = um.begin();
//     // for(; itr != um.end(); itr++)
//     // {
//     //     pairs += itr->second / 2;
//     // }
    
//     for(const auto& kv: um)
//     {
//         pairs += kv.second / 2;
//     }
//     return pairs;
// }

// v3 multiset
// int sockMerchant(int n, vector<int> ar) {
//     // set<int> s(ar.begin(), ar.end());
//     multiset<int> s(ar.begin(), ar.end());
//     // unordered_multiset<int> s(ar.begin(), ar.end());    
//     int pairs = 0;
//     auto itr = s.begin();
//     for(; itr != s.end(); itr = s.upper_bound(*itr))
//     {
//         // cout << *itr << ' ' << s.count(*itr) << endl;
//         pairs += s.count(*itr) / 2;
//     }
//     return pairs;
// }

// v4 std members and basics
// int sockMerchant(int n, vector<int> ar) {
//     sort(ar.begin(), ar.end());
//     auto itr = ar.begin();
//     // auto up
//     int pairs = 0;
//     for(; itr != ar.end(); itr = upper_bound(itr, ar.end(), *itr))
//     {
//         pairs += distance(itr, upper_bound(itr, ar.end(), *itr)) / 2;
//     }
//     return pairs;
// }

// v5 O (nlogn) using mostly default algos
int sockMerchant(int n, vector<int> ar) {
    sort(ar.begin(), ar.end());
    int pairs = 0;
    int prev = 0;
    int curr = 0;
    // while(prev != ar.size() - 1)
    // {
    //     // curr = prev;
        int currCnt = 0;
        while(curr != ar.size())
        {
            // holds true even for init
            if(ar[prev] == ar[curr])
            {
                currCnt++;
                curr++;
            }
            else if(ar[prev] != ar[curr])
            {
                prev = curr;
                pairs += currCnt / 2;
                currCnt = 0;
            }
        }
        pairs += currCnt / 2;
        
        
    // }    
    return pairs;
}
