
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


//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE





// 264661403 	Jun/08/2024 09:49UTC+8 	Ouha 	1878E - Iva & Pav 	C++20 (GCC 13-64) 	Accepted 	1312 ms 	32800 KB 



// binary search ?
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::cin>>sz2;
    std::vector<std::pair<int, int>> vp(sz2);
    for (int i = 0; i < sz2; ++i) {
        std::cin>>vp[i].first>>vp[i].second;
    }

    std::vector<std::vector<int>> vvi(sz1, std::vector<int>(31, 0)); // 30?

    int t2;
    for (int i = 0; i < sz1; ++i) {
        t2 = vi[i];
        for (int j = 0; j < 31 && t2 > 0; ++j) {
            if ((t2 & (1 << j)) != 0) {
                vvi[i][j] = 1;
                t2 ^= (1 << j);
            }
        }
        if (i > 0) {
            for (int j = 0; j < 31; ++j) {
                vvi[i][j] += vvi[i - 1][j];
            }
        }
    }

    #ifdef __test
    for (int i = 0; i < sz1; ++i) {
        for (int j = 0; j < 7; ++j) {
            std::cout<<vvi[i][j]<<',';
        }
        std::cout<<'\n';
    }
    #endif
    
    int st, en, ans, beg, t3;
    for (int i = 0; i < sz2; ++i) {
        st = vp[i].first - 1;  // input begin from 1..
        kk = vp[i].second;
        if (kk > vi[st]) {
            std::cout<<-1<<' ';
            continue;
        }
        en = sz1 - 1;
        ans = -1;
        beg = st;
        while (st <= en) {
            int md = (st + en) / 2;
            t2 = 0;
            t3 = md - beg + 1;
            for (int i = 0; i < 31; ++i) {
                if ((vvi[md][i] - (beg == 0 ? 0 : vvi[beg - 1][i])) == t3) {
                    t2 |= 1 << i;
                }
            }
            #ifdef __test
            // std::cout<<t2<<"..\n";
            #endif
            if (t2 >= kk) {
                ans = md;
                st = md + 1;
            } else {
                en = md - 1;
            }
        }
        std::cout<<(ans + 1)<<' ';
    }

    std::cout<<'\n';
    
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
