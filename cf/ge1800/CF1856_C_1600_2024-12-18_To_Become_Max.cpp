
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



// 297074975 	Dec/18/2024 16:43UTC+8 	Ouha 	1856C - To Become Max 	C++20 (GCC 13-64) 	Accepted 	78 ms 	100 KB

// g 之后，hint之前，想到过二分，但是 感觉会tle。。



// g // hint: binary search  .. 硬算吗？

bool cana1(std::vector<int>& vi, int mx, int kk);

void fun1() {
    int sz1, kk;
    std::cin>>sz1>>kk;

    std::vector<int> vi(sz1);
    int ans = -1;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
        ans = std::max(ans, vi[i]);
    }

    int st = 0;
    int en = ans + sz1;
    while (st <= en) {
        int md = (st + en) / 2;
        #ifdef __test
        // std::cout<<md<<", ";
        #endif
        if (cana1(vi, md, kk)) {
            ans = std::max(ans, md);
            st = md + 1;
        } else {
            en = md - 1;
        }
    }

    std::cout<<ans<<std::endl;
}

bool cana1(std::vector<int>& vi, int mx, int kk) {
    for (int i = 0; i < vi.size(); ++i) {
        int used = 0;
        int mx2 = mx;
        for (int j = i; j < vi.size() && used <= kk; ++j) {
            if (vi[j] >= mx2) {
                return true;
            }
            used += mx2 - vi[j];
            --mx2;
        }
    }
    return false;
}

// 5 6
// 6 5 4 1 5  ->  7 6 5 4 5  ............


// 选择 非降的2个相邻元素， 第一个元素+1    最多k次
// 求 数组中的 最大值
//
// 45度 投影，被覆盖的 完全不需要考虑
// 1,2,3,4,5
void fun1__error()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    int ans = -1;
    int mx = 0;
    int cnt, tar;
    for (int i = 0; i < sz1; ++i) {
        --mx;
        if (vi[i] <= mx)
            continue;
        mx = vi[i];

        cnt = 0;
        tar = vi[i];
        for (int j = i; j >= 0 && (cnt + tar - vi[j]) <= kk; --j) {
            cnt += tar - vi[j];
            ++tar;
        }
        ans = std::max(tar - 1, ans);
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
