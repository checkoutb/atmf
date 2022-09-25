
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








// 173273517 	Sep/24/2022 13:34UTC+8 	Ouha 	1692G - 2^Sort 	GNU C++17 	Accepted 	390 ms 	800 KB


// 1 2 4 8 16 32 64
// a2>a1/2,  a3>a2/2,  a4>a3/2
// 64 32 16 8 4 2 1
// a2*2 > a1
void fun1()
{
    int sz1;
    cin >> sz1;
    int kk;
    cin >> kk;

    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    //ll ans = 0LL;
    int ans = 0;

    int cnt = 1;
    for (int i = 1; i < sz1; ++i)
    {
        if (vi[i] * 2 > vi[i - 1])
        {
            ++cnt;
        }
        else
        {
            if (cnt > kk)
            {
                ans += cnt - kk;
            }
            cnt = 1;
        }
    }
    if (cnt > kk)
        ans += cnt - kk;

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
        
        //cout<<endl;
    }
    
    
    return 0;
}
