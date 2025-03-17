
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







// 309584156 	Mar/09/2025 14:30UTC+8 	Ouha 	1833D - Flipper 	C++20 (GCC 13-64) 	Accepted 	62 ms 	100 KB

// 好麻烦..忘记了 permutation
// 53241-41253 52341-41325---41352
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);

    int mx = -1;
    int mxi = -1;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
        if (vi[i] > mx) {
            mx = vi[i];
            mxi = i;
        }
    }

    
    if (mxi == 0) {
        mxi = 1;
        for (int i = 2; i < sz1; ++i) {
            if (vi[i] > vi[mxi]) {
                mxi = i;
            }
        }
        for (int i = mxi; i < sz1; ++i) {
            std::cout<<vi[i]<<' ';
        }
        if (mxi + 1 == sz1) {
            for (int i = 0; i < mxi; ++i) {
                std::cout<<vi[i]<<' ';
            }
        } else {
            std::cout<<vi[mxi - 1]<<' ';
            for (int i = 0; i < mxi - 1; ++i) {
                std::cout<<vi[i]<<' ';
            }
        }
    } else if (mxi + 1 == sz1 && vi[mxi - 1] <= vi[0]) {
        std::cout<<vi[mxi]<<' ';
        for (int i = 0; i < mxi; ++i) {
            std::cout<<vi[i]<<' ';
        }
    } else {
        for (int i = mxi; i < sz1; ++i) {
            std::cout<<vi[i]<<' ';
        }
        int mxi2 = mxi - 1;
        while (mxi2 > 0 && vi[mxi2 - 1] > vi[0]) {
            mxi2--;
        }
        for (int i = mxi - 1; i >= mxi2; --i) {
            std::cout<<vi[i]<<' ';
        }
        for (int i = 0; i < mxi2; ++i) {
            std::cout<<vi[i]<<' ';
        }
        // for (int i = 0; i < mxi; ++i) {
        //     if (vi[i] > vi[mxi2]) {
        //         mxi2 = i;
        //     }
        // }
        // for (int i = mxi - 1; i >= mxi2; --i) {
        //     std::cout<<vi[i]<<' ';
        // }
    }
    
    std::cout<<std::endl;

    
    // int mx = 0;
    // for (int i = 0; i < sz1; ++i) {
    //     std::cin>>vi[i];
    //     mx = std::max(mx, vi[i]);
    // }

    // // r, l
    // std::vector<std::pair<int, int>> vp;
    // for (int i = 0; i < sz1; ++i) {
    //     if (vi[i] == mx)
    //         vp.push_back({-1, i});
    // }

    // while (!vp.empty()) {
    //     std::vector<std::pair<int, int>> vp2;
        
    // }
        
    
    
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
