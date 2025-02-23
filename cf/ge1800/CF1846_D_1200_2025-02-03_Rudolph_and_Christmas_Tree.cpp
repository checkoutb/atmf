
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
#include <iomanip>    // std::setprecision(10)
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






// 304250152 	Feb/03/2025 20:49UTC+8 	Ouha 	1846D - Rudolph and Christmas Tree 	C++20 (GCC 13-64) 	Accepted 	140 ms 	0 KB


// 
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    int d, h;
    std::cin>>d>>h;

    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::map<int, int> map2; // <height, count>

    for (size_t i = 1; i < sz1; ++i) {
        int t2 = vi[i] - vi[i - 1];
        if (t2 > h)
            t2 = h;
        ++map2[t2];
    }
    ++map2[h];

    double ans = 0.0;
    for (auto& p : map2) {
        int t2 = p.first;
        ans += 1.0 * p.second * (d + 1.0 * d * (h - t2) / h) * t2 / 2;
    }
    
    std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;
    
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
