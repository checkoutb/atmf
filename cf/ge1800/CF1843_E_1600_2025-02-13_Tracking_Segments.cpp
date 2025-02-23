
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




// 305945952 	Feb/13/2025 21:09UTC+8 	Ouha 	1843E - Tracking Segments 	C++20 (GCC 13-64) 	Accepted 	108 ms 	100 KB 




// 似乎可以二分啊， 每次是 O(n)的设置bit， O(n)的前缀数组， O(n)的计算segment是否美丽。 最终 O(nlogn)
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;   // vb.size  all 0
    std::cin>>sz2;   // segment count
    
    std::vector<std::pair<int, int>> vp(sz2);
    for (size_t i = 0; i < sz2; ++i) {
        int a, b;
        std::cin>>a>>b;
        --a, --b;
        vp[i].first = a;
        vp[i].second = b;
    }

    int sz3;
    std::cin>>sz3;  // op set bit 1

    std::vector<int> vi(sz3);
    for (size_t i = 0; i < sz3; ++i) {
        int a;
        std::cin>>a;
        vi[i] = a - 1;
    }

    int st = 0, en = sz3 - 1;  // <=
    int ans = -1;
    while (st <= en) {
        int md = (st + en) / 2;

        std::vector<int> v2(sz1);

        for (int i = 0; i <= md; ++i) {
            v2[vi[i]] = 1;
        }

        for (int i = 1; i < sz1; ++i) {
            v2[i] += v2[i - 1];
        }

        bool can = false;
        for (int i = 0; i < sz2; ++i) {
            int t2 = v2[vp[i].second] - (vp[i].first == 0 ? 0 : v2[vp[i].first - 1]);
            if (t2 > (vp[i].second - vp[i].first + 1 - t2)) {
                can = true;
                break;
            }
        }

        if (can) {
            ans = md;
            en = md - 1;
        } else {
            st = md + 1;
        }
    }
    if (ans != -1)
        ++ans;
    
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
