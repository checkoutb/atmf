
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
#include <string_view>
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




// 309709733 	Mar/10/2025 14:23UTC+8 	Ouha 	1826D - Running Miles 	C++20 (GCC 13-64) 	Accepted 	108 ms 	4000 KB




// 
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    
    // std::vector<std::pair<int, int>> v2(sz1);
    // int a, b;
    // for (int i = sz1 - 1; i >= 0; --i) {
    //     a = vi[i] + (sz1 - i);
    //     if (i + 1 < sz1 && v2[i + 1].first > a) {
    //         v2[i] = v2[i + 1];
    //     } else {
    //         v2[i].first = a;
    //         v2[i].second = i;
    //     }
    // }

    std::vector<int> v2(sz1);
    v2[sz1 - 1] = vi[sz1 - 1];
    for (int i = sz1 - 2; i >= 0; --i) {
        v2[i] = std::max(vi[i], v2[i + 1] - 1);
    }
    int a = vi[0];
    int ans = 0;
    for (int i = 1; i < sz1 - 1; ++i) {
        ans = std::max(ans, a - 1 + vi[i] + v2[i + 1] - 1);
        a = std::max(a - 1, vi[i]);
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
