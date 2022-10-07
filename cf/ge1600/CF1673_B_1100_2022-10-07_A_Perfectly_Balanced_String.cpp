
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








// 174951923 	Oct/07/2022 17:08UTC+8 	Ouha 	1673B - A Perfectly Balanced String? 	GNU C++17 	Accepted 	77 ms 	500 KB
// 12021

// "abc" * x ?
void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    
    string s;
    cin >> s;
    
    sz1 = s.size();
    
    char ch = s[0];

    int arr[123] = { 0 };
    ++arr[ch];
    int snd = -1;
    bool b3 = true;
    for (int i = 1; i < sz1; ++i)
    {
        if (s[i] == ch && snd == -1)
        {
            snd = i;
        }

        if (b3 && (arr[s[i]] == 1))
        {
            if (s[i] != ch)
            {
                cout << "NO" << endl;
                return;
            }
            else 
            {
                b3 = false;
            }
        }

        ++arr[s[i]];
    }
    
    int mn = 1234567;
    int mx = -1;

    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (arr[i] > 0)
        {
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
    }
    if (mn + 1 < mx)
    {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < snd; ++i)
    {
        for (int j = i + snd; j < sz1; j += snd)
        {
            if (s[j] != s[i])
            {
                cout << "NO" << endl;
                return;
            }
        }

    }
    cout << "YES" << endl;
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
