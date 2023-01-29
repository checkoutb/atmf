
//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>

//#include <cstdio>
//#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <cmath>
//#include <limits.h>   // INT_MAX

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
//#include <unordered_map>
//#include <string.h>       // memset

using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = vector<vector<int>>;
using myvi = vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

// D D

//for (int i = 0; i < n;) {
//    if (s[i] == 'W') {
//        ++i;
//        continue;
//    }
//    int j = i + 1;
//    while (j < n && s[j] != 'W') ++j;
//    bool is_valid = false;
//    FOR(k, i + 1, j) is_valid |= s[k - 1] != s[k];
//    if (!is_valid) {
//        cout << "NO\n";
//        return;
//    }
//    i = j + 1;
//}







//186522104 	Dec / 24 / 2022 10:15UTC + 8 	Ouha 	1669D - Colorful Stamp 	GNU C++17 	Accepted 	61 ms 	300 KB
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    string s;
    cin >> s;
    s.push_back('W');

    bool rb = s[0] != 'W';
    for (int i = 1; i <= sz1; ++i)
    {
        if (s[i] == 'W')
        {
            if (rb)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (s[i - 1] != 'W' && s[i] != s[i - 1])
            {
                rb = false;
            }
            else if (s[i - 1] == 'W')
            {
                rb = true;
            }
        }

        //if (s[i] != 'W' && s[i - 1] != 'W' && s[i] != s[i - 1])
        //{
        //    while (i < sz1 && s[i] != 'W')
        //        ++i;
        //}
    }
    cout << "yes" << endl;
}


int main()
{
    int w = 1;
    cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {        
        fun1();
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
