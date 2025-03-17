
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






// 309703117 	Mar/10/2025 12:54UTC+8 	Ouha 	1829G - Hits Different 	C++20 (GCC 13-64) 	Accepted 	374 ms 	4000 KB


// n n+1 / 2
// 1000
void fun1()
{
    int sz1, sz2, kk;
    // std::cin >> sz1;
    ll t2;
    std::cin>>t2;
    
    std::vector<ll> vll;
    ll sum2 = 0;
    for (int i = 1; i <= 2023; ++i) {
        vll.push_back(sum2 + 1); // first element
        sum2 += i;
        if (sum2 >= t2)
            break;
    }
    ll st = t2 - vll.back();
    ll en = st;
    ll ans = 0ll;
    for (int i = vll.size() - 1; i >= 0; --i) {
        ll st2 = st + vll[i];
        ll en2 = en + vll[i];
        while (st2 <= en2) {
            ans += st2 * st2;
            ++st2;
        }
        if (st > 0)
            st -= 1;
        if (en >= i)
            en--;
    }
    
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
