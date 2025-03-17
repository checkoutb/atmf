
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






// g




// abac
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::string str;
    std::cin>>str;

    int ans = sz1 - 1;
    for (int i = 3; i < sz1; i += 2) {
        if (str[i] == str[i - 2] && str[i - 1] == str[i - 3]) {
            --ans;
        }
    }
    bool b2 = true;
    for (int i = 4; i < sz1; i += 2) {
        if (str[i] == str[i - 2] && str[i - 1] == str[i - 3]) {
            --ans;
            if (b2) {
                if (str[i] == str[i - 1]) {
                    --ans;
                }
                b2 = false;
            }
        } else {
            b2 = true;
        }
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
