
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









// 190444293 	Jan/25/2023 12:10UTC+8 	Ouha 	1628B - Peculiar Movie Preferences 	GNU C++17 	Accepted 	93 ms 	200 KB


// a : a, ba,
// ab : a, ba, cba
// abc : ba, cba
// a + b/bc/bcX : cba
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    // 1:not-end, 2:end, 3:1&2
    //vector<vector<vector<int>>> vvvi(26, vector<vector<int>>(26, vector<int>(26, 0)));
    vector<bool> vb(26, false);     // useless, 'a' is palindrome
    vector<vector<bool>> vvb(26, vector<bool>(26, false));
    vector<vector<vector<bool>>> vvvb(26, vector<vector<bool>>(26, vector<bool>(26, false)));

    string s;
    bool ans = false;
    int a, b, c;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> s;
        if (ans)
            continue;

        a = s[0] - 'a';
        b = s.size() > 1 ? (s[1] - 'a') : -1;
        c = s.size() > 2 ? (s[2] - 'a') : -1;


        if (s.size() == 1)
        {
            ans = true;         // s is palindrome
        }
        else if (s.size() == 2)
        {
            if (a == b)
            {
                ans = true;
            }
            else if (vb[b] || vvb[b][a])
            {
                ans = true;
                continue;
            }
            else
            {
                // ab : ab Xba, baX ab
                for (int j = 0; j < 26; ++j)
                {
                    if (vvvb[b][a][j])
                    {
                        ans = true;
                        break;
                    }
                }
            }
            vvb[a][b] = true;
        }
        else
        {
            //if (a == b && b == c)       // ....
            if (a == c)
            {
                ans = true;
            }
            else if (vvvb[c][b][a] || vvb[c][b])
            {
                // abc : abc cba, cba abc , abc ba, cb abc
                // ...in order
                ans = true;
            }
            vvvb[a][b][c] = true;
        }
        
    }

    cout << (ans ? "Yes" : "No") << endl;
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
