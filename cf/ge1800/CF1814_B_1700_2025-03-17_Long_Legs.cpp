
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




// 311017416 	Mar/17/2025 19:36UTC+8 	Ouha 	1814B - Long Legs 	C++20 (GCC 13-64) 	Accepted 	124 ms 	0 KB




// %2 /2        5: jmp, +1, jmp, jmp    no, 16: +1+1+1,jmp*4
// must first +1, then jmp.   %2^n
// ...似乎是： m必然加到 某个 2的次方。 所以尝试所有的0-30次方。 m每次+1，所以 在+的过程中，把 哪些 bit为1的 jmp下。
// // 5,3 -> 5 ... 不是 2的次方。。  2jmp 3jmp jmp， m最终3 。。。 5是  +1jmp+1jmp  4下。
// 。。。突然感觉应该 2分。。不是二分搜索，是 二分逼近。 抛物线找最低点。   但太麻烦了。 还有，不知道是否光滑。
// m最大应该是 sqrt(sz1.max(sz2)) 硬算？ 可以硬算，就是 。。。 突然发现 如果最终 m是 x 的话，那么 就是 sz1/x + (sz1%x == 0 ? 0 : 1);    sqrt(10^9) = 31623 ..... 8,4 ... not sqrt...
int cala1(int, int);
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2;

    int ans = sz1 + sz2;
    if (sz1 < sz2) {
        int t2 = sz1;
        sz1 = sz2;
        sz2 = t2;
    }
    int cnt = 0;
    for (int i = 1; i <= sz1; ++i) {
        cnt = 0;
        cnt += i - 1;   // m+1
        if (cnt >= ans) {
            break;
        }
        cnt += sz1 / i + (sz1 % i == 0 ? 0 : 1);
        cnt += sz2 / i + (sz2 % i == 0 ? 0 : 1);

        ans = std::min(ans, cnt);
    }

    std::cout<<ans<<std::endl;



    
    
    //int ans = cala1(sz1, sz2);
    
    //std::cout<<ans<<std::endl;
    
    
}

// int cala1(int sz1, int& ans) {  //... sz1 和 sz2 可以一起。。
int cala1(int sz1, int sz2) {
    if (sz1 < sz2) {
        int t4 = sz1;
        sz1 = sz2;
        sz2 = t4;
    }
    // sz1 >= sz2
    // int stp = 1;
    int cnt1 = 0;
    int mncnt = sz1 - 1 + 2; // sz1 - 1 times +1 (m will be sz1), and 2 jmp.
    // int mnidx = 0;
    for (int i = 1; i < 31; ++i) {
        int t2 = 1 << i;
        if (t2 > sz1) {
            break;
        }
        cnt1 += (sz1 & (1 << (i - 1))) == 0 ? 0 : 1;
        cnt1 += (sz2 & (1 << (i - 1))) == 0 ? 0 : 1;

        if (cnt1 + (sz1 / t2) + (sz2 / t2) + t2 - 1 < mncnt) {
            mncnt = cnt1 + (sz1 / t2) + (sz2 / t2) + t2 - 1;
        }
        // int t3 = 0;
        // for (int j = 1;)
    }
    return mncnt;
}



// int cala1(int sz1, int& ans) {
//     int stp = 1;
//     for (int i = 1; i < 31; ++i) {
//         int t2 = 1 << i;
//         if (sz1 % t2) {
//             int t3 = sz1 % t2;
            
            
//             sz1 = sz1 & (sz1 - 1);
//         }
//     }
// }


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
