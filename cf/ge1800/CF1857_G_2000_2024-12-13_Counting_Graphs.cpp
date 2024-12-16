
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



// 296274563 	Dec/13/2024 18:28UTC+8 	Ouha 	1857G - Counting Graphs 	C++20 (GCC 13-64) 	Accepted 	999 ms 	11000 BK

// 这是第一道 2000 吧。 不，之前 1624E 过了。  这道是第二道AC 的2000分。

// `ls */*_2*00_*` 一共7道，都是2000，2道AC，其他g




// 加边， 但不能自环，不能重复边，而且 最小生成树 是原来的树，而且 加的边的权 不能超过S
//
// 如果 S 小于 原先的树中的 最大权，那么 无法加任何边吧。
// 如果大于，那么可以 无限加，组成一个 任意2个点 都直接连通的 图啊。
// 2^n ? n! ?  2^n吧，选或不选
// 但是，这是 2000 分的题啊。
// 。。果然不简单。。 不能任意2个点都连通。 要确保 原树中 这2个点的 距离 < S。  点对间最短路径 floyd。
// 难度来了， floyd 是 forforfor 的，  2*10^5 个点 怎么可能forforfor得了。
// 这是一棵树， 似乎可以 dfs 。不不不， 要构建 点对间最短路进，空间是 n^2， 抗不住的。
// 我只需要 判断 任意2个点 之间距离是否 小于 S。 不关心具体多少。 不行的 空间也是n^2
// 从度为1的节点出发，dfs，如果经过的边的权的和>S,则丢弃最上面的那个节点和边。
// ???
// ??? 根据 prim 或 kruskal， 只要 加的边的权 大于 任何已知的，那么 必然 不属于 最小生成树， 如果 <=已知的，那么 必然进入 最小生成树。   kruskal !!! 好像确实是这样的？ 就是 不需要考虑 2个节点的距离是否 < S
//
// .. 不是， 第3个例子， S是6， 树中有条边的权也是 6.  所以还是得计算 以某个点为出发， 权和 小于S 的边
// kruskal 是 加入后 不能成环 的 最小的权的边。  所以只需要 a,b 这2个点 的路径 的 最大权 小于 S 就可以了。
// 所以就是 权大于等于S的 边， 移除， 然后 每个连通分量中 计算 任意2点 直接连通， 2^n 


/*
.

   1
  2  3
    4  5

*/

// 边的权重不同， 是不同的图。。。。。
// 2-3: 4,5,6
// 2-5: 4,5,6
// 1-5: 3,4,5,6,
// 但是还是算不出 80 啊， 这里只是 3*3*4 = 36,  +不放边  4*4*5=80

// 还是要计算 任意两点 间的 最大权的边的权

// kruskal, 将 边 加入到 最小生成树前， 两侧 的子树中的 边的权 必然 小于等于 准备加入的这条边的权A。 这样两侧 可以加 A+1，A+2..S 这些权的边。



// int ufa(std::vector<int>& vi, int idx) { // .. (uf, idx)
//     return vi[idx] == -1 ? idx : vi[idx] = ufa(vi, vi[idx]);
// }

// return root's index
int ufa(std::vector<std::pair<int, int>>& uf, int idx) {
    if (uf[idx].first == -1) {
        return idx;
    } else {
        int t2 = ufa(uf, uf[idx].first);
        uf[idx].first = t2;
        return t2;
    }
}

void fun1() {
    int sz1, kk;
    std::cin>>sz1>>kk;

    std::priority_queue<std::vector<int>> priq;
    int a,b,w;
    for (int i = 1; i < sz1; ++i) {
        std::cin>>a>>b>>w;
        if (w >= kk)
            continue;
        --a, --b;
        priq.push({-w, a, b});
    }

    // vector<int> uf(sz1, -1);
    std::vector<std::pair<int, int>> uf(sz1, std::make_pair(-1, 1)); // <parent, count>
    long long ans = 1LL;
    const long long MOD = 998244353LL;
    
    while (!priq.empty()) {
        std::vector<int> vi = priq.top();
        priq.pop();
        w = -vi[0];
        a = vi[1];
        b = vi[2];

        int roota = ufa(uf, a);
        int rootb = ufa(uf, b);

        if (roota == rootb) // tree, so won't happen.
            continue;

        long long t2 = kk - w + 1;
        long long cnt = 1LL * uf[roota].second * uf[rootb].second - 1LL;

        while (cnt > 0) {
            if (cnt & 1) {
                ans = ans * t2 % MOD;
            }
            t2 = t2 * t2 % MOD;
            cnt >>= 1;
        }

        // merge .. add edge to min span tree
        uf[rootb].second += uf[roota].second;
        uf[roota].first = rootb;
        
    }

    std::cout<<ans<<std::endl;
}




int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, std::vector<bool>& vst);

void fun1_errrrror()
{
    int sz1, sz2, kk;
    std::cin >> sz1; // point count
    std::cin>>kk; // S, max edge value i can set
    
    std::vector<std::vector<int>> vvi(sz1);
    int a,b,w;
    for (int i = 1; i < sz1; ++i) {
        std::cin>>a>>b>>w;
        if (w >= kk)
            continue;
        
        --a, --b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }

    std::vector<bool> vst(sz1);
    int ans = 0;
    const int MOD = 998244353;
    for (int i = 0; i < sz1; ++i) {
        if (vst[i])
            continue;

        int cnt = dfsa1(vvi, i, -1, vst);
        long long t2 = 1LL * cnt * (cnt - 1) / 2;
        t2 -= cnt - 1;  // already exist cnt-1 edges
        
        long long t3 = 2LL;
        long long ans2 = 1LL;
        while (t2 > 0) {
            if (t2 & 1) {
                ans2 = (ans2 * t3) % MOD;
            }
            t3 = t3 * t3 % MOD;
            t2 >>= 1;
        }
        ans = (ans + ans2) % MOD;
    }
    std::cout<<ans<<std::endl;
}

// return number of node in subtree
int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, std::vector<bool>& vst) {
    int ans = 1;
    vst[node] = true;

    for (int nxt : vvi[node]) {
        if (nxt == parent)
            continue;
        ans += dfsa1(vvi, nxt, node, vst);
    }

    return ans;
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
