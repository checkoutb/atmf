
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




// 306869235 	Feb/19/2025 20:46UTC+8 	Ouha 	1841B - Keep it Beautiful 	C++20 (GCC 13-64) 	Accepted 	92 ms 	0 KB 


// first_ele ...

// 1 down
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    bool down = false;

    int t2 = 0;
    int last_ele = -1;
    int first_ele = -1;
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>t2;
        if (first_ele == -1)
            first_ele = t2;

        #ifdef __test
        // std::cout<<first_ele<<", "<<last_ele<<", "<<t2<<std::endl;
        #endif
        
        if (!down) {
            if (t2 >= last_ele) {
                std::cout<<1;
                last_ele = t2;
            } else {
                if (down) {  // unreachable
                    std::cout<<0;
                } else {
                    if (t2 <= first_ele) {
                        std::cout<<1;
                        down = true;
                        last_ele = t2;
                    } else {
                        std::cout<<0;
                    }
                }
            }
        } else {
            if (t2 >= last_ele && t2 <= first_ele) {
                std::cout<<1;
                last_ele = t2;
            } else {
                std::cout<<0;
            }
        }
    }
    
    std::cout<<std::endl;
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
