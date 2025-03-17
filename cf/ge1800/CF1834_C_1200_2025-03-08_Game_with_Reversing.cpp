
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






// 309491313 	Mar/08/2025 20:15UTC+8 	Ouha 	1834C - Game with Reversing 	C++20 (GCC 13-64) 	Accepted 	62 ms 	4000 KB 


// 1-0, 2-2, 3-2, 4-4
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::string s;
    std::string t;
    std::cin>>s>>t;

    // s=t
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < sz1; ++i) {
        if (s[i] != t[i]) {
            cnt += 1;
        }
    }
    // if (cnt == 0) {
    //     cnt = 1;
    // }
    ans = cnt + cnt / 2 * 2;
    
    // s=prev t
    cnt = 0;
    for (int i = 0; i < sz1; ++i) {
        if (s[i] != t[sz1 - 1 - i]) {
            cnt ++;
        }
    }
    if (cnt == 0)
        cnt = 1;
    cnt += (cnt - 1) / 2 * 2 + 1;
    ans = std::min(ans, cnt);
    
    
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
