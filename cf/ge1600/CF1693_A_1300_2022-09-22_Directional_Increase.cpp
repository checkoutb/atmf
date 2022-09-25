
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







// 173068680 	Sep/22/2022 21:54UTC+8 	Ouha 	1693A - Directional Increase 	GNU C++17 	Accepted 	312 ms 	2400 KB


// idx > 0, ++[idx], ++idx;
// idx < sz1, --[idx], --idx;
// [sz1 - 1] <= 0
// last non 0    <= 0
// sum == 0
void fun1()
{
    int sz1;
    cin >> sz1;
    
    myvi vi(sz1);
    ll sum2 = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
        sum2 += vi[i];
    }

    if (sum2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    
    vector<ll> v2(sz1, 0);
    int idx = -1;
    for (int i = sz1 - 1; i >= 0; --i)
    {
        if (vi[i] != 0)
        {
            if (vi[i] > 0)
            {
                cout << "NO" << endl;
                return;
            }
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << "YES" << endl;
        return;
    }

    v2[0] = 1;
    for (int i = 1; i < idx; ++i)
    {
        v2[i] = 1;
    }

#ifdef __test
    cout << " ============ " << endl;
    for (int i : v2)
    {
        cout << i << ", ";
    }
    cout << endl << endl;
#endif

    for (int i = idx; i >= 1; --i)
    {
        if (v2[i] <= vi[i])
        {
            cout << "NO" << endl;
            return;
        }
        v2[i - 1] += v2[i] - vi[i] - 1;

#ifdef __test
        cout << " -------- " << i << endl;
        for (int i : v2)
        {
            cout << i << ", ";
        }
        cout << endl << endl;
#endif


    }
    
    if (v2[0] == vi[0])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
