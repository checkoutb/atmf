
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
#include <cmath>
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
#define __test_
#endif // ONLINE_JUDGE





// 296249394 	Dec/13/2024 15:26UTC+8 	Ouha 	1857F - Sum and Product 	C++20 (GCC 13-64) 	Accepted 	1827 ms 	6600 KB



// ai + aj = x, ai*aj = y
// count
// 只会硬算。但是肯定tle， 预先计算 ai+aj 也是tle。 因为 forfor 2*10^5
// (a+b)^2 = a2 + 2ab + b2
// x2 - 2y = a2 + b2  但 好像还是没用啊， 还是得 计算 a2 + b2
// 
// a + b = x, a*b = y
// a*(a+b) = x*y
// 
// a2 + ab = x*y
// a2 + b2 = x2 - 2y
// 就是 二元二次 方程组。

// a+b = x, ab = y 
// a+(y/a) = x     a!=0
// a2 - xa + y = 0   // !!!   ( x +- sqrt(x^2 - 4y) ) / 2
// 二元一次方程组 转 一元二次方程。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::map<int, int> map2;
    int t2 = 0;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        ++map2[t2];
    }

    std::cin>>sz2; // query
    long long x, y, t3, t4, t5;
    for (int i = 0; i < sz2; ++i) {
        std::cin>>x>>y;
        t3 = x*x - 4*y;
        if (t3 < 0LL) {
            std::cout<<"0 ";
            continue;
        }
        t4 = std::sqrt(t3);
        if (t4 * t4 != t3) {
            std::cout<<"0 ";
            continue;
        }
        t3 = x + t4;
        t5 = -123123123123LL;
        long long ans = 0LL;
        if (t3 % 2 == 0) {
            t3 = t3 / 2;
            t5 = x - t3;
            if (map2.contains(t3) && map2.contains(t5)) {
                if (t3 == t5) {
                    t3 = map2[t3];
                    // 1+2+.. (t3-1)
                    ans += (1 + t3 - 1) * (t3 - 1) / 2;
                } else {
                    ans += 1LL * map2[t3] * map2[t5];
                }

                #ifdef __test
                std::cout<<"bbbbb  "<<t3<<", "<<t5<<" +"<<x<<", *"<<y<<" .. "<<map2[t3]<<", "<<map2[t5]<<std::endl;

                #endif
            }
        }
        t3 = x - t4;
        if (t4 != 0 && t3 % 2 == 0 && (t3 / 2) != t5) {
            t3 = t3 / 2;
            t5 = x - t3;
            if (map2.contains(t3) && map2.contains(t5)) {
                if (t3 == t5) {
                    t3 = map2[t3];
                    ans += (t3 - 1) * t3 / 2;
                } else {
                    ans += 1LL * map2[t3] * map2[t5];
                }
                #ifdef __test
                std::cout<<"zzzzzz "<<t3<<", "<<t5<<" +"<<x<<", *"<<y<<" .. "<<map2[t3]<<", "<<map2[t5]<<std::endl;

                #endif
            }
        }

        #ifdef __test
        std::cout<<" --- ans: ";
        #endif
        std::cout<<ans<<" ";
    }
    std::cout<<std::endl;
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
