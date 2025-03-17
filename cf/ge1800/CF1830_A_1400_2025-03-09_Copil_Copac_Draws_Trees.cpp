
//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>

//#include <cstdio>
//#include <cstring>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
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






// 309611916 	Mar/09/2025 18:29UTC+8 	Ouha 	1830A - Copil Copac Draws Trees 	C++20 (GCC 13-64) 	Accepted 	187 ms 	13500 KB 


// bfs..depth.....no
// TLE..
// bfs!

void fun1() {
    int sz1;
    std::cin>>sz1;
    --sz1;
    std::vector<std::vector<std::pair<int, int>>> vvp(sz1 + 1);
    int a, b;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>a>>b;
        --a, --b;
        vvp[a].push_back(std::make_pair(b, i));
        vvp[b].push_back(std::make_pair(a, i));
    }
    std::vector<std::pair<int, int>> vp;
    vp.push_back(std::make_pair(0, -1)); // node, edge order
    int ans = 0;
    std::vector<int> vi(sz1 + 1); // time
    vi[0] = 1;
    int t2, t3;

    //std::cout<<"22n33\n"<<std::endl;
    while (!vp.empty()) {
        //std::cout<<vp.size()<<std::endl;
        std::vector<std::pair<int, int>> vp2;
        for (int i = 0; i < vp.size(); ++i) {
            a = vp[i].first;
            b = vp[i].second;
            for (int j = 0; j < vvp[a].size(); ++j) {
                t2 = vvp[a][j].first;
                t3 = vvp[a][j].second;
                if (vi[t2] != 0)
                    continue;
                //std::cout<<a<<'_'<<t2<<std::endl;
                if (t3 > b) {
                    vp2.push_back(std::make_pair(t2, t3));
                    vi[t2] = vi[a];
                } else {
                    vi[t2] = vi[a] + 1;
                    vp2.push_back(std::make_pair(t2, t3));
                }
            }
        }

        vp = vp2;
    }
    for (int i : vi) {
        ans = std::max(ans, i);
    }
    std::cout<<ans<<std::endl;
}


void fun1__ttttlle() {
    int sz1;
    std::cin>>sz1;
    std::vector<std::vector<int>> vvi(sz1 - 1, std::vector<int>(2, 0));
    int a, b;
    for (int i = 0; i < sz1 - 1; ++i) {
        std::cin>>a>>b;
        --a, --b;
        vvi[i][0] = a;
        vvi[i][1] = b;
    }
    std::vector<bool> vb(sz1);
    vb[0] = true;
    bool ok = true;
    int ans = -1;
    while (ok) {
        ++ans;
        ok = false;
        for (int i = 0; i < sz1 - 1; ++i) {
            a = vvi[i][0];
            b = vvi[i][1];
            if (vb[a] ^ vb[b]) {
                ok = true;
                vb[a] = vb[b] = true;
            }
        }
    }
    std::cout<<ans<<std::endl;
}


void fun1___eee()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<std::vector<int>> vvi(sz1);
    int a, b;
    for (int i = 1; i < sz1; ++i) {
        std::cin>>a>>b;
        --a, --b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }

    int ans = -1;
    std::vector<std::pair<int, int>> vp;
    vp.push_back(std::make_pair(0, -1));

    while (!vp.empty()) {
        ++ans;
        std::vector<std::pair<int, int>> v2;

        for (int i = 0; i < vp.size(); ++i) {
#ifdef __test
            std::cout<<vp[i].first<<", "<<vp[i].second<<std::endl;
#endif

            a = vp[i].first;
            b = vp[i].second;
            for (int nxt : vvi[a]) {
                if (nxt == b)
                    continue;
                v2.push_back(std::make_pair(nxt, a));
            }
        }

        vp = v2;
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
