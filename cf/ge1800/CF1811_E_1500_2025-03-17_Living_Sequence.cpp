
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


// D D

        // while(k > 0) {
        //     digits.push_back(k % 9);
        //     k /= 9;
        // }
// reverse.   for-each digits  if >= 4, ++ 


// 311025229 	Mar/17/2025 20:38UTC+8 	Ouha 	1811E - Living Sequence 	C++20 (GCC 13-64) 	Accepted 	77 ms 	100 KB
// 写出来了，但是还是很模糊，跑了n次 Example




// ???
// <= 9    8   ..  no zero.
// <= 99   8 + {1,2,3,5,6,7,8,9} * 8 = 8 + 8*8 = 72 ... 4,14,24,34,54,64,74,84,94,4X   19
//       (10-1-1) + 8 * 9 = 80           99-19=80
// <= 999
// ...绕来绕去，绕不出来了。 错了，而且错的很大。   看我 万能二分, buyong, gaowei -> diwei

void fun1(bool show = false) {
    long long kk;
    std::cin>>kk;

    std::vector<long long> vl(14);
    vl[0] = 9;      // <<<<<<<< start from 0
    for (int i = 1; i < vl.size(); ++i) {
        vl[i] = (vl[i - 1]) * 8 + vl[i - 1];
    }

    long long ans = 0;
    for (int i = vl.size() - 1; i >= 0; --i) {
        int t2 = kk / vl[i];
        if (t2 >= 4) {
            ++t2;
        }
        ans += t2;
        kk %= vl[i];
        ans *= 10;
    }

#ifdef __test
    std::cout<<"   "<<kk<<std::endl;
#endif
    if (kk >= 4) {
        kk++;
    }
    ans += kk;
    std::cout<<ans<<std::endl;
}


void fun1___EError(bool show = false)
{
    int sz1, sz2, kk;
    // std::cin >> sz1;

    long long kkl;
    std::cin>>kkl;

    // 8,80,728,6560,59048,531440,4782968,43046720,387420488,3486784400,31381059608,282429536480,2541865828328,22876792454960,
    std::vector<long long> vl(14);
    vl[0] = 8;
    for (int i = 1; i < vl.size(); ++i) {
        vl[i] = (vl[i - 1] + 1) * 8 + vl[i - 1];
    }

    long long ans = 0;

    for (int i = vl.size() - 1; i >= 0; --i) {
        ans *= 10;
        if (vl[i] < kkl) {
            ans += kkl / vl[i];
            kkl %= vl[i];
        }
    }
#ifdef __test
    // for (long long ll : vl) {
    //     std::cout<<ll<<',';
    // }
    // std::cout<<std::endl;
#endif
    ans *= 10;
    ans += kkl + (kkl > 3 ? 1 : 0);
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
