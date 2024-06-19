
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
#include <cmath>
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

#include <iomanip>

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE







// 261974078 	May/21/2024 15:10UTC+8 	Ouha 	1886B - Fear of the Dark 	C++20 (GCC 13-64) 	Accepted 	139 ms 	0 KB


//-1 1
//-1 5
//-4 -1
// 4.1231056256   std::setprecision(10)


// illuminate  light
// (0, 0) to a/b
// a to b
// a/b to home   min
void fun1()
{
    int sz1, sz2, kk;
    // std::cin >> sz1;

    int hx, hy, ax, ay, bx, by;

    std::cin>>hx>>hy>>ax>>ay>>bx>>by;
    
    double ans = 1234567890;

    // now, no sqrt
    // just a
    ans = std::min(ans, 1.0 * std::max(ax * ax + ay * ay, (ax - hx) * (ax - hx) + (ay - hy) * (ay - hy)));

    // just b
    ans = std::min(ans, 1.0 * std::max(bx * bx + by * by, (bx - hx) * (bx - hx) + (by - hy) * (by - hy)));


    // a + b
    ans = std::min(ans, std::max(((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) / 4.0, 1.0 * std::max(std::min(ax * ax + ay * ay, bx * bx + by * by), std::min((hx - ax) * (hx - ax) + (hy - ay) * (hy - ay), (hx - bx) * (hx - bx) + (hy - by) * (hy - by)))));

    #ifdef __test
    std::cout<<ans<<": ";
    #endif
    
    std::cout<<std::setprecision(10)<<std::sqrt(ans)<<std::endl;
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
