
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



// error
// 
// 6 10 - 3  -  +1 +1 |
// 10 13 - 2 -  13+1  |
void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    
    int a, b;
    cin >> a >> b;          // a < b
    
    // a + (b-a) == b
    // a | b >= b > a
    // 0011 0100 = 0111
    // 0110 1000 = 1110
    // b cover a . a|b=b
    
    int ans = b - a;
    ans = min(ans, (a | b) - b + 1);
    int t2 = -1;
    int t3 = -1;
    int t4 = -1;
    for (int i = 20; i >= 0; --i)
    {
        if (t2 == -1 && (a & (1 << i)) != 0)
        {
            t2 = 0;
            for (int j = 0; j <= i; ++j)
            {
                t2 |= (1 << j);
            }
        }
        if (t2 == -1 && (b & (1 << i)) != 0)
        {
            t3 = i;
        }
        if (t4 == -1 && (a & (1 << i)) != 0 && (b & (1 << i)) == 0)
        {
            t4 = 0;
            for (int j = 0; j <= i; ++j)
                t4 |= (1 << j);
        }
    }
    if (t3 != -1)
    {
        ans = min(ans, 1 + (1 << t3) - a);
    }
    if (t4 != -1)
    {
        ans = min(ans, 1 + (a & t4) - (b & t4));
    }
    ans = min(ans, abs((a & t2) - (b & t2)) + 1);
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
