
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
#include <unordered_set>
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

// D

// ...由于每次变动 都是 +1 或-1， 所以 subpath的 sum 构成了 [min, max] 的全集。
// 找min 找max 就是 Kadane。
            // cur.mn_suf = min(0, pref.mn_suf + x)
            // cur.mx_suf = max(0, pref.mx_suf + x)
            // cur.mn_ans = min(pref.mn_ans, cur.mn_suf)
            // cur.mx_ans = max(pref.mx_ans, cur.mx_suf)
// ...所以 昨天的 1845D rating system 也是 只需要找到一个 min 就可以了？

// 306023132 	Feb/14/2025 10:15UTC+8 	Ouha 	1843F1 - Omsk Metro (simple version) 	C++20 (GCC 13-64) 	Accepted 	1359 ms 	3600 KB


// tle
// 开局就问 `? 1 2 10000`


// expected NO, found YES [97th token]
// 我还想改成 YEs， yES 来区分 是 vb错 还是 set2错。结果 found 就是 YES。。
// ...确实 cache是错的， 1个叶子 往上走 subpath 有2， 但不代表 另一个叶子 往上走有也有2.


// -1:pay,  1:get
// +station
// subpath, get k
// 增加节点并不会导致之前subpath的sum的失效
// 而且是tree，增加的节点的度为1，不会被经过。  所以每次加节点，就以该节点为root dfs？
// bu，这里给定了 起点 终点，找 subpath。 tree，所以path只有一条。 但是怎么知道 走哪个边呢？
// simple version，所以 起点一直 是1。
// 每次+点的时候 更新 parent，一路更新到root。 这个如果单链表，更新会tle吧。
// ...? 的时候，从 v 上浮到 root 就可以了。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vparent(2, -1);  // root is [1]
    std::vector<int> vget(2, 1);
    // std::vector<int> vdepth(2, 1);  // u->root path's node count
    std::vector<std::pair<int, int>> vp(2, {0, 1});  // {-1's sum, 1's sum} // {subpath.min, subpath.max}  // 能更进一步吗？保存 真正的 最大，最小。

    // std::vector<int> vb(sz1 * 2 + 2);  // already exists
    // vb[0 + sz1] = true;
    
    for (size_t i = 0; i < sz1; ++i) {
        char ch;
        int a,b,c;
        std::cin>>ch;
        if (ch == '+') {
            std::cin>>a>>b;
            vparent.push_back(a);
            vget.push_back(b);
            // vdepth.push_back(vdepth[a] + 1);
            vp.push_back(vp[a]);
            if (b == -1) {
                vp.back().first--;
            } else {
                vp.back().second++;
            }
        } else {
            std::cin>>a>>b>>c; // a always is 1
            // c is [-sz1, sz1]

            // if (vb[c + sz1]) {
            //     std::cout<<"YEs\n";
            //     continue;
            // }

            if (c == 0) {
                std::cout<<"yes\n";
                continue;
            }
            if (c < vp[b].first || c > vp[b].second) {
                std::cout<<"No\n";
                continue;
            }
            
            // std::unordered_set<int> set2;   // tle? array?
            // set2.insert(0);
            std::vector<bool> vb2(sz1 * 2 + 2);
            vb2[0 + sz1] = true;
            
            int got = 0;
            int t2 = 0;
            bool ok = false;
            while (b != -1) {
                got += vget[b];
                b = vparent[b];
                t2 = got - c;   // got - t2 = c
                // if (set2.contains(t2)) {
                if (vb2[t2 + sz1]) {
                    // vb[c + sz1] = true;
                    ok = true;
                    break;
                }
                // set2.insert(got);
                vb2[got + sz1] = true;
            }
            if (ok) {
                std::cout<<"yES\n";
            } else {
                std::cout<<"NO\n";
            }
        }
    }
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
