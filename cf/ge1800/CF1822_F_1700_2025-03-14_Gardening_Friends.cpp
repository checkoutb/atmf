
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





// g 好麻烦。



// 2 dfs? ??? 每次移动， cost 和 len 都是固定的啊。
// .. 似乎是， 如果 k <= cost 那么不需要移动。 否则 就是 树中的 最长路径？ bu 不一定是最长路径
// 应该计算 每个node作为root的子树的深度。
int dfsa2(std::vector<std::vector<int>>& vvi, int node, int parent, std::vector<int>& vi);
int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent);
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    int lenk, cst;
    std::cin>>lenk>>cst;

    std::vector<std::vector<int>> vvi(sz1);
    int a, b;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>a>>b;
        --a, --b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }

    if (cst > lenk) {
        std::vector<int> vi(sz1);
        dfsa2(vvi, 0, -1, vi);
        
    } else  {
        // no move
        int ans = dfsa1(vvi, 0, -1);
        ans *= lenk;
        std::cout<<ans<<std::endl;
    }
    
}

int dfsa2(std::vector<std::vector<int>>& vvi, int node, int parent, std::vector<int>& vi) {
    int ans = 0;
    for (int nxt : vvi[node]) {
        if (nxt == parent)
            continue;
        ans = std::max(ans, dfsa2(vvi, nxt, node, vi));
    }
    vi[node] = ans;
    return ans + 1;
}

int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent) {
    int ans = 0;

    for (int nxt : vvi[node]) {
        if (nxt == parent)
            continue;

        ans = std::max(ans, dfsa1(vvi, nxt, node));
    }
    return ans + 1;
}

// void dfsa1_mx_mx2(std::vector<std::vector<int>>& vvi, int node, int parent, std::pair<std::pair<int, int>, std::pair<int, int>>& mxpp) {
    
// }




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
