
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
//#include <numeric>
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



// D

// 硬算。。。 最短， bfs。




// g



// mx digit = 9   不会一次 length + 2
// 每次最大 digit ？ 还是 
// 42 - 168 - 
// 42 - 84 - *8
void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;
    
    // length,  val
    ll n, x;
    cin >> n >> x;
    
    int mxd = 0;
    int cnt = 0;
    for (ll t2 = x; t2 > 0; t2 /= 10)
    {
        if (t2 % 10 > mxd)
            mxd = t2 % 10;
        ++cnt;
    }
    if (cnt > n)
    {
        cout << -1 << endl;
        return;
    }
    if (mxd == 1)
    {
        if (cnt == n)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        return;
    }
    
    if (cnt == n)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    while (cnt < n)
    {
        ++ans;

        x = x * mxd;
        cnt = 0;
        mxd = 0;
        for (ll t2 = x; t2 > 0; t2 /= 10)
        {
            ++cnt;
            if (t2 % 10 > mxd)
                mxd = t2 % 10;
        }
    }
    cout << ans << endl;
}


int main()
{
    int w = 1;
    //cin>>w;
    
    
    
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
