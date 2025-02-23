
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
//#include <climits>   // INT_MAX

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
//#include <iomanip>    // std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;
//#include <utility>  // pair (include by other header)

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

// D

// dp[i] 代表 vi[1..i] 的 最小剩余
// dp[i] = min{ dp[i-1]+1, {dp[x] | vi[ x + 1 ] = vi[i] } }




// 306033286 	Feb/14/2025 13:26UTC+8 	Ouha 	1842C - Tenzing and Balls 	C++20 (GCC 13-64) 	Accepted 	93 ms 	100 KB

// AC了，但是代码是 尝试出来的， 各种调整。
// v2，代表了 不包含当前下标的 前缀的 最小 剩余。  主要是为了 把 当前下标 当作 删除的区间 ==开始==。 这样计算 ans的时候 就是 直接 前面的 最小剩余 就是 ans， 因为 ==开始== 到 当前下标 的 区间 被删除了。
// 不包含当前下标的 前缀中的 最小剩余，  就是 [i-1]的ans。




// 2 2 2 1 3 1

// [2 1 3 1 2] [3 2 1 1 3]
// 1 1 1 1 1 1 1
// 1 2 1 2 1 2 1 3
// min remain
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    
    int ans = 0;

    std::vector<int> v2(sz1 + 1, -1);  // [color] = min remain in prefix, not include current
    std::vector<int> vans(sz1 + 1, -1);

    for (size_t i = 0; i < sz1; ++i) {
        int t2 = vi[i];
        if (v2[t2] == -1) {
            v2[t2] = i;     // < t2
        } else {
            ans = std::max(ans, static_cast<int>(i + 1 - v2[t2]));
        }
        v2[t2] = std::min(v2[t2], (i == 0) ? sz1 + 1 : (static_cast<int>(i) - vans[i-1]));
        
        vans[i] = ans;

        #ifdef __test
        std::cout<<i<<" - "<<ans<<std::endl;
        #endif
    }

    #ifdef __test
    for (int i : v2) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
    #endif
    
    std::cout<<ans<<std::endl;
}


int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    int w = 1;
    
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:"<<std::endl;
    #endif
    std::cin>>w;  // <------   remove or not
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {        
        fun1();
        
        #ifdef __test
        std::cout << "   ---/////--------/////---" << std::endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
