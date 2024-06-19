
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





// 263814333 	Jun/03/2024 10:29UTC+8 	Ouha 	1883C - Raspberries 	C++20 (GCC 13-64) 	Accepted 	140 ms 	0 KB



// +1,  product / k
// if there is a (k-1), need one operation
// or k is 6, [2,2] need one op
// k <= 5,  2,3,5 is prime,    4=2*2,   2<=n,  no 1. 
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::cin>>kk;

    //std::vector<int> vi(sz1);
    std::vector<int> vi(kk);
    int t2;
    for (int i = 0; i < sz1; ++i) {
        //std::cin>>vi[i];
        std::cin>>t2;
        ++vi[t2 % kk];
    }

    if (vi[0] != 0)
        std::cout<<0<<'\n';
    else if (kk != 4) {
        for (int i = kk - 1; i > 0; --i) {
            if (vi[i] != 0) {
                std::cout<<(kk - i)<<'\n';
                break;
            }
        }
    }
    else {
        // kk = 4
        if (vi[2] > 1) {
            std::cout<<0<<'\n';
        } else if (vi[3] > 0) {
            std::cout<<1<<'\n';
        } else if (vi[2] > 0) {
            if (vi[1] > 0)
                std::cout<<1<<'\n';
            else
                std::cout<<2<<'\n';
        } else if (vi[1] > 1){
            std::cout<<2<<'\n';
        } else {
            std::cout<<3<<'\n';
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
