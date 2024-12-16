
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
#include <map>
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





// 295169326 	Dec/06/2024 12:43UTC+8 	Ouha 	1866B - Battling with Numbers 	C++20 (GCC 13-64) 	Accepted 	749 ms 	4300 KB



// lcm(a,b) = x, gcd(a,b) = y
// x*y == a*b
// 2^5 * 2^3 = 2^8
// gcd,
// 似乎没有提到 x > y
// 最大公约数， 所以是 a,b 的 共同部分。 现在 gcd=y，说明 a,b 共同的因子 是y，
// a*b=x*y   x*y的因子 减去 2倍y的因子,就是不同部分， 拿了就得拿完。
// 直接 x-y 就是 不同部分的因子， 这些因子的种类 进行 2^n ( 就是 a取或不取 这个种类)
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    int t2 = 0;
    std::map<int, int> map2;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        map2[vi[i]] = t2;
    }

    std::cin>>sz1;
    vi = std::vector<int>(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        map2[vi[i]] -= t2;
    }

    long long cnt = 0;
    bool lt0 = false;
    for (const auto& [k, v] : map2) {
        if (v > 0) {  // < 0? .. example 3
            ++cnt;
        } else if (v < 0) {
            lt0 = true;
        }
    }
    if (lt0) {
        std::cout<<0<<std::endl;
        return;
    }

    const long long MOD = 998244353LL;
    long long ans = 1LL;
    t2 = 2;

    if (cnt == 0) {
        std::cout<<"1\n";
        return;
    }
    
    while (cnt > 0) {
        if (cnt & 1) {
            ans = (ans * t2) % MOD;
        }
        cnt >>= 1;
        t2 = (1LL * t2 * t2) % MOD;  // ...
    }
    
    std::cout<<ans<<std::endl;
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    // std::cin>>w;
    
    
    
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
