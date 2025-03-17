
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




// 310557095 	Mar/14/2025 20:00UTC+8 	Ouha 	1821B - Sort the Subarray 	C++20 (GCC 13-64) 	Accepted 	109 ms 	0 KB


// 4
// 4 2 1 3
// 4 1 2 3  //......


// 
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    std::vector<int> v2(sz1);

    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    for (int i = 0; i < sz1; ++i) {
        std::cin>>v2[i];
    }

    int st = -1;
    int en = 0;

    for (int i = 0; i < sz1; ++i) {
        if (vi[i] != v2[i]) {
            if (st == -1)
                st = i;
            en = i;
        }
    }

    int mn = vi[st];
    int mx = mn;
    for (int i = st; i <= en; ++i) {
        mn = std::min(mn, vi[i]);
        mx = std::max(mx, vi[i]);
    }

    while (st - 1 >= 0 && vi[st - 1] <= mn) {
        --st;
        mn = vi[st];
    }

    while (en + 1 < sz1 && (vi[en + 1] >= mx)) {
        ++en;
        mx = vi[en];
    }
    ++st, ++en;
    std::cout<<st<<' '<<en<<std::endl;
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
