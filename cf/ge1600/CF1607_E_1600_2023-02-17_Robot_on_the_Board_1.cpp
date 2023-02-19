
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

// cin.tie(nullptr)->ios::sync_with_stdio(false);
// ...?






// 193998878 	Feb/17/2023 22:08UTC+8 	Ouha 	1607E - Robot on the Board 1 	GNU C++17 	Accepted 	202 ms 	1900 KB
// 8053

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    string s;
    cin >> s;
    
    int r = 0, c = 0;
    int mxr = r, mnr = r, mxc = c, mnc = c;
    
    for (int i = 0; i < s.size(); ++i)
    {
        switch (s[i])
        {
        case 'L':
            --c;
            if (c < mnc)
            {
                if (mxc - c + 1 > sz2)
                    break;
                mnc = c;
            }
            break;
        case 'R':
            ++c;
            if (c > mxc)
            {
                if (c - mnc + 1 > sz2)
                    break;
                mxc = c;
            }
            break;
        case 'D':
            ++r;
            if (r > mxr)
            {
                if (mxr - mnr + 1 > sz1)
                    break;
                mxr = r;
            }
            break;
        default:        // U
            --r;
            if (r < mnr)
            {
                if (mxr - r + 1 > sz1)
                    break;
                mnr = r;
            }
        }
    }
    
    cout << -mnr + 1 << ' ' << -mnc + 1 << endl;
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
