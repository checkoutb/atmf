
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









// 193717654 	Feb/15/2023 21:21UTC+8 	Ouha 	1610C - Keshi Is Throwing a Party 	GNU C++17 	Accepted 	514 ms 	1600 KB
// 8489

// zui duo ai >
// zui duo bi <
// tag : binary search ????  ok. how many person will be invited.
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    myvi va(sz1);
    myvi vb(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> va[i] >> vb[i];
    }
    
    int st = 1, en = sz1;
    int ans = -1;
    while (st <= en)
    {
        int md = (st + en) / 2;
        int cnt = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (va[i] >= (md - cnt - 1) && vb[i] >= cnt)
            {
                ++cnt;
            }
        }
        if (cnt >= md)
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
