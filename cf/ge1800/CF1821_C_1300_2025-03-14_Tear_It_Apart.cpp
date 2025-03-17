
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





// 310554195 	Mar/14/2025 19:40UTC+8 	Ouha 	1821C - Tear It Apart 	C++20 (GCC 13-64) 	Accepted 	62 ms 	4000 KB



// log2  >> 1
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    //std::cin >> sz1;

    std::string str;
    std::cin>>str;
    sz1 = str.size();
    
    int arr[26];
    for (int i = 0; i < 26; ++i)
        arr[i] = -1;

    int arr2[26] = {0};

    int t2;
    for (int i = 0; i < sz1; ++i) {
        t2 = i - arr[str[i] - 'a'] - 1;
        if (t2 > arr2[str[i] - 'a'])
            arr2[str[i] - 'a'] = t2;
        arr[str[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; ++i) {
        if (arr[i] != -1) {
            t2 = sz1 - arr[i] - 1;
            if (t2 > arr2[i]) {
                arr2[i] = t2;
            }
        }
    }

    int ans = sz1 * 2;
    for (int i = 0; i < 26; ++i) {
        if (!arr2[i])
            continue;
        t2 = arr2[i];
        int cnt = 0;
        while (t2 > 0) {
            ++cnt;
            t2 >>= 1;
        }
        ans = std::min(ans, cnt);
    }

    if (ans == sz1 * 2)
        ans = 0;

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
