
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







// AC了， 但是我还是不懂 英语。
// 263418256 	May/31/2024 14:01UTC+8 	Ouha 	1883G1 - Dances (Easy version) 	C++20 (GCC 13-64) 	Accepted 	374 ms 	0 KB 

// ..完全看不懂题目啊。。
// a < b
// 感觉是 [1, a1, a2, ...]  [b1, b2, b3 ...]
// hard 就是 a的第一个数字 从1-m
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin >> kk;

    std::vector<int> va(sz1);
    std::vector<int> vb(sz1);
    va[0] = 1;
    for (int i = 1; i < sz1; ++i) {
        std::cin>>va[i];
    }
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vb[i];
    }

    std::sort(std::begin(va), std::end(va));
    std::sort(std::begin(vb), std::end(vb));

    #ifdef __test
    for (int i : va) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
    for (int i : vb) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    #endif
    
    int ans = 0;

    int idxb = 0;
    for (int i = 0; i < sz1; ++i) {
        while (idxb < sz1 && vb[idxb] <= va[i]) {
            ++idxb;
        }

        #ifdef __test
        std::cout<<i<<", "<<idxb<<std::endl;
        #endif
        
        if (idxb >= sz1) {
            ans = sz1 - i;
            break;
        }
        idxb++;
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
