
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





// the cycle in each component has a size exactly k
// ..每个连通分量 都要 有一个 ==k的环。。。

// error, g


// distinct,  <<
// kk 是 l 的长度
// 下标为 l[x] 的 值变为 l[x+1]  循环
// 如果值是 l[x+1]， l[x] 的值 是 x
// 11111
// b 直接 >>. 每个位置尝试，肯定tle。 不行的， 或者要3个方向，头开始尾结束，尾开始头结束，头尾开始中间结束。
// 23134  231645
// b[0]必然是2. kk=1不算  。。 好像不是。
// a[l[x]] = l[x+1]
// 2 3 5 3 4
// a[1] = 2, a[2] = 3, a[3] = 5, a[4] = 3, a[5] = 4
// 不是 << 。
// 似乎是： 能否找到 k 个位置，使得 它们的 下标组成的集合  == 值组成的集合 ？ 这k个位置就是最后一次操作。 之前的操作 无所谓的， 不是，k=1, 123156. k=1时 b必须1,2,3..
// distinct， 不能 b[x] = x  k==1除外
// >=k 的环, ==k
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    if (kk == 1) {
        for (int i = 0; i < sz1; ++i) {
            if (vi[i] != i + 1) {
                std::cout<<"no\n";
                return;
            }
        }
        std::cout<<"yes\n";
        return;
    }

    std::vector<bool> vst(sz1);

    for (int i = 0; i < sz1; ++i) {
        if (vst[i])
            continue;

        std::vector<int> v2(sz1);
        int stp = 1;
        int nxt = i;

        while (true) {
            vst[nxt] = true;
            if (v2[nxt] != 0) {
                // circle
                if (stp - v2[nxt] == kk) {
                    std::cout<<"yes\n";
                    return;
                }
                break;
            }
            v2[nxt] = stp;
            ++stp;
            nxt = vi[nxt] - 1;
        }
    }

    std::cout<<"no\n";
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
