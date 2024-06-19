
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
#include <bitset>
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







// 263822669 	Jun/03/2024 12:39UTC+8 	Ouha 	1882B - Sets and Union 	C++20 (GCC 13-64) 	Accepted 	93 ms 	0 KB 


void fun1()
{
    int sz1;
    std::cin>>sz1;

    std::vector<std::vector<int>> vvi(sz1); // set's element
    std::vector<std::vector<int>> vv2(51); // element -> set's index

    int j = 0;
    int t2 = 0;
    std::vector<int> vall(51);
    for (int i = 0; i < sz1; ++i) {
        for (std::cin>>j; j > 0; --j) {
            std::cin>>t2;
            vvi[i].push_back(t2);
            ++vall[t2];
            vv2[t2].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 50; ++i) {
        if (vall[i] == 0)
            continue;
        std::vector<int> v2(vall);
        for (int j = 0; j < vv2[i].size(); ++j) {
            int t2 = vv2[i][j];
            for (int k = 0; k < vvi[t2].size(); ++k) {
                --v2[vvi[t2][k]];
            }
        }
        int t3 = 0;
        for (int j = 1; j < 51; ++j) {
            if (v2[j] != 0)
                ++t3;
        }
        ans = std::max(t3, ans);
    }
    std::cout<<ans<<std::endl;
}



// example 3

// != all
// remove a set that contains less distinct number ?
// < 50 long long. but  .. bitset, no vb
void fun1_eeee()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<std::bitset<51>> vbs(sz1);

    int j = 0;
    int t2 = 0;
    // std::bitset<51> bsall;
    std::vector<int> viall(51);
    for (int i = 0; i < sz1; ++i) {
        // std::cin>>j;
        // for (; j > 0; --j) {            
        // }
        for (std::cin>>j; j > 0; --j) {
            std::cin>>t2;
            vbs[i].set(t2);
            ++viall[t2];
        }
        // bsall |= vbs[i];
    }

    int ans = -1; // min distinct
    for (int i = 0; i < sz1; ++i) {
        t2 = 0;
        for (int j = 1; j <= 50; ++j) {
            if ((viall[j] == 1) && vbs[i].test(j))
                ++t2;
        }
        if (t2 != 0) {
            if (ans == -1) {
                ans = t2;
            } else {
                ans = std::min(ans, t2);
            }
        }
    }
    if (ans == -1) {
        std::cout<<"0\n";
        return;
    }

    ans = -ans;
    for (int i = 1; i <= 50; ++i)
        if (viall[i])
            ++ans;
    
    std::cout<<ans<<'\n';
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
