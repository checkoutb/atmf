
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
//#include <limits.h>   // INT_MAX

#include <stack>
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


//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE







// 269814123 	Jul/11/2024 11:19UTC+8 	Ouha 	1873H - Mad City 	C++20 (GCC 13-64) 	Accepted 	608 ms 	9200 KB 

// M's step count to V's circle entry point
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    int stm, stv;
    std::cin >> stm >> stv;

    std::vector<std::vector<int>> vvi(sz1 + 1);
    int a, b;
    for (int i = 0; i < sz1; ++i) {
        std::cin >> a >> b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }

    ///////////////
    // V's step count to V's circle entry point
    // 2*10^5
    // std::vector<int> vi(sz1 + 1, -1);
    // std::queue<int> que1;
    // std::queue<std::pair<int, int>> que1;
    // que1.push(std::make_pair(stv, -1));
    // vi[stv] = 0;
    // int vcep = -1;
    // int stpv = -1;
    // while (vcep == -1) {
    //     std::pair<int, int> p2 = que1.front();
    //     que1.pop();
    //     int nw = p2.first; // now
    //     int prev = p2.second;
    //     int stpp1 = vi[nw] + 1;
    //     for (int nxt : vvi[nw]) { // next
    //         if (nxt == prev)
    //             continue;
    //         if (vi[nxt] != -1) {
    //             // circle
    //             vcep = nxt;
    //             stpv = vi[nxt];
    //             break;
    //         } else {
    //             vi[nxt] = stpp1;
    //             que1.push(std::make_pair(nxt, nw));
    //         }
    //     }
    // }

    // ... bfs 能找环，但是不知道入口 (也可以，要通过最近公共祖先，但就不是单纯的bfs了，而且要记录每个节点的prev)。 只有 dfs可以找到入口。
    std::stack<std::pair<int, int>> stk1;
    stk1.push(std::make_pair(stv, 0)); // node, next nxt
    
    std::vector<int> vi(sz1 + 1, -1);
    std::vector<int> vprev(sz1 + 1, -1); // ...不记录不行。。不记录直接 a-b-a 成环了。。
    vi[stv] = 0;
    int vcep = -1;
    int stpv = -1;
    while (!stk1.empty()) {
        std::pair<int, int>& p = stk1.top();
        if (p.second >= vvi[p.first].size()) {
            stk1.pop();
            continue;
        }
        int nxt = vvi[p.first][p.second];
        ++p.second;
        if (vprev[p.first] == nxt)
            continue;
        vprev[nxt] = p.first;
        
        if (vi[nxt] != -1) {
            // circle
            vcep = nxt;
            stpv = vi[nxt];
            break;
        }
        vi[nxt] = vi[p.first] + 1;
        stk1.push(std::make_pair(nxt, 0));
    }
    

    // while (!que1.empty())
    //     que1.pop();

    std::queue<std::pair<int, int>> que1;
    que1.push(std::make_pair(stm, -1));
    std::fill(std::begin(vi), std::end(vi), -1);
    vi[stm] = 0;
    int stpm = -1;
    while (stpm == -1) {
        std::pair<int, int> p = que1.front();
        que1.pop();
        int nw = p.first;
        int prev = p.second;
        if (nw == vcep) {
            stpm = vi[nw];
            break;
        }
        int stp2 = vi[nw] + 1;
        for (int nxt : vvi[nw]) {
            // if (prev == nxt) // ... 直接判断vi就可以了。。而且 vi 更准，不会重复。。
            if (vi[nxt] != -1)
                continue;
            vi[nxt] = stp2;
            que1.push(std::make_pair(nxt, nw));
        }
    }

    #ifdef __test
    std::cout<<vcep<<", "<<stpv<<", "<<stpm<<std::endl;
    #endif
    
    if (stpm <= stpv) {
        std::cout<<"NO\n";
    } else {
        std::cout<<"YES\n";
    }
    
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
