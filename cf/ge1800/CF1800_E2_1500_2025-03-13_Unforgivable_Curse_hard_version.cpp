
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





// 310370344 	Mar/13/2025 16:19UTC+8 	Ouha 	1800E2 - Unforgivable Curse (hard version) 	C++20 (GCC 13-64) 	Accepted 	77 ms 	4000 KB



// 
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2;

    std::string s, t;
    std::cin>>s>>t;

    int arr[26] = {};
    bool b2 = true;
    for (int i = 0; i < sz1; ++i) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
        if (s[i] != t[i]) {
            b2 = false;
        }
    }

    if (b2) {
        std::cout<<"yes"<<std::endl;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (arr[i] != 0) {
            std::cout<<"no"<<std::endl;
            return;
        }
    }
    
    int st = sz1 - sz2;
    int en = sz2 - 1;
    st = std::max(0, st);
    en = std::min(en, sz1 - 1);
    while (st <= en) {
        if (s[st] != t[st]) {
            std::cout<<"no"<<std::endl;
            return;
        }
        ++st;
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
