// v1 using stl
// int hurdleRace(int k, vector<int> height) {
//     int heightTallestHurdle = *(max_element(height.begin(), height.end()));
//     if(k >= heightTallestHurdle)
//     {
//         return 0;
//     }
//     else
//     {
//         return heightTallestHurdle - k;
//     }
// }

// v2 random stuff, bruv
// int hurdleRace(int k, vector<int> height) {
    
//     int mx = numeric_limits<int>::min();
//     for(int val: height)
//     {
//     // mx = max(mx, val);
//         if(val > mx)
//             mx = val;   
//     }
//     if(k >= mx)
//     {
//         return 0;
//     }
//     else
//     {
//         return mx - k;
//     }
//     //
// }

//v 3
// just return max(0, mx - k);
// int hurdleRace(int k, vector<int> height) {
//     int heightTallestHurdle = *(max_element(height.begin(), height.end()));
//         return max(0, heightTallestHurdle - k);
// }

// v4 one liner
int hurdleRace(int k, vector<int> height) {
        return max(0, *(max_element(height.begin(), height.end())) - k);
}
