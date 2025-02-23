
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






// 304242872 	Feb/03/2025 19:53UTC+8 	Ouha 	1846E1 - Rudolf and Snowflakes (simple version) 	C++20 (GCC 13-64) 	Accepted 	155 ms 	100 KB


// 13, 1-3-9
// 15, 1-2-4-8
// 255,   ... ... 1-2-4-...  256
//
// 1 - x - x^2 - x^3 - x^4 ...
//
// 1+x+x2+x3+x4  这种没有通项公式吧？ 。。。。 等比数列。。
// (1 - q^n) / (1-q)  找到整数 q 和n，使得 公式的值 == kk。 而且 n>=3
// 只能硬算啊。
//
// 10101, 1-100-10000
void fun1()
{
    long long kk;
    std::cin>>kk;
    
    for (long long i = 2; i < kk; ++i) {
        int t2 = kk * (i - 1) + 1;
        int cnt = 0;
        while (t2 != 1 && (t2 % i == 0)) {
            cnt++;
            t2 /= i;
        }
        #ifdef __test
        //std::cout<<i<<", "<<t2<<std::endl;
        #endif
        if (t2 == 1 && cnt >= 3) {
            std::cout<<"yes\n";
            return;
        }
        if (i * (1 + i) > kk)
            break;
    }
    
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
