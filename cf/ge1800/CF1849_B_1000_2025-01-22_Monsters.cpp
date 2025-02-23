
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



// 加上 sync_with_stdio, tie, tie 后，直接减少了500ms。。。看来必须了。
// 302354260 	Jan/22/2025 18:54UTC+8 	Ouha 	1849B - Monsters 	C++20 (GCC 13-64) 	Accepted 	140 ms 	100 KB

// 302353903 	Jan/22/2025 18:51UTC+8 	Ouha 	1849B - Monsters 	C++20 (GCC 13-64) 	Accepted 	656 ms 	100 KB 


// Test#4, tle, 无法理解 为什么tle。 我去，kk<10^9， 我记得之前看过 是 10^3 。。

// k damage to highest health.   small index first
// the order of die
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;
    std::vector<int> vi(sz1);

    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<std::pair<int, int>> vpii(sz1);
    for (int i = 0; i < sz1; ++i) {
        // 0 > 9 > 8 > 7...
        if (vi[i] % kk == 0)
            vpii[i].first = kk;
        else 
            vpii[i].first = vi[i] % kk;
        vpii[i].second = i + 1;
    }

    std::sort(std::begin(vpii), std::end(vpii), [](const std::pair<int, int>& p1, const std::pair<int, int>& p2){
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        } else {
            return p1.first > p2.first;
        }
    });

    for (std::pair<int, int>& p : vpii) {
        std::cout<<p.second<<' ';
    }
    
    
    // std::vector<std::vector<int>> vvi(kk);

    // for (int i = 0; i < sz1; ++i) {
    //     vvi[vi[i]].push_back(i + 1);
    // }

    // for (size_t j = 0; j < vvi[0].size(); ++j) {
    //     std::cout<<(vvi[0][j])<<' ';
    // }
    // for (int i = kk - 1; i > 0; --i) {
    //     for (size_t j = 0; j < vvi[i].size(); ++j) {
    //         std::cout<<(vvi[i][j])<<' ';
    //     }
    // }
    
    std::cout<<std::endl;
}


int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
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
