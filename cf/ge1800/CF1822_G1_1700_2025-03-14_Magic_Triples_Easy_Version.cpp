
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
#include <map>
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

        // for (int i = 0; i < n; ++i) {
        //     ans += (cnt[a[i]] - 1) * (cnt[a[i]] - 2);
        //     for (int b = 2; a[i] * b * b <= MAX_VAL; ++b) {
        //         ans += cnt[a[i] * b] * cnt[a[i] * b * b];
        //     }
        // }
// cnt 是一个100w长度的数组





// 310530201 	Mar/14/2025 16:34UTC+8 	Ouha 	1822G1 - Magic Triples (Easy Version) 	C++20 (GCC 13-64) 	Accepted 	562 ms 	6600 KB
// 竟然没有tle。 因为元素个数最大是 20w， 如果元素都是唯一的，那么 map就有 20w个元素，每个元素1000次尝试， 这是 2亿啊。




// 感觉 tle
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::map<int, int> mp2;
    int t2;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        ++mp2[t2];
    }

    long long ans = 0LL;

    for (std::map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++) {
        int num = it->first;
        int cnt = it->second;
        ans += 1LL * cnt * (cnt - 1) * (cnt - 2);
        for (int i = 2; i <= 1000 && i <= num; ++i) {
            if (num % i) {
                continue;
            }
            t2 = num * i;
            if (t2 > 1000000) {
                break;
            }
            if (mp2.contains(t2) && mp2.contains(num / i)) {
                // long long t3 = 1LL * cnt * mp2[t2];
                ans += 1LL * cnt * mp2[t2] * mp2[num / i];
            }
        }
    }
    
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
