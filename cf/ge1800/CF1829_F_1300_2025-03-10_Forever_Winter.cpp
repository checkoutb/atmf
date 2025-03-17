
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






// 309704927 	Mar/10/2025 13:20UTC+8 	Ouha 	1829F - Forever Winter 	C++20 (GCC 13-64) 	Accepted 	124 ms 	4000 KB


// 
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1; // cnt node 
    std::cin>>sz2; // edge

    std::vector<std::vector<int>> vvi(sz1);
    int a, b;
    for (int i = 0; i < sz2; ++i) {
        std::cin>>a>>b;
        --a, --b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }
    
    std::map<int, int> map2;
    
    for (int i = 0; i < sz1; ++i) {
        if (vvi[i].size() == 1)
            continue;
        map2[vvi[i].size()]++;
    }
    a = -1, b = -1;
    for (auto& [k, v] : map2) {
        if (v == 1) {
            a = k;
        } else {
            b = k;
        }
    }
    std::cout<<(a == -1 ? b : a)<<' '<<(b - 1)<<std::endl;
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
