
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








// 263813266 	Jun/03/2024 10:05UTC+8 	Ouha 	1883D - In Love 	C++20 (GCC 13-64) 	Accepted 	593 ms 	4900 KB

// the min r  vs  the max l
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::string op2;
    int st, en;
    std::map<int, int> mapr, mapl;
    int cnt = 0;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>op2>>st>>en;
        if (op2 == "+") {
            ++mapr[en];
            ++mapl[st];
            ++cnt;
        } else {
            --mapr[en];
            --mapl[st];
            --cnt;
            if (mapr[en] == 0)
                mapr.erase(en);
            if (mapl[st] == 0)
                mapl.erase(st);
        }
        // if (cnt > 1 && )
        if (!mapr.empty() && mapr.cbegin()->first < mapl.crbegin()->first) {
            std::cout<<"YES\n";
        } else {
            std::cout<<"NO\n";
        }
    }
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
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
