
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




// 304254440 	Feb/03/2025 21:17UTC+8 	Ouha 	1846C - Rudolf and the Another Competition 	C++20 (GCC 13-64) 	Accepted 	93 ms 	4600 KB


// panelty > INT_MAX


// point， penalty
// 似乎就是 时间越短，越先做。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2>>kk;

    std::vector<std::vector<int>> vvi(sz1, std::vector<int>(sz2, 0));
    for (size_t i = 0; i < sz1; ++i) {
        for (size_t j = 0; j < sz2; ++j) {
            std::cin>>vvi[i][j];
        }
    }

    //std::vector<std::pair<int, int>> vp(sz1);

    int ans = 1;
    int cnt2 = 0;
    long long penalty2 = 0;
    int t2 = 0;
    std::sort(std::begin(vvi[0]), std::end(vvi[0]));
    for (int j = 0; j < sz2; ++j) {
        t2 += vvi[0][j];
        if (t2 <= kk) {
            cnt2++;
            penalty2 += t2;
        } else {
            break;
        }
    }
    
    for (size_t i = 1; i < sz1; ++i) {
        std::vector<int>& vi = vvi[i];
        std::sort(std::begin(vi), std::end(vi));
        int cnt = 0;
        long long penalty = 0;
        int t2 = 0;
        for (int j = 0; j < sz2; ++j) {
            t2 += vi[j];
            if (t2 <= kk) {
                cnt++;
                penalty += t2;
            } else {
                break;
            }
        }
        if (cnt > cnt2 || (cnt == cnt2 && penalty < penalty2)) {
            ++ans;
        }
    }

    //std::sort(std::begin(vp), std::end(vp));

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
