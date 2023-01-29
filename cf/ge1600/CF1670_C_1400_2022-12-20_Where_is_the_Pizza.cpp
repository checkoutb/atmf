
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









//186065141 	Dec / 20 / 2022 13:46UTC + 8 	Ouha 	1670C - Where is the Pizza ? GNU C++17 	Accepted 	530 ms 	2000 KB

// 从2个排列取一些数，依然是排列。 每个位置2种可能
// 一旦一个选定后，关联的也选定了，   所以是 uf。。

int ufa(vector<int>& uf, int idx);

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> va(sz1);
    vector<int> vb(sz1);
    vector<int> vc(sz1);
    
    for (int i = 0; i < sz1; ++i)
        cin >> va[i];
    for (int i = 0; i < sz1; ++i)
        cin >> vb[i];
    for (int i = 0; i < sz1; ++i)
        cin >> vc[i];

    vector<int> uf(sz1 + 1, -1);
    
    for (int i = 0; i < sz1; ++i)
    {
        //if (va[i] == vb[i])            
        //    continue;
        int ta = ufa(uf, va[i]);
        int tb = ufa(uf, vb[i]);
        if (ta != tb)
            uf[ta] = tb;
    }
    
    map<int, bool> map2;

    for (int i = 1; i <= sz1; ++i)
    {
        int t2 = ufa(uf, i);
        map2[t2] = true;
    }

    for (int i = 0; i < sz1; ++i)
    {
        if (va[i] == vb[i])
        {
            map2[va[i]] = false;            // .
        }
        if (vc[i])
        {
            map2[ufa(uf, vc[i])] = false;
        }
    }

    int ans = 1;
    const int MOD = 1e9 + 7;

    for (auto& [k, v] : map2)
    {
        if (v)
        {
            ans = (ans * 2) % MOD;
        }
    }
    cout << ans << endl;
}

int ufa(vector<int>& uf, int idx)
{
    return uf[idx] == -1 ? idx : uf[idx] = ufa(uf, uf[idx]);
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
