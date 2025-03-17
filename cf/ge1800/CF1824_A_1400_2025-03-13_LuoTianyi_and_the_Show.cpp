
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





// g



void fun1(bool show = false) {
    int szp, szs;
    std::cin>>szp>>szs;

    int cnt1l = 0;
    int cnt2r = 0;
    std::vector<int> vi;
    int t2;
    for (int i = 0; i < szp; ++i) {
        std::cin>>t2;
        if (t2 == -1) {
            ++cnt1l;
        } else if (t2 == -2) {
            ++cnt2r;
        } else {
            vi.push_back(t2);
        }
    }

    std::sort(std::begin(vi), std::end(vi));
    int lst = 0;
    std::vector<int> v2;
    vi.push_back(szs + 1);
    for (int i = 0; i < vi.size(); ++i) {
        t2 = vi[i] - lst - 1;
        if (lst == 0) {
            continue;
        }
        v2.push_back(t2);
        lst = vi[i];
    }
    
}


//
void fun1__eee(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1; // person
    std::cin>>sz2; // seat

    int cntl = 0;
    int cntr = 0;
    std::vector<int> vi;

    int t2;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        if (t2 == -2) {
            ++cntr;
        } else if (t2 == -1) {
            ++cntl;
        } else {
            vi.push_back(t2);
        }
    }

    std::vector<int> v2;
    std::sort(std::begin(vi), std::end(vi));
    int lst = 0;
    int ans = 0;
    for (int i = 0; i < vi.size(); ++i) {
        if (i > 0 && vi[i] == vi[i - 1])
            continue;
        ++ans;
        t2 = vi[i] - lst - 1;
        if (t2)
            v2.push_back(t2);
        lst = vi[i];
    }

    if (v2.empty()) {
        // std::cout<<std::min(sz1, std::max(cntl + 1, cntr + 1))<<std::endl;
        // if (cntl == 0 || cntr == 0) {
        //     std::cout<<1<<std::endl;
        // } else {
        //     std::cout<<std::min(sz2, std::min(sz1, std::min(1 + cntr, 1 + cntl)))<<std::endl;
        // }
        std::cout<<ans + std::min(sz2 - ans, std::max(cntr, cntl))<<std::endl;
        return;
    }
    
    t2 = sz2 - lst;
    if (t2)
        v2.push_back(t2);

    int st = 0;
    int en = v2.size() - 1;

#ifdef __test
    std::cout<<cntl<<','<<cntr<<std::endl;
    for (int i : v2) {
        std::cout<<i<<',';
    }
    std::cout<<std::endl;
#endif
    


    
    while (st <= en && v2[st] <= cntl) {
        cntl -= v2[st];
        ans += v2[st];
        ++st;
    }

    while (st <= en && v2[en] <= cntr) {
        cntr -= v2[en];
        ans += v2[en];
        --en;
    }

    if (st == en) {
        // if (st == v2.size() - 1) {
        //     ans += std::min(v2.back(), cntr);
        // } else if (en == 0) {
        //     ans += std::min(v2.front(), cntl);
        // } else {
            ans += std::min(v2[st], std::max(cntr, cntl));
        // }
    } else {
        ans += std::min(cntl, v2[st]);
        ans += std::min(cntr, v2[en]);
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
