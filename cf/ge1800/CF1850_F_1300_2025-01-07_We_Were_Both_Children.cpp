
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




// 300008332 	Jan/07/2025 16:37UTC+8 	Ouha 	1850F - We Were Both Children 	C++20 (GCC 13-64) 	Accepted 	358 ms 	100 KB


// tle   200000 全1 知道了 计数。

// n有点大，没有办法 for for 吧？
// ok， sort 遍历 每个 hop，然后 *2 *3 .. 类似 埃式筛
// 每个 hop 都得 +，直到 超过 sz1?  有没有可能 让后续的 带一下？
// 似乎可以啊， 当前hop，如果能被前面的一个hop整除，那么就 +1.  算了。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::sort(std::begin(vi), std::end(vi));
    vi.push_back(2100000000);

    std::vector<int> v2(sz1 + 1);

    int cnt = 0;
    for (int i = 0; i < sz1 + 1; ++i) {
        if (i == 0 || vi[i] == vi[i - 1]) {
            ++cnt;
            continue;
        }
        
        for (int t2 = vi[i - 1]; t2 <= sz1; t2 += vi[i - 1]) {
            v2[t2] += cnt;
        }
        cnt = 1;
        if (vi[i] > sz1)
            break;
    }

    int ans = -1;
    for (int i = 0; i < v2.size(); ++i) {
        ans = std::max(ans, v2[i]);
    }

    std::cout<<ans<<std::endl;
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    std::cin>>w;
    
    
    
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
