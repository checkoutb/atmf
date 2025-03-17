
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


// D

    // for(int i = 0; i < n - 2; i++){
    //     a.emplace_back(min(b[i], b[i + 1]));
    // }



// 311028892 	Mar/17/2025 21:06UTC+8 	Ouha 	1811C - Restore the Array 	C++20 (GCC 13-64) 	Accepted 	109 ms 	0 KB


// a a a a a
//  b b b b
// .. b 0 b b b ?... no
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1 - 1);
    for (int i = 1; i < sz1; ++i) {
        std::cin>>vi[i - 1];
    }
    
    std::vector<int> v2(sz1);
    v2[0] = vi[0];
    for (int i = 2; i < sz1; ++i) {
        // v2[i] = vi[i - 1];
        if (vi[i - 1] <= vi[i - 2]) {
            v2[i - 1] = vi[i - 1];
        } else {
            v2[i] = vi[i - 1];
        }
    }
    
    for (int i : v2) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
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
    
    
    for (int _ = 0; _ < w; ++_)
    {
        if (_ == -1)
            fun1(true);
        fun1();
        
        #ifdef __test
        std::cout << "   ---/////--------/////---" << std::endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
