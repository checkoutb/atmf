
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









// 191073781 	Jan/29/2023 17:30UTC+8 	Ouha 	1622C - Set or Decrease 	GNU C++17 	Accepted 	405 ms 	800 KB
// 9965

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    ll k2;
    cin >> k2;

    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    sort(begin(vi), end(vi));
    ll ans = 1LL << 40;
    //ll sum2 = std::accumulate(begin(vi), end(vi));
    ll sum2 = 0LL;
    int mn = vi[0];
    ll t2;
    for (int i = 1; i <= sz1; ++i)       // [>= i] will be set to [0]
    {
        t2 = k2 - sum2;
        if (t2 < 0)
        {
            t2 -= sz1 - i;
        }
        else
        {
//            t2 += sz1 - i;
        }
        //t2 = (k2 + sz1 - i - sum2) / (sz1 - i + 1);          // need mn
        t2 = t2 / (sz1 - i + 1);
        if (t2 < mn)
        {
            t2 = (mn - t2) + (sz1 - i);
        }
        else
        {
            t2 = sz1 - i;
        }
        if (i < sz1)
            sum2 += vi[i];
        ans = min(ans, t2);
    }

    cout << ans << endl;
}


int main()
{
#ifdef __test
    int a = -1 / 2;
    cout << a << endl;      // 0 0 -1 1
    a = -1 / -2;
    cout << a << endl;
    a = -3 / 2;
    cout << a << endl;
    a = -3 / -2;
    cout << a << endl;
#endif

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
