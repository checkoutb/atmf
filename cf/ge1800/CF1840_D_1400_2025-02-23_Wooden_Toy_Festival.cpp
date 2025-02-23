
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





//  	Feb/23/2025 16:46UTC+8 	Ouha 	1840D - Wooden Toy Festival 	C++20 (GCC 13-64) 	Accepted 	108 ms 	0 KB



// 看了半天，题目没看明白。
/*

3个木匠，每个木匠可以选一个 专精，
n个请求，对于木匠来说，完成这个请求需要 |专精 - 请求| 的时间。
求 ...
...看懂了。 求的是 最大等待时间。 想成：最小等待和了。。。所以 Example 看不明白。
*/

// 二分了。  试下那种难点的二分。

// 好像不用二分， 就是划分3个区间， 使得 最大的区间的跨度 最小。
// 类似 双指针。

void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    if (sz1 <= 3) {
        std::cout<<"0\n";
        return;
    }

    std::sort(std::begin(vi), std::end(vi));

    int ans = vi.back();
    
    size_t idx = 0;
    int t2 = 0;
    int en = vi.back();
    for (size_t i = 0; i < sz1 - 1; ++i) {
        // [0, i] (i,idx] (idx, end)
        // i, i+1, idx, idx+1
        // t2 = vi[i] - vi[0];
        if (idx + 1 < sz1)
            t2 = std::max(vi[idx] - vi[i + 1], en - vi[idx + 1]);
        else
            t2 = en;
        while (idx + 1 < sz1 && vi[idx] - vi[i+1] < en - vi[idx + 1]) {
            ++idx;
            t2 = std::min(t2, std::max(vi[idx] - vi[i+1], en - vi[idx + 1]));
        }
        t2 = std::max(vi[i] - vi[0], t2);
        ans = std::min(ans, t2);
    }
    
    std::cout<<(ans + 1) / 2<<std::endl;
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
