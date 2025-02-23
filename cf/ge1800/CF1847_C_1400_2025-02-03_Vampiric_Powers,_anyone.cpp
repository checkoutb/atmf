
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
//#include <iomanip>    // std::setprecision(10)
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






// 304234753 	Feb/03/2025 18:50UTC+8 	Ouha 	1847C - Vampiric Powers, anyone? 	C++20 (GCC 13-64) 	Accepted 	124 ms 	100 KB


// i to last
// max power in any
// 是不是 所有的 出现过的 1 都设置上？ 不是 8,2,4,12,1 -> 14 不是 15.
//
// 复制[i,n] == 消除了[i,n]
// [n,n] -> [n-1,n+1]
//
// 似乎是 子数组？ 但是子数组需要 O(n^2) 。 ai < 2^8 不知道怎么利用。
//
// pfx 异或， 2个再异或 就是 子数组的值。  256，难道 对每个值 计算256？  似乎可以，千万级别，可以过的。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<bool> vb(256);
    int got = 0;
    int ans = -1;
    int mx = 0;
    for (size_t i = 0; i < sz1; ++i) {
        got ^= vi[i];
        ans = std::max(ans, got);
        for (int j = 1; j <= mx; ++j) {
            if (vb[j]) {
                int t2 = got ^ j;
                ans = std::max(ans, t2);
            }
        }
        vb[got] = true;
        mx = std::max(mx, got);
    }
    
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
