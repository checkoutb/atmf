
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


void fun1()
{
    int sz1;
    cin >> sz1;
    myvi vi(sz1);
    myvi v2(sz1);
    for (int i = 0; i < sz1; ++i)   // tea
        cin >> vi[i];
    for (int i = 0; i < sz1; ++i)   // drink
        cin >> v2[i];

    vector<ll> ans(sz1);
    vector<int> v3(sz1 + 1);
    int ti = sz1 - 1;
    int di = sz1 - 1;
    ll t2 = 0LL;
    bool b2 = false;
    for (int i = sz1 - 1; i >= 0; --i)
    {
        t2 += v2[i];
        b2 = false;
        while (t2 > vi[i] && di >= i)
        {
            b2 = true;
            t2 -= v2[di];
            --di;
        }
        if (b2)
        {
            ans[di + 1] += vi[i] - t2;
            ++di;
            t2 += v2[di];
        }
        v3[i] += 1;
        v3[di + 1] -= 1;
    }

    t2 = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        t2 += v3[i];
        ans[i] += t2 * v2[i];
    }
    for (ll l : ans)
        cout << l << ' ';
    cout << endl;
}


// error
void fun1_error()
{
    int sz1, sz2, kk;
    cin >> sz1;

    vector<ll> v3(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> v3[i];

    vector<ll> vll(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vll[i];
    
    vector<ll> ans(sz1);
    vector<ll> v2(sz1);
    
    for (int i = 1; i < sz1; ++i)
        vll[i] += vll[i - 1];
    
    for (int i = 0; i < sz1; ++i)
    {
        vector<ll>::iterator it = upper_bound(begin(vll), end(vll), v3[i] + (i == 0 ? 0 : vll[i - 1]));
        v2[i] += vll[i] - (i == 0 ? 0 : vll[i - 1]);
        int t2 = distance(begin(vll), it);
        if (t2 < sz1)
            v2[t2] -= vll[i] - (i == 0 ? 0 : vll[i - 1]);
        ans[t2 - 1] += v3[i] + (i == 0 ? 0 : vll[i - 1]) - vll[t2 - 1];
    }
    ll t3 = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        t3 += v2[i];
        cout << t3 + ans[i] << ' ';
    }
    cout << endl;
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
