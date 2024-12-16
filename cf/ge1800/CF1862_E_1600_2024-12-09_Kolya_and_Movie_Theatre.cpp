
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
#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
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





// 295711266 	Dec/09/2024 15:19UTC+8 	Ouha 	1862E - Kolya and Movie Theatre 	C++20 (GCC 13-64) 	Accepted 	406 ms 	0 KB




// ai 娱乐值
// 不去的话，下场的娱乐值会下降 d*cnt。 昨天看了，今天再去，cnt是1.， 开业前一天也看了。
// 最多k次，最大化 娱乐值。
// 可能为负数， 不看为0
//
// maxk. 以当前为观看的最后一部，无论前面怎么看，减去的 d*cnt 是相同的。 所以选前面 >0 的最大的 m部看。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    int mxMv, down;
    std::cin>>mxMv>>down;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::priority_queue<int> priq;
    long long ans = 0LL;
    long long sumPriq = 0LL;
    long long t2 = 0LL;
    
    for (int i = 0; i < sz1; ++i) {
        if (vi[i] <= 0) {
            continue;
        }

        priq.push(-vi[i]);
        sumPriq += vi[i];
        
        if (priq.size() > mxMv) {
            sumPriq += priq.top();
            priq.pop();
        }

        t2 = sumPriq - 1LL * (i + 1) * down;
        ans = std::max(ans, t2);
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
