
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





// 306035493 	Feb/14/2025 13:55UTC+8 	Ouha 	1842B - Tenzing and Books 	C++20 (GCC 13-64) 	Accepted 	93 ms 	100 KB



// 3n book   3 stack
// 难度
// read stack's top and throw it
// a|b  bit or
// x
// 3个stack 取top的 几本书，然后 bit or 能不能 变成 x
// 似乎很简单，因为 | 的存在，所以 每个stack 直接读， 直到 | 以后， a|x != a，那么这本书 回滚。 结束这个 stack
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::cin>>kk;   // x
    
    std::vector<int> v1(sz1);  // 可以不需要，直接处理。
    std::vector<int> v2(sz1);
    std::vector<int> v3(sz1);

    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>v1[i];
    }
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>v2[i];
    }
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>v3[i];
    }

    int know = 0;
    for (size_t i = 0; i < sz1; ++i) {
        if ((v1[i] | kk) != kk) {
            break;
        }
        know |= v1[i];
    }

    for (size_t i = 0; i < sz1; ++i) {
        if ((v2[i] | kk) != kk) {
            break;
        }
        know |= v2[i];
    }

    for (size_t i = 0; i < sz1; ++i) {
        if ((v3[i] | kk) != kk)
            break;
        know |= v3[i];
    }

    if (know == kk)
        std::cout<<"yes\n";
    else
        std::cout<<"no\n";
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
