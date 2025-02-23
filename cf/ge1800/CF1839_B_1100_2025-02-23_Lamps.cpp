
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






// 307399729 	Feb/23/2025 19:13UTC+8 	Ouha 	1839B - Lamps 	C++20 (GCC 13-64) 	Accepted 	124 ms 	100 KB


// 不太清楚， 点亮了， 然后被 打破了， 那么 还会算到 x 中？ 不算。 但是 如果 ai 都很大的话， x 会慢慢变大的。
// 肯定 从 最小的 ai 开始。 相同ai， bi降序。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    // std::vector<int> vi(sz1);  // a
    // std::vector<int> v2(sz1);  // b
    // std::vector<bool> vb(sz1);  // turn on?
    // int x = 0;

    std::vector<std::pair<int, int>> vp(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vp[i].first;
        std::cin>>vp[i].second;
        vp[i].second = -vp[i].second;
    }

    std::sort(std::begin(vp), std::end(vp));
    int cnt_on = 0;
    int mx_cnt_on = 0;
    ll ans = 0LL;
    std::vector<bool> vb(sz1);  // tuned on?
    int vbi = 0;
    for (int i = 0; i < sz1; ++i) {
        if (vp[i].first <= mx_cnt_on)
            continue;

        // tuen on i
        ans += vp[i].second;
        vb[i] = true;
        ++cnt_on;
        mx_cnt_on = std::max(mx_cnt_on, cnt_on);
        
        while (vbi <= i && vp[vbi].first <= mx_cnt_on) {  // break
            if (vb[vbi]) {  // turn on -> break
                --cnt_on;
            }
            ++vbi;
        }
    }

    std::cout<<-ans<<std::endl;
    
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
