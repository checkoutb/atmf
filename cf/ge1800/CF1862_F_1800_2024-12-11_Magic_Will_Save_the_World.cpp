
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
#include <set>
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






// g

        // vector<bool> dp(sum_s + 1);
        // dp[0] = true;
        // for (int i = 0; i < n; ++i) {
        //     for (int w = sum_s; w - s[i] >= 0; --w) {
        //         dp[w] = dp[w] || dp[w - s[i]];
        //     }
        // }
// .. vector<bool>， 从后向前。 6




// tle @ 7， 但想不出其他策略，难道不需要 尝试另一侧？ 第3个用例报错
// 似乎可以换一种方法， 就是 n 只有100， 所以可以尝试所有的 可能？
// 就是 {0} -> {0, vi[0]} -> {0, vi[0], vi[1], vi[0+1]} .不行。 2^100 。。不，数据集好像不大，set以后 会小很多吧？ 而且 100个元素最大 10000，所以 set 中最多 100万个元素。 似乎可以？


// tle @ 11, 使用 set。 三分不三分，无所谓，大头是 for for， 最后一个 for 无所谓的。




// w，f 每秒
// 无限咒语 只要蓝够
// 消耗 si 才可以击败
//
// 就是 怪物分2组，使得 各自的sum 接近但小于 w*ans 和 f*ans ? 不过代码怎么实现？
// ans 可以二分，但是 怎么 分组呢？


void fun1() {
    long long ww, ff;
    int sz1;
    std::cin>>ww>>ff>>sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::sort(std::begin(vi), std::end(vi), [](const int a, const int b){
        return a > b;
    });

    std::set<int> set2;
    set2.insert(0);
    int sum2 = 0;
    for (int i = 0; i < sz1; ++i) {
        int t2 = vi[i];
        sum2 += t2;
        std::set<int> set3;

        for (auto x : set2) {
            set3.insert(x + t2);
        }
        set2.insert(std::begin(set3), std::end(set3));
    }

    int ans = 2000000000;
    if (ww > ff) {
        std::swap(ww, ff);
    }
    for (auto x : set2) { // 感觉应该三分，但是不好写啊。
        int t2 = sum2 - x;
        if (x > t2) {
            std::swap(x, t2);
        }
        t2 = (t2 + ff - 1) / ff; // seconds
        t2 = std::max(1LL * t2, (x + ww - 1) / ww);
        ans = std::min(ans, t2);
    }
    std::cout<<ans<<std::endl;
}




bool cana1(std::vector<int>& vi, long long wwr, long long ffr, int idx);
void fun1__errrrrrr()
{
    int sz1, sz2, kk;

    long long ww,ff;
    std::cin>>ww>>ff;
    
    std::cin >> sz1;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::sort(std::begin(vi), std::end(vi));
    std::reverse(std::begin(vi), std::end(vi));

    int st = 1;
    int en = 1000000;
    int ans = -1;
    long long wwremain, ffremain;
    while (st <= en) {
        int md = (st + en) / 2;

        wwremain = ww * md;
        ffremain = ff * md;

        if (cana1(vi, wwremain, ffremain, 0)) {
            ans = md;
            en = md - 1;;
        } else {
            st = md + 1;
        }
    }
    
    std::cout<<ans<<std::endl;

}

bool cana1(std::vector<int>& vi, long long wwr, long long ffr, int idx) {
    if (wwr < 0 || ffr < 0) {
        return false;
    }
    if (idx == vi.size()) {
        return true;
    }
    if (wwr > ffr) {
        if (cana1(vi, wwr - vi[idx], ffr, idx + 1)
            // || cana1(vi, wwr, ffr - vi[idx], idx + 1)
            )
            return true;
    } else {
        if (cana1(vi, wwr, ffr - vi[idx], idx + 1)
            // || cana1(vi, wwr - vi[idx], ffr, idx + 1)
            )
            return true;
    }
    return false;
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
