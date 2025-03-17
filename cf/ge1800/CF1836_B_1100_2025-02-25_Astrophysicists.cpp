
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






// 307663347 	Feb/25/2025 21:05UTC+8 	Ouha 	1836B - Astrophysicists 	C++20 (GCC 13-64) 	Accepted 	61 ms 	0 KB


// k*g
// x mod g >= g/2
// ? 英语是真的难。  似乎就是 除了最后一个人外， 每个人 g/2 -1。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;
    int gg;
    std::cin>>gg;

    long long ans = 0;
    int t2 = (gg + 1) / 2 - 1;
    long long remain = 1LL * gg * kk;

    #ifdef __test
    // std::cout<<remain<<" , "<<t2<<" , "<<sz1<<std::endl;
    #endif
    
    if (remain <= 1LL * t2 * sz1) {
        std::cout<<remain<<std::endl;
        return;
    }
    // for (int i = 1; i < sz1; ++i) {
    //     ans += t2;
    // }
    ans += 1LL * t2 * (sz1 - 1);
    remain = 1LL * kk * gg - 1LL * t2 * (sz1 - 1);

    #ifdef __test
    std::cout<<t2<<", "<<ans<<", "<<remain<<std::endl;
    #endif

    remain %= gg;
    if (remain > t2) {
        ans -= gg - remain;
    } else {
        ans += remain;
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
