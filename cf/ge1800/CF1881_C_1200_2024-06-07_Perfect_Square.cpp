
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
//#include <limits.h>   // INT_MAX

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


//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE







// 264566258 	Jun/07/2024 16:40UTC+8 	Ouha 	1881C - Perfect Square 	C++20 (GCC 13-64) 	Accepted 	125 ms 	0 KB 


// 顺时针 90
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<std::string> vs(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vs[i];
    }

    int ans = 0;
    int sum2 = 0, mx = 0;
    for (int i = sz1 / 2 - 1; i >= 0; --i) {
        for (int j = sz1 / 2 - 1; j >= 0; --j) {
            sum2 = mx = vs[i][j] - 'a';
            sum2 += vs[j][sz1 - 1 - i] - 'a';
            mx = std::max(int(vs[j][sz1 - 1 - i]) - 'a', mx);
            sum2 += vs[sz1 - 1 - i][sz1 - 1 - j] - 'a';
            mx = std::max(int(vs[sz1 - 1 - i][sz1 - 1 - j] - 'a'), mx);
            sum2 += vs[sz1 - 1 - j][i] - 'a';
            mx = std::max(int(vs[sz1 - 1 - j][i] - 'a'), mx);
            ans += mx * 4 - sum2;
        }
        
    }
    
    
    std::cout<<ans<<'\n';
    
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
