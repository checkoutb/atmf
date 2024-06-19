
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







// 264659775 	Jun/08/2024 09:11UTC+8 	Ouha 	1879C - Make it Alternating 	C++20 (GCC 13-64) 	Accepted 	62 ms 	4000 KB 




// 1010  or 0101   first char
// mCn * m!
// 000111   -2 -2,  3 * 3 * 4!
void fun1()
{
    int sz1, sz2, kk;
    // std::cin >> sz1;

    std::string s;
    std::cin>>s;
    sz1 = s.size();
    const int MOD = 998244353;
    long long ans = 1;
    int cnt = 0;
    int t2 = 0;
    for (int i = 0; i < sz1; ++i) {
        t2 = 1;
        while (i + 1 < sz1 && s[i + 1] == s[i]) {
            ++t2;
            ++i;
        }
        ans = (ans * t2) % MOD;
        cnt += (t2 - 1);
    }
    std::cout<<cnt<<' ';
    while (cnt > 1) {
        ans = (ans * cnt) % MOD;
        --cnt;
    }
    
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
