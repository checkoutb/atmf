
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

//we need to make sure that the first taken portal is taken from point 0, 
//so we will iterate over all portalsand check the maximum amount of portals 
//we can take if we use it as the first one.
// 





// g

// error
void fun1()
{
    int sz1, kk;
    cin >> sz1 >> kk;
    
    vector<pair<int, int>> vp(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vp[i].first;
        vp[i].second = 0;
    }
    
    for (int i = 0; i < sz1; ++i)
    {
        if (i < (sz1 >> 1))     // from 0
        {
            vp[i].first += i + 1;
            vp[i].second = -1;
        }
        else
        {
            vp[i].first += sz1 - i;
            vp[i].second = i + 1 - (sz1 - i);
        }
    }

    sort(begin(vp), end(vp));

    ll t2 = 0LL;
    int mn = sz1 + 1;
    int idx = 0;
    while (idx < sz1 && t2 + vp[idx].first <= kk)
    {
        t2 += vp[idx].first;
        mn = min(mn, vp[idx].second);
        ++idx;
    }

    if (mn > 0)
    {
        if (mn > (kk - t2))
        {
            bool b2 = false;
            ll t3 = t2;
            int i3 = idx;
            while (!b2 && idx >= 0)
            {
                t2 = kk - t3 + (idx == 0 ? 0 : vp[idx - 1].first);
                --idx;

                int i2 = idx;
                while (!b2 && i2 < sz1 && vp[i2].first <= t2)
                {
                    if (vp[i2].second == -1)
                        b2 = true;
                    ++i2;
                }
            }
            ++idx;
            idx -= b2 ? 0 : 1;
            if (idx < 0)
                idx = 0;

            if (idx == 0)       // for test case 2...
            {
                for (int i = 0; i < sz1; ++i)
                {
                    if (vp[i].first + (vp[i].second == -1 ? 0 : vp[i].second) <= kk)
                    {
                        cout << 1 << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << idx << endl;
}



// error  2 14 7 5
// 1st
void fun1_error()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;  // coin
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    myvi v2(sz1, 0);    // min cost
    int mni = 0;
    int mn = 1 + vi[0];
    for (int i = 1; i < sz1; ++i)
    {
        if (vi[i] + i + 1 < mn)
        {
            mni = i;
            mn = vi[i] + i + 1;
        }
    }
    
    if (mn > kk)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < sz1; ++i)
    {
        v2[i] = vi[i] + min(i + 1, sz1 - i);
    }
    v2[mni] = 1 << 30;
    sort(begin(v2), end(v2));

    ll t2 = mn;
    int i = 0;
    while (t2 + v2[i] <= kk)
    {
        t2 += v2[i];
        ++i;
    }
    cout << i + 1 << endl;
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
