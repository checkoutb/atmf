
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




// 注释 sync_with_stdio后 280ms

// 302360212 	Jan/22/2025 19:46UTC+8 	Ouha 	1848B - Vika and the Bridge 	C++20 (GCC 13-64) 	Accepted 	124 ms 	5900 KB 


// 可以重涂一块木板，然后 只选择一个颜色，只走这个颜色的模板， 最多跨了几个木板， 要把这个跨的木板数 降最低
// 找到各个color的 最小的 跨木板数， 次小的， 然后把 最小的 一分为二， 然后 max下， 最后 min
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk; // color cnt

    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<int> vkk(kk + 1, -1);  // last appear's index

    std::vector<std::vector<int>> vvi(kk + 1, std::vector<int>(2, -1));

    int clr, skp;
    for (size_t i = 0; i < sz1; ++i) {
        clr = vi[i];
        skp = i - vkk[clr] - 1;
        if (skp >= vvi[clr][0]) {
            vvi[clr][1] = vvi[clr][0];
            vvi[clr][0] = skp;
        } else if (skp > vvi[clr][1])
            vvi[clr][1] = skp;

        vkk[clr] = i;
    }

    int ans = sz1;
    int t2;
    for (int i = 1; i <= kk; ++i) { // @sz1
        skp = sz1 - vkk[i] - 1;
        if (skp >= vvi[i][0]) {
            vvi[i][1] = vvi[i][0];
            vvi[i][0] = skp;
        } else if (skp > vvi[i][1])
            vvi[i][1] = skp;

        t2 = vvi[i][0] / 2;
        t2 = std::max(t2, vvi[i][1]);
        ans = std::min(ans, t2);

        #ifdef __test
        // std::cout<<i<<", "<<vvi[i][0]<<", "<<vvi[i][1]<<",,, "<<t2<<", "<<ans<<std::endl;
        #endif
        
    }

    std::cout<<ans<<std::endl;
    
}


int main()
{

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);

    
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
