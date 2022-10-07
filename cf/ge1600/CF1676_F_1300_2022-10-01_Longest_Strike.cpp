
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
#include <map>
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







// 174215764 	Oct/01/2022 15:29UTC+8 	Ouha 	1676F - Longest Strike 	GNU C++17 	Accepted 	452 ms 	6400 KB


// 
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> kk;
    
    map<int, int> map2;
    int t2;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        ++map2[t2];
    }
    
    int ans = 0;        // mx cnt
    
    map<int, int>::iterator it = map2.begin();
    int cnt = 0;
    int lst = -1;
    int lft = -1;
    int rgh = -1;
    int ansl = -1;
    int ansr = -1;
    if (it->second >= kk)
    {
        ++cnt;
        lst = it->first;
        ans = 1;
        lft = rgh = lst;
        ansl = ansr = lst;
    }
    it++;
    for (; it != map2.end(); it++)
    {
        if (it->second >= kk)
        {
            if (it->first == lst + 1)
            {
                ++cnt;
                ++lst;
                rgh = lst;
                if (cnt > ans)
                {
                    ansl = lft;
                    ansr = rgh;
                    ans = cnt;
                }
            }
            else
            {
                lst = it->first;
                cnt = 1;
                lft = rgh = lst;
                if (ans == 0)
                {
                    ansl = ansr = lst;
                    ans = 1;
                }
            }
        }
    }
    if (lft == -1)
        cout << -1 << endl;
    else
        cout << ansl << ' ' << ansr << endl;
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
