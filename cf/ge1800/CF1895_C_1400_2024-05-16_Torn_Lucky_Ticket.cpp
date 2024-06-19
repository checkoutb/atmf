
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
#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
//#include <unordered_map>
//#include <string.h>       // memset

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE








// AC
// 261143796 	May/16/2024 13:19UTC+8 	Ouha 	1895C - Torn Lucky Ticket 	C++20 (GCC 13-64) 	Accepted 	202 ms 	2700 KB


// 1. even
// 2. sum(half) = sum(half)
// sort by length
// each of length at most 5
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<std::string> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::ranges::sort(vi, [](const std::string& s1, const std::string& s2){
        return s1.size() < s2.size();
    });

    std::vector<std::map<int, int>> vmp(6); // 
    long long ans = 0LL;
    for (int i = 0; i < sz1; ++i) {
        const std::string& s2 = vi[i];
        sz2 = s2.size();
        int sum2 = 0;
        for (int j = 0; j < sz2; ++j)
            sum2 += s2[j] - 'a';

        int t2 = 0;
        for (int j = 0; j < sz2 - 1 && (sz2 - j - j - 2 > 0); ++j)
        {
            t2 += s2[j] - 'a';
            if (vmp[sz2 - j - j - 2].contains(sum2 - t2 - t2))
            {
                //std::cout<<ans<<", "<<s2<<", "<<j<<std::endl;
                ans += vmp[sz2 - j - j - 2][sum2 - t2 - t2];
            }
                
        }
        t2 = 0;
        for (int j = sz2 - 1; j > 0 && (j + j - sz2 > 0); --j)
        {
            t2 += s2[j] - 'a';
            if (vmp[j - (sz2 - j)].contains(sum2 - t2 - t2))
            {
                // std::cout<<ans<<"- "<<s2<<", "<<j<<std::endl;
                ans += vmp[j + j - sz2][sum2 - t2 - t2];
            }
                
        }
        if (vmp[sz2].contains(sum2))
            ans += vmp[sz2][sum2] * 2;
        
        ++vmp[sz2][sum2];
    }

    std::cout<<((ans << 0) + sz1)<<std::endl;

    
}


int main()
{
    int w = 1;
    // std::cin>>w;
    
    
    
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
