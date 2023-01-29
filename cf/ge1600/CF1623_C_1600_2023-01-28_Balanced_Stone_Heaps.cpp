
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
#include <numeric>            // accumulate
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









// 190931479 	Jan/28/2023 14:04UTC+8 	Ouha 	1623C - Balanced Stone Heaps 	GNU C++17 	Accepted 	405 ms 	800 KB
// 9344

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    long long sum2 = std::accumulate(std::begin(vi), end(vi), 0LL);

    int st = 0;
    int en = sum2 / sz1;
    int ans = -1;
    while (st <= en)
    {
        int md = (st + en) / 2;

        bool can = true;

        ll t0 = 0;
        ll t1 = 0;
        ll t4 = 0;
        for (int i = sz1 - 1; i >= 2; --i)
        {
            if (t0 + vi[i] < md)
            {
                can = false;
                break;
            }
            else
            {
                t4 = t0 + vi[i] - md;       // d
                t4 = min((long long)vi[i], t4);
                t4 /= 3;
                t0 = t1 + t4;
                t1 = t4 * 2;
            }
        }

        if (can && (vi[0] + t1 >= md) && (vi[1] + t0 >= md))
        {
            ans = md;
            st = md + 1;
        }
        else
        {
            en = md - 1;
        }
    }

    cout << ans << endl;
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
