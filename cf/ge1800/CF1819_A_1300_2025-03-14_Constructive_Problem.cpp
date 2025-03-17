
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


// 310570528 	Mar/14/2025 21:39UTC+8 	Ouha 	1819A - Constructive Problem 	C++20 (GCC 13-64) 	Accepted 	156 ms 	4000 KB


// TLE@4, WA@10, WA@20, AC



// 
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    // std::vector<int> vi(sz1);
    std::vector<int> vi;
    int t2;
    sz2 = sz1;    // WA@20
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        if (t2 <= sz1 + 2)     // tle@4:if,    WA@10:+2
            vi.push_back(t2);
    }

    std::vector<bool> vb(sz1 + 3);
    sz1 = vi.size();
    for (int i = 0; i < sz1; ++i) {
        vb[vi[i]] = true;
    }

    int mex = -1;
    for (int i = 0; i < vb.size(); ++i) {
        if (!vb[i]) {
            mex = i;
            break;
        }
    }

    int st = -1, en = -1;
    for (int i = 0; i < sz1; ++i) {
        if (vi[i] == mex + 1) {
            if (st == -1)
                st = i;
            en = i;
        }
    }

    if (st == -1) {
        if (mex == sz2) {   // WA@20
            std::cout<<"no"<<std::endl;
        } else {
            std::cout<<"yes"<<std::endl;
        }
        return;
    }

    for (int i = 0; i < vb.size(); ++i)
        vb[i] = false;

    for (int i = 0; i < st; ++i) {
        vb[vi[i]] = true;
    }
    for (int i = en + 1; i < sz1; ++i) {
        vb[vi[i]] = true;
    }
    for (int i = 0; i < mex; ++i) {
        if (!vb[i]) {
            std::cout<<"no"<<std::endl;
            return;
        }
    }

    std::cout<<"yes"<<std::endl;
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
