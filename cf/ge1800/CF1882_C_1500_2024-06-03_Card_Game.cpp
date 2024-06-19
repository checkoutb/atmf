
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






// 263816923 	Jun/03/2024 11:18UTC+8 	Ouha 	1882C - Card Game 	C++20 (GCC 13-64) 	Accepted 	390 ms 	100 KB 


// top is 0th, no top is 1th
// odd  remove , add  reindex   1,3,5
// even remove, no add, reindex  2,4,6
// ?
// 从后往前，正数，如果是偶数下标，那么累加，如果是奇数下标，那么+ans，并且把累加的也+ans，清零
// -4，1，-3，5 怎么处理？ 只能枚举？ 不过也无所谓， O(n) 速度是够的。
//
// 好烦啊， 下标从1开始的。
// 奇数 no add
// 偶数 add
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    std::vector<long long> v2(sz1);

    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    long long ans = 0;
    long long acc = 0;
    for (int i = sz1 - 1; i >= 0; --i) {
        if (vi[i] >= 0) {
            if (i % 2 == 1) {
                acc += vi[i];
            } else {
                ans += vi[i] + acc;
                acc = 0;
            }
        } else {
            if (i % 2 == 1) {
                ans += acc;
                acc = 0;
            }
        }
        v2[i] = acc;
    }

    long long t2 = 0;
    for (int i = 0; i < sz1; ++i) {
        if (v2[i] == 0)
            break;
        if (i % 2 == 0) {
            t2 = std::max(t2, vi[i] + v2[i]);
        } else {
            t2 = std::max(t2, v2[i] - vi[i]);
        }
    }
    ans += t2;
    
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
