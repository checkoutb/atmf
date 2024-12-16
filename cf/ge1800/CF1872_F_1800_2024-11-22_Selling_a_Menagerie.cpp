
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
#include <climits>   // INT_MAX

//#include <stack>
//#include <bitset>
#include <set>
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





// 292700095 	Nov/22/2024 10:33UTC+8 	Ouha 	1872F - Selling a Menagerie 	C++20 (GCC 13-64) 	Accepted 	1405 ms 	11400 KB


// que is empty 的时候，预先计算 priq 保存 损失 ( 需要一个 vst数组)。  用v<set>代替 vvi
void fun1() {
    int sz1;
    std::cin>>sz1;

    std::vector<int> vp(sz1), vaf(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vaf[i];
        --vaf[i];
    }
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vp[i];
    }
    std::vector<std::set<int>> vset(sz1);
    std::vector<bool> vst(sz1);

    for (int i = 0; i < sz1; ++i) {
        vset[vaf[i]].insert(i);
    }

    std::queue<int> que;
    std::priority_queue<std::pair<long long, int>> priq; // <lost, index>
    for (int i = 0; i < sz1; ++i) {
        if (vset[i].empty()) {
            que.push(i);
        } else {
            long long t2 = 0; // lost
            for (int idx : vset[i]) {
                t2 += vp[idx];
            }
            t2 = -t2;
            priq.push(std::make_pair(t2, i));
        }
    }

    std::vector<int> vans;
    while (vans.size() < sz1) {
        while (que.empty()) {
            if (vst[priq.top().second]) {
                priq.pop();
            } else {
                que.push(priq.top().second);
                priq.pop();
            }
        }
        int tp = que.front();
        que.pop();
        vans.push_back(tp);
        vst[tp] = true;

        vset[vaf[tp]].erase(tp);
        if (vset[vaf[tp]].empty() && !vst[vaf[tp]]) {
            que.push(vaf[tp]);
        }
        if (!vset[vaf[tp]].empty()) {
            long long t2 = 0;
            for (int i : vset[vaf[tp]]) {  // 预先计算 vset[i] 的和，然后每次剔除的时候，减去，这样 priq 就不需要 这个for了。应该可以更快。
                t2 -= vp[i];
            }
            priq.push(std::make_pair(t2, vaf[tp]));
        }
    }
    
    for (int i : vans) {
        std::cout<<(i + 1)<<' ';
    }
    std::cout<<std::endl;

    
}


// tle .. 但不知道为什么它能过 test3， 上面的 过test3的时候 int 溢出了。

// 拓扑排序， 不被害怕的 第一个卖。 如果环，那么选 价格最高的 卖，还是得计算下，环从这里断开的损失。
void fun1_tle()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vprice(sz1);
    std::vector<int> vafraid(sz1);

    for (int i = 0; i < sz1; ++i) {
        std::cin>>vafraid[i];
        --vafraid[i];
    }
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vprice[i];
    }

    std::vector<std::vector<int>> vvi(sz1);
    
    for (int i = 0; i < sz1; ++i) {
        vvi[vafraid[i]].push_back(i);
    }

    std::queue<int> que;
    int remain = sz1;

    for (int i = 0; i < sz1; ++i) {
        if (vvi[i].empty()) {
            que.push(i);
        }
    }

    std::vector<int> vans;

    while (remain > 0) { // vans.size() < sz1...
        if (que.empty()) {
            // circle
            int t2 = -1; // sell which
            int t3 = INT_MAX; // lost how much
            int t4 = 0;
            for (int i = 0; i < sz1; ++i) {
                if (vvi[i].empty()) {
                    continue;
                }
                // if sell this
                t4 = 0;
                for (int j = 0; j < vvi[i].size(); ++j) {
                    t4 += vprice[vvi[i][j]];
                }
                if (t4 < t3) {
                    t2 = i;
                    t3 = t4;
                }
            }
            vvi[t2].clear();
            que.push(t2);
        }

        int tp = que.front();
        que.pop();
        remain--;
        vans.push_back(tp);

        std::vector<int> &vi = vvi[vafraid[tp]];   // i should use set/map...
        for (int i = 0; i < vi.size(); ++i) {
            if (vi[i] == tp) {
                vi.erase(vi.begin() + i);

                if (vi.empty()) {
                    que.push(vafraid[tp]);
                }
                
                break;
            }
        }

    }

    for (int i : vans) {
        std::cout<<(i + 1)<<' ';
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
