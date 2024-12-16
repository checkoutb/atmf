
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
#include <utility>  // pair (include by other header)

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE





// 292706507 	Nov/22/2024 12:34UTC+8 	Ouha 	1870D - Prefix Purchase 	C++20 (GCC 13-64) 	Accepted 	437 ms 	100 KB



// 单调升。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    std::cin>>kk;
    
    std::vector<std::pair<int, int>> stk; // <vi[i], i>
    for (int i = 0; i < sz1; ++i) {
        while (!stk.empty() && stk.back().first >= vi[i]) {
            stk.pop_back();
        }
        stk.push_back(std::make_pair(vi[i], i));
    }

    std::vector<int> v2;
    int lst = 0;
    for (int i = 0; i < stk.size(); ++i) {
        int t2 = stk[i].first - lst;
        if (kk < t2) {
            break;
        }
        int t3 = kk / t2;
        if (!v2.empty()) {
            t3 = std::min(t3, v2.back());
        }
        v2.push_back(t3);
        kk -= t3 * t2;
        lst = stk[i].first;
    }

    // int cnt = 0;
    int idx = 0;
    for (int i = 0; i < v2.size(); ++i) {
        int t2 = stk[i].second;
        int t3 = v2[i];
        while (idx <= t2) {
            std::cout<<t3<<' ';
            ++idx;
        }
    }

    while (idx < vi.size()) {
        std::cout<<0<<' ';
        ++idx;
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
