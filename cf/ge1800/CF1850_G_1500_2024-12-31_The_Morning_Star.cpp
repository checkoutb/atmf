
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





// 299140380 	Dec/31/2024 15:33UTC+8 	Ouha 	1850G - The Morning Star 	C++20 (GCC 13-64) 	Accepted 	1452 ms 	44800 KB



// 
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<std::vector<int>> vvi(sz1);
    int t2;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        vvi[i].push_back(t2);
        std::cin>>t2;
        vvi[i].push_back(t2);
    }

    // x
    // y
    // ne
    // nw

    std::map<int, int> mpx, mpy, mp45x, mp135x;

    for (int i = 0; i < sz1; ++i) {
        int x = vvi[i][0];
        int y = vvi[i][1];

        ++mpx[x];
        ++mpy[y];
        ++mp45x[x - y];  // (x,y) (x-y, 0), 2 point are NE/SW
        ++mp135x[x+y]; // (x,y) (x+y, 0)
    }

    long long ans = 0LL;

    for (auto& [_k, v] : mpx) {
        ans += 1LL * v * (v - 1) / 2;
    }
    for (auto& [_, v] : mpy)
        ans += 1LL * v * (v - 1) / 2;
    for (auto& [_, v] : mp45x)
        ans += 1LL * v * (v - 1) / 2;
    for (auto& [_, v] : mp135x)
        ans += 1LL * v * (v - 1) / 2;
    
    std::cout<<(ans << 1)<<std::endl;
    
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
