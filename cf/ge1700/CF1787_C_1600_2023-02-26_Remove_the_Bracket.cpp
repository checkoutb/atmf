
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








// g


// 5*0 + 3*4 + 0*3 + 0*5
// 0+3 , 4+0, 3+0 . no >= s .  0-1 * 4-1 == -3 < 0
// s, ai-s ? ++ 0,ai
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    ll us = vi[0] - kk;     // used kk
    ll uais = kk;   // used ai-kk
    ll ts = vi[0] * kk;     // used kk
    ll tais = vi[0] * us;

    ll u0 = vi[0];
    ll ua = 0;
    ll t0 = 0;
    ll ta = vi[0] * vi[1];

    for (int i = 1; i < sz1 - 1; ++i)
    {
        //if (vi[i] >= kk)
        {
            ts = min(kk * us + ts, kk * (uais) + tais);
            tais = min((vi[i] - kk) * us + ts, (vi[i] - kk) * uais + tais);
        }
        //else
        //{
        //    ts = 
        //}


        us = vi[i] - kk;
        uais = kk;
        u0 = vi[i];
        ua = 0;
    }
    
    ts += us * vi[sz1 - 1];
    tais += uais * vi[sz1 - 1];
    
    cout << min(ts, tais) << endl;
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
