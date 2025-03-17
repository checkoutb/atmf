
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






// 310561037 	Mar/14/2025 20:29UTC+8 	Ouha 	1820B - JoJo's Incredible Adventures 	C++20 (GCC 13-64) 	Accepted 	62 ms 	0 KB


// 最长连续1，的长度 / 2
void fun1(bool show = false)
{
    int sz1, sz2, kk;
        
    std::string str;
    std::cin>>str;
    sz1 = str.size();

    int mx = 0;
    int t2 = 0;
    for (int i = sz1 - 1; i >= 0; --i) {
        if (str[i] == '1') {
            t2++;
        } else {
            break;
        }
    }
    if (t2 == sz1) {
        mx = t2;
        t2 = 0;
        std::cout<<(1LL * mx * mx)<<std::endl;   // ...
        return;
    }
    for (int i = 0; i < sz1; ++i) {
        if (str[i] == '1') {
            t2++;
        } else {
            mx = std::max(t2, mx);
            t2 = 0;
        }
    }

    mx = std::max(t2, mx);

    // long long ans = mx >> 1;
    // ans *= (mx - (mx >> 1));

    // x+1 * mx-x  x = mx-1 / 2

    long long ans = (mx - 1) / 2;
    ans = 1LL * (ans + 1) * (mx - ans);
    


    
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
    
    
    for (int _ = 0; _ < w; ++_)
    {
        if (_ == -1)
            fun1(true);
        fun1();
        
        #ifdef __test
        std::cout << "   ---/////--------/////---" << std::endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
