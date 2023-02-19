
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

// segement tree






// 193275899 	Feb/12/2023 15:48UTC+8 	Ouha 	1611F - ATM and Students 	GNU C++17 	Accepted 	390 ms 	800 KB
// 5088

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
    int mxlen = 0;
    int st{ -1 }, en{ -1 };
    int idx = 0;
    ll t2 = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        while (idx < sz1 && (kk + t2 + vi[idx]) >= 0)
        {
            t2 += vi[idx++];
        }
        if ((idx - i) > mxlen)
        {
            st = i;
            en = idx - 1;
            mxlen = idx - i;
        }
        if (idx > i)
        {
            t2 -= vi[i];
        }
        else
        {
            idx = i + 1;
        }
    }
    
    if (st == -1)
        cout << -1 << endl;
    else
        cout << st + 1 << ' ' << en + 1 << endl;
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
