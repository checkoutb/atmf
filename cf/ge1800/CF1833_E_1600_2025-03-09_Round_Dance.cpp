
//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>

//#include <cstdio>
//#include <cstring>
#include <algorithm>
#include <cstdio>
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





// 309594783 	Mar/09/2025 16:04UTC+8 	Ouha 	1833E - Round Dance 	C++20 (GCC 13-64) 	Accepted 	93 ms 	4500 KB 



// max - uf
// min : ? circle but how? easy!!dfs  and not need uf
// a circle with 2 person can join/merge.. no
// need uf...
int ufa(std::vector<int>& uf, int idx);
void fun1() {
    int sz1;
    std::cin>>sz1;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
        --vi[i];
    }

    std::vector<int> uf(sz1, -1);
    for (int i = 0; i < sz1; ++i) {
        int a = ufa(uf, i);
        int b = ufa(uf, vi[i]);
        if (a != b) {
            uf[a] = b;
        }
    }

    myvvi vvi(sz1);
    for (int i = 0; i < sz1; ++i) {
        int a = ufa(uf, i);
        vvi[a].push_back(vi[i]);
    }
    int mxcnt = 0;
    int mgcnt = 0; // can merge
    for (int i = 0; i < sz1; ++i) {
        if (vvi[i].empty())
            continue;
        mxcnt++;
        std::sort(std::begin(vvi[i]), std::end(vvi[i]));
        bool same = false;
        for (int j = 1; j < vvi[i].size(); ++j) {
            if (vvi[i][j] == vvi[i][j - 1]) {
                same = true;
                break;
            }
        }
        if (same || vvi[i].size() == 2)
            mgcnt++;
    }
#ifdef __test
    // for (int i = 0; i < sz1; ++i) {
    //     std::cout<<i<<'_'<<vvi[i].size()<<std::endl;
    //     for (int j = 0; j < vvi[i].size(); ++j)
    //         std::cout<<vvi[i][j];
    //     std::cout<<'\n';
    // }
    // std::cout<<"     "<<mxcnt<<','<<mgcnt<<std::endl;
#endif
    std::cout<<(mxcnt - (mgcnt > 1 ? mgcnt - 1 : 0))<<' '<<mxcnt<<std::endl;
}

int ufa(std::vector<int>& uf, int idx) {
    return uf[idx] == -1 ? idx : uf[idx] = ufa(uf, uf[idx]);
}


void fun1__eeee()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    int t2 = 0;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        t2--;
        vi[i] = t2;
    }

    int mxcnt = 0;
    int no_cycle_cnt = 0;
    for (int i = 0; i < sz1; ++i) {
        if (vi[i] < 0)
            continue;

        int st = vi[i];
        t2 = st;
        vi[i] = -vi[i];
        int len = 1;
        while (vi[t2] >= 0) {
            vi[t2] = -vi[t2];
            t2 = -vi[t2];
            len++;
        }
        mxcnt++;
        if (t2 != i || len == 2) {
            no_cycle_cnt++;
        }
    }
    
    std::cout<<(mxcnt - no_cycle_cnt + 1)<<' '<<mxcnt<<std::endl;
    
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
