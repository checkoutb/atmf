
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





// 假设一共x个球，x-1个球是a-b-a-b,  mx 可以减少 2*(x-1), sum可以减少 3*(x-1)。 因为1个球， a-b-a-b,这种 能消耗最多比例的a。
// 还剩一个球，需要满足 (mx - 2*(x-1)) * 2 - 1 <= sum - (x-1)*3 ,即 x >= 2mx - sum
//          这是 mx - notmx - mx - notmx - mx - notmx, 消耗最多的 mx。
// 实际上反过来想：一开始 mx - notmx - mx - notmx， 但是mx还是多了，那么此时 就需要 额外的 球 来消耗 mx。就有了上面的假设。


// 188037191 	Jan/05/2023 21:19UTC+8 	Ouha 	1649B - Game of Ball Passing 	GNU C++17 	Accepted 	280 ms 	400 KB

// x
// 1: 
// x-1: 2*(x-1)
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    long long sum2 = 0LL;
    //long long mx = 0LL;
    int mx = 0;

    for (int i = 0; i < sz1; ++i)
    {
        sum2 += vi[i];
        mx = max(mx, vi[i]);
    }
    
    if (sum2 == 0)
    {
        cout << 0 << endl;
        return;
    }

    long long ans = 2LL * mx - sum2;
    ans = max(1LL, ans);
    
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
