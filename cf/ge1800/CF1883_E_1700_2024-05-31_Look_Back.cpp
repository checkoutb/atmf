
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






// AC
// 263433266 	May/31/2024 16:00UTC+8 	Ouha 	1883E - Look Back 	C++20 (GCC 13-64) 	Accepted 	390 ms 	0 KB 

void fun1()
{
    int sz1;
    std::cin>>sz1;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    long long ans = 0; // ...int overflow..
    int pow = 0; // 2 ^ pow
    for (int i = 1; i < sz1; ++i) {
        while (pow > 0 && vi[i - 1] < vi[i]) {
            --pow;
            vi[i - 1] <<= 1;
        }
        long long a = vi[i];
        while (vi[i - 1] > a) {
            a <<= 1;
            ++pow;
        }
        ans += pow;
    }
    std::cout<<ans<<std::endl;
    
    // int ans = 0;
    // std::vector<int> stk;

    // for (int i = sz1 - 2; i >= 0; --i) {
    //     int a {vi[i]}, b {vi[i + 1]};
    //     if (a < b) {
    //         stk.push_back(i);
    //     } else {
            
    //     }
    // }
    
}


// 反向...  2 1 1000  最后一位不需要 * 2
void fun1_ee()
{
    int sz1;
    std::cin>>sz1;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        std::cin>>vi[i];

    int ans = 0;
    int a, b;
    for (int i = sz1 - 2; i >= 0; --i) {
        a = vi[i];
        b = vi[i + 1];
        while (a > b) {
            b <<= 1;
            ans += (sz1 - i - 1);
        }
    }
    std::cout<<ans<<std::endl;
}


// tle ..? 估计溢出了。 en
// 
void fun1__eeee()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    long long t2 = 1LL;
    long long t3 = 1LL;
    int ans = 0;
    for (int i = 0; i < sz1; ++i) {
        t3 = vi[i];
        while (t3 < t2) {
            // t3 <<= 1;
            t3 = t3 * 2;
            ++ans;
            if (t3 < -1) {
                std::cout<<-123<<std::endl;
                return;
            }
        }
        t2 = t3;
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
