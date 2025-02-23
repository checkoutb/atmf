
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





// g



// -n - n,  + !=0, + > 0
// 要 >0,必然正数越多越好。 不是， exactly 。。。
// n 10^5， 而且 不包含0， 且 任意2个相加，不能等于0
// 如果 b1 < b2, 那么 a1 小于 a2 ？ 充要的？
// a1==a2  <=>  b1==b2 错的， a:[2,2], b:[1,2]
// a1 < a2 <=> b1 < b2 ?  充分非必要，
// max(a)。。 n-max(a) 就是 多少个 < -max(b) 的。 而且 相加不能为0， 所以 max(b) <= n-(n-max(a)) .不，可能 n-max(a) 个 -n， 那么 n-1 就 满足 max(a) 了。
// 而且 -n 对应的 a 必然是0， 所以 a中有n-max(a) 个0。 有且仅有。
// 然后 继续算中间部分。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<std::pair<int, int>> vpii(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vpii.first;
        vpii.second = i;
    }

    std::sort(std::begin(vpii), std::end(vpii));
    std::reverse(std::begin(vpii), std::end(vpii));

    std::vector<int> vi(sz1);

    int mn = -n;
    int mx = n;
    int en = sz1;
    int cntpos = 0; // positive
    bool can = true;
    for (int i = 0; i < en; ++i) {
        if (i > 0 && vpii[i].first == vpii[i - 1].first) {
            vi[i] = vi[i - 1];
            continue;
        }
        if (i > 0 && vi[i - 1] > 0) {
            cntpos = i;
        }
        int t2 = vpii[i].first;  // max(a)
        t2 -= cntpos;
        if (t2 < 0) {
            can = false;
            break;
        }
        if (t2 == 0) {
            vi[i] = -1;
            mx = -2;
            continue;
        }
        vi[i] = mx;
        mx--;
    }


    if (!can) {
        std::cout<<"NO\n";
        return;
    }

    std::cout<<"YES\n";

    // .order
    std::vector<int> v2(sz1);
    for (int i = 0; i < sz1; ++i) {
        v2[vpii[i].second] = vi[i];
    }

    for (int i : v2) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
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
