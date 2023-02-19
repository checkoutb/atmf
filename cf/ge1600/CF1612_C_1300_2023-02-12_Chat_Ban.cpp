
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









// 193262357 	Feb/12/2023 12:46UTC+8 	Ouha 	1612C - Chat Ban 	GNU C++17 	Accepted 	93 ms 	0 KB
// 12776

void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;

    ll k, x;
    cin >> k >> x;
    
    ll t2 = (1LL + k) * k / 2;
    ll st, en, md;
    ll ans = 0;
    if (t2 >= x)
    {
        st = 1LL;
        en = k;
        while (st <= en)
        {
            md = (st + en) / 2;
            t2 = (1LL + md) * md / 2;
            if (t2 >= x)
            {
                en = md - 1;
            }
            else
            {
                ans = md;
                st = md + 1;
            }
        }
        cout << ans + 1 << endl;
    }
    else if ((t2 * 2 - k) <= x)
    {
        cout << k * 2 - 1 << endl;
    }
    else
    {
        st = 1LL;
        en = k;
        ll t3 = t2;
        while (st <= en)
        {
            md = (st + en) / 2;
            t2 = t3 * 2 - k - (md + 1LL) * md / 2;
            if (t2 >= x)
            {
                st = md + 1;
            }
            else
            {
                ans = md;
                en = md - 1;
            }
        }
        cout << k * 2 - ans << endl;
    }
    
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
