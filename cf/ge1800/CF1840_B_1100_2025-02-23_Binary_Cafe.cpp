
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
// ... 钱很多很多，那么 2^k 种选择
// ... 还有一点主要是： 点心的不同组合的价格 构成了 [0, 2^k] 的全集 (并且 每个价格 对应了 唯一一种组合)， 所以 n+1 种。
// 这算什么类型的题目？


// g, 盲点。。。



// 双指针？ 不， dp。 也不行。
//
int fun1a(int mx, int des);
void fun1__EEEE() {
    int mx, des;
    std::cin>>mx>>des;

    
    
    // std::vector<int> vi(31);
    // int t2 = 0;
    // for (int i = 0; i < 31; ++i) {
    //     // buy [i]
    //     if ((1 << i) > mx) {
    //         continue;
    //     }
    //     t2 = mx - (1 << i);
    //     vi[i] = 1;
    //     for (int j = 0; j < i; ++j) {
            
    //     }
    // }

    int ans = 0;
    for (int i = 0; i < 31; ++i) {
        ans += fun1a(mx, i + 1);
    }
    
    std::cout<<ans<<std::endl;
}

int fun1a(int mx, int des) {
    int i = 0;
    if (des == 0)
        return 1;
    while ((1 << i) <= mx) {
        ++i;
    }
    --i;
    if (i == -1) {
        return 1;
    }

    int ans = 1;
    ans += fun1a(mx - (1 << i), des - 1);

    return ans;
}


// 硬算？是的， 最多30个， choose or not。   /// TLE....
int dfsa1(int ofst, int remain, int des);
void fun1__TLLEEE()
{
    // int sz1, sz2, kk;
    // std::cin >> sz1;

    int mny, des;
    std::cin>>mny>>des;

    int ans = dfsa1(0, mny, des);
    std::cout<<ans<<std::endl;
}

int dfsa1(int ofst, int remain, int des) {
    if (ofst >= des) {
        return 1;
    }
    if (1<<ofst > remain) {
        return 1;
    }
    int ans = 0;
    ans += dfsa1(ofst + 1, remain, des);
    ans += dfsa1(ofst + 1, remain - (1<<ofst), des);
    return ans;
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
