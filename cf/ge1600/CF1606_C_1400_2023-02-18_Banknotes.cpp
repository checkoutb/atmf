
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
#include <cmath>
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








// 194072662 	Feb / 18 / 2023 13:45UTC + 8 	Ouha 	1606C - Banknotes 	GNU C++17 	Accepted 	140 ms 	100 KB
// 11938

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    myvi vi(sz1);
    int t2;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        vi[i] = pow(10, t2);
    }
    ++kk;
    ll ans = 0LL;
    for (int i = 0; i < sz1 - 1 && kk > 0; ++i)
    {
        t2 = vi[i + 1] / vi[i] - 1;
        if (t2 >= kk)
        {
            ans += 1LL * vi[i] * kk;
            kk = 0;
        }
        else
        {
            ans += 1LL * vi[i] * t2;
            kk -= t2;
        }
    }
    ans += 1LL * kk * vi[sz1 - 1];
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
