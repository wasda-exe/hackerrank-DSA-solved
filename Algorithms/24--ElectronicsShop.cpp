 // v1 brute force vec
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
     vector<int> spent;
    // set<int> spent;
    for(int i = 0; i < keyboards.size(); i++)
    {
        for(int j = 0; j < drives.size(); j++)
        {
            // each budget inserted in sorted order
            // spent.insert(keyboards[i] + drives[j]);
            spent.push_back(keyboards[i] + drives[j]);
        }
    }
    sort(spent.begin(), spent.end());
    int k;
    for(k = spent.size() - 1; k >= 0; k--)
    {
        if(spent[k] <= b)
        {
            break;
        }
    }
    if(k != -1)
    {
        return spent[k];
    }
    else
    {
        return -1;
    }
}

 // v1 brute force set
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    set<int> spent;
    for(int i = 0; i < keyboards.size(); i++)
    {
        for(int j = 0; j < drives.size(); j++)
        {
            // each budget inserted in sorted order
            spent.insert(keyboards[i] + drives[j]);
            // spent.push_back(keyboards[i] + drives[j]);
        }
    }
    // sort(spent.begin(), spent.end());
    // int k;
    auto itr = spent.rbegin();
    for(; itr != spent.rend(); itr++)
    {
        if(*itr <= b)
        {
            break;
        }
    }
    if(itr != spent.rend())
    {
        return *itr;
    }
    else
    {
        return -1;
    }
}

// v3, brute using only forward iters
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    set<int> spent;
    for(int i = 0; i < keyboards.size(); i++)
    {
        for(int j = 0; j < drives.size(); j++)
        {
            // each budget inserted in sorted order
            spent.insert(keyboards[i] + drives[j]);
            // spent.push_back(keyboards[i] + drives[j]);
        }
    }
    // sort(spent.begin(), spent.end());
    // int k;
    
    // auto itr = spent.rbegin();
    // for(; itr != spent.rend(); itr++)
    // {
    //     if(*itr <= b)
    //     {
    //         break;
    //     }
    // }
    
    auto itr = spent.end();
    itr--;
    for(; itr != spent.begin(); itr--)
    {
        if(*itr <= b)
        {
            break;
        }
    }
    
    if(itr != spent.begin())
    {
        return *itr;
    }
    else if(itr == spent.begin() && *itr <= b)
    {
        return *itr;
    }
    else
    {
        return -1;
    }
}

// v4 recur attempt
// int getMoneySpent(vector<int> kb, vector<int> dr, int b) {
//     int i = kb.size() - 1;
//     int j = dr.size() - 1;
//     int bothMoreB;
//     int kbMoreB;
//     int drMoreB;
//     for(;; i--, j--)
//     {
//         // i and j are at ends;
//         bothMoreB = kb[i] + dr[j];
//         kbMoreB = kb[i] + dr[j - 1];
//         drMoreB = kb[i - 1] + dr[j];
//         if(kbMoreB <= b || drMoreB <= b)
//         {
            
//         }
//     }
// }

 // v5 brute force On time O1 space
int getMoneySpent(vector<int> kb, vector<int> dr, int b) {
    // int mx = numeric_limits<int>::min();
    int mx = - 1; // in case no mx within budget found.    
    for (int i = 0; i < kb.size(); i++) {
        for (int j = 0; j < dr.size(); j++)
        {
            if(kb[i] + dr[j] <= b)
            {
                mx = max(mx, kb[i] + dr[j]);
            }
        }
    }
    return mx;
}
