
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





// 293174934 	Nov/25/2024 13:36UTC+8 	Ouha 	1870C - Colorful Table 	C++20 (GCC 13-64) 	Accepted 	171 ms 	0 KB


// ..last bigger, first bigger
// bit, range query  [vi[i], kk]'s min index, max index
// ..for
void fun1() {
    int sz1, kk;
    std::cin>>sz1>>kk;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<int> fst_big(kk + 1, -1);
    std::vector<int> lst_big(kk + 1, -1);
    std::vector<bool> exists(kk + 1);
    
    int t2 = 0;
    for (int i = 0; i < sz1; ++i) {
        t2 = vi[i];
        exists[t2] = true;
        while (fst_big[t2] == -1) {
            fst_big[t2] = i;
            --t2;
        }
    }

    for (int i = sz1 - 1; i >= 0; --i) {
        t2 = vi[i];
        while (lst_big[t2] == -1) {
            lst_big[t2] = i;
            --t2;
        }
    }

    for (int i = 1; i <= kk; ++i) {
        if (!exists[i]) {
            std::cout<<"0 ";
            continue;
        }

        t2 = lst_big[i] - fst_big[i] + 1;
        std::cout<<(t2 + t2)<<' ';
    }

    std::cout<<std::endl;
}


// 3 5  / 3 2 4
//   3 2 4
// 3 3 2 3
// 2 2 2 2
// 4 3 2 4

// 主对角线对称矩阵
// first appear,    last appear's next smaller
// set, binary search ? stack!
void fun1___error()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<int> fst(kk + 1);
    std::vector<int> small(kk + 1);
    
    std::vector<int> stk;
    
    for (int i = sz1 - 1; i >= 0; --i) {
        while (!stk.empty() && stk.back() >= vi[i]) {
            stk.pop_back();
        }

        if (small[vi[i]] == 0) {
            small[vi[i]] = stk.empty() ? sz1 : stk.back();
        }
        fst[vi[i]] = i;
        stk.push_back(i);
    }


    int t2 = 0;
    for (int i = 1; i <= kk; ++i) {
        t2 = small[i] - fst[i];
        std::cout<<(t2 + t2)<<' ';
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
