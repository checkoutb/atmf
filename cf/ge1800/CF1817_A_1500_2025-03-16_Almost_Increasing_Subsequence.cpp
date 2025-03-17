
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



//     for(int i=1;i<n-1;++i) {
//         int downhill = a[i-1]>=a[i] and a[i]>=a[i+1];
//         p[i] = p[i-1] + downhill;
//     }
// int ans = (r-l+1) - p[r-1] + p[l];


// 310869531 	Mar/16/2025 17:33UTC+8 	Ouha 	1817A - Almost Increasing Subsequence 	C++20 (GCC 13-64) 	Accepted 	171 ms 	1100 KB



// 

// 连续非降 就合并
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<std::pair<int, int>> vp(sz2);
    int a, b;
    for (int i = 0; i < sz2; ++i) {
        std::cin>>a>>b;
        --a, --b;
        vp[i].first = a;
        vp[i].second = b;
    }

    
    std::vector<int> v2(sz1);
    v2[0] = 1;
    v2[1] = 2;
    std::vector<int> vb(sz1);
    for (int i = 2; i < sz1; ++i) {
        if (vi[i] > vi[i - 1]) {
            v2[i] = v2[i - 1] + 1;
        } else {
            // y <= z, check x y
            if (vi[i - 2] < vi[i - 1]) {
                v2[i] = v2[i - 1] + 1;
            } else {
                v2[i] = v2[i - 1];
                vb[i] = true;
            }
        }
    }

    std::vector<int> vans(sz2);
    for (int i = 0; i < sz2; ++i) {
        a = vp[i].first;
        b = vp[i].second;

        vans[i] = v2[b] - (a == 0 ? 0 : v2[a - 1]);
        if (vb[a]) {
            ++vans[i];
        }
        if (a + 1 <= b && vb[a + 1]) {
            ++vans[i];
        }
    }

#ifdef __test
    std::cout<<"v2: ";
    for (int i : v2) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
#endif
    
    for (int i : vans) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
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
    // std::cin>>w;  // <------   remove or not
    
    
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
