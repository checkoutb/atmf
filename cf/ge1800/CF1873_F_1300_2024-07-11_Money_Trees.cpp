
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






// 269822150 	Jul/11/2024 12:59UTC+8 	Ouha 	1873F - Money Trees 	C++20 (GCC 13-64) 	Accepted 	546 ms 	100 KB 


// subarray, hi % hi+1 == 0
// > k, will be catch
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    std::vector<int> hi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>hi[i];
    }

    int ans = 0;
    int en = 0;
    long long got = 0LL;
    for (int i = 0; i < sz1; ++i) {
        if (en < i) {
            en = i;
            got = 0;
        }
        while (en < sz1 && (got + vi[en]) <= kk && (en == i || (hi[en - 1] % hi[en] == 0))) {
            got += vi[en];
            ++en;
        }

        ans = std::max(ans, en - i);
        
        got -= vi[i];
    }
    
    std::cout<<ans<<std::endl;
    
    
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
