
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
#include <numeric>            // accumulate
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





// 295706986 	Dec/09/2024 14:36UTC+8 	Ouha 	1863C - MEX Repetition 	C++20 (GCC 13-64) 	Accepted 	390 ms 	100 KB



// 最小缺失
// 每次赋值前，都要 MEX 整个数组一次。
//
// 0-n, n+1, n, 缺少一个。 第一次op必然是 缺少的，第二次必然是第一次原来的值
// 几次能形成一个 环？
// 013 +2  201
// 201 +3  320
// 320 +1 132
// 013, 201
//
// 02 +1 10 +2 21 +0 02
// 似乎是 n+1次一个循环？ 即 缺2，缺3， 缺的 构成 0-n 就是一个循环。
//
// 换种写法
// 013+2, 201+3, 320+1, 013+2
// 0132, 2013, 3201, 0132, 是 循环右移
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    kk %= (sz1 + 1);

    kk = (sz1 + sz1 - kk + 2) % (sz1 + 1);
    
    long long sum2 = std::accumulate(std::begin(vi), std::end(vi), 0LL);
    long long sum3 = 1LL * (0 + sz1) * (sz1 + 1) / 2;  // .. (0+sz1)/2*(sz1+1) ..
    int loss = static_cast<int>(sum3 - sum2);

    std::vector<int> v2(sz1);
    int idx = kk;

#ifdef __test
    std::cout<<" --  "<<kk<<" .. "<<loss<<std::endl;
#endif
    
    
    for (int i = 0; i < sz1; ++i) {
        //v2[i] = vi[kk];
        //++kk;
        if (kk == sz1) {
            //if (i + 1 < sz1) {
            //++i;
                v2[i] = loss;
                //++i;
                kk = 0;
                //}
                continue;
        }
        v2[i] = vi[kk];
        ++kk;
    }

    for(int i : v2) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
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
