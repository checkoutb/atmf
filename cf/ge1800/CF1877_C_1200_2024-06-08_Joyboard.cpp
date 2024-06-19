
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









// 264681834 	Jun/08/2024 14:13UTC+8 	Ouha 	1877C - Joyboard 	C++20 (GCC 13-64) 	Accepted 	155 ms 	0 KB


// 1 n+1
// k distinct
// 0 % x = 0
// how many valid way
// n array size 1, m init value, k distinct
// ?
// %1, %2 %3 %4 %5 ... %n init    k distinct
// ai = ai+1 % i
// 1 0,1,1,1,1,...1
// 2 0,0,2,2,2,2,2,
// 3 0,0,0,3,3,3,3
// n-1 0,0,0,...0,0,n-1,n-1
// n 0,0,...0,0,n
// n+1  0,1,1,1,...,1,n+1
// n+2  0,0,2,2,2,..2,2,n+2
// n+3  0,0,0,3,3,3,..3,3,n+3
//
// max 3 distinct,  0,0...,0,x,x...,x,x+n*y   init val is x+n*y
// 0 - m
void fun1()
{
    //int sz1, sz2, kk;
    //std::cin >> sz1;
    int n,m,k;
    std::cin>>n>>m>>k;

    if (k > 3) {
        std::cout<<0<<'\n';
        return;
    } else if (k == 1) {
        std::cout<<1<<'\n';  // init: 0
        return;
    } else if (k == 2) {
        if (m == 0) {
            std::cout<<0<<'\n';
            return;
        }
        // 1 - n
        // n*x    0,0,0...0,0,0,n*x
        if (m >= n) {
            std::cout<<(n + m / n - 1)<<'\n';
        } else {
            std::cout<<m<<'\n';
        }
    } else {
        // k=3
        // n+1 ... 
        if (m <= n) {
            std::cout<<"0\n";
        } else {
            // n + 1    not n+n
            // 
            std::cout<<(m - n - (m / n) + 1)<<'\n';
        }
    }

    
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
