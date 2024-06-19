
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
#include <limits.h>   // INT_MAX

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







// 264570449 	Jun/07/2024 17:13UTC+8 	Ouha 	1881E - Block Sequence 	C++20 (GCC 13-64) 	Accepted 	265 ms 	0 KB


// len + element
// ? dp ?
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<int> v2(sz1, INT_MAX); // min remove

    for (int i = 0; i < sz1; ++i) {
        int t2 = vi[i] + i; // end
        if (t2 >= sz1) {
            v2[i] = std::min(v2[i], (i == 0 ? 0 : v2[i - 1]) + 1);
        } else {
            v2[t2] = std::min(v2[t2], (i == 0 ? 0 : v2[i - 1]));
            v2[i] = std::min(v2[i], (i == 0 ? 0 : v2[i - 1]) + 1);
        }
    }

    #ifdef __test
    for (int i : v2) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
    #endif
    
    std::cout<<v2[sz1 - 1]<<std::endl;
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
