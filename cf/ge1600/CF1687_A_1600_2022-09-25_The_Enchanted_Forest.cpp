
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






// 173379881 	Sep/25/2022 10:50UTC+8 	Ouha 	1687A - The Enchanted Forest 	GNU C++17 	Accepted 	358 ms 	800 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> kk;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }

    ll ans = 0LL;
    ll sum2 = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        sum2 += vi[i];
        if (i >= kk)
        {
            sum2 -= vi[i - kk];
        }
        if (sum2 > ans)
            ans = sum2;
    }
    
    int cnt = min(sz1, kk);
    int en = kk - 1;
    int st = kk - cnt;

    ans += 1LL * (st + en) * cnt / 2;
    
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
