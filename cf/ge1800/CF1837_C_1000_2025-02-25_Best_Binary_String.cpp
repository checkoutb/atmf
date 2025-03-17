
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





// 307657944 	Feb/25/2025 20:30UTC+8 	Ouha 	1837C - Best Binary String 	C++20 (GCC 13-64) 	Accepted 	62 ms 	100 KB 



// 0,1,?
// ..真绕啊。
// 似乎只要 和 最近的 非? 一致就可以了？
void fun1()
{
    std::string str;
    std::cin>>str;

    //int t2 = -1;  // -1: none, 0:0, 1:1
    char ch = 'A'; // A:none, '0':0, 1:1
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '?') {
            if (ch != 'A')
                str[i] = ch;
        } else {
            ch = str[i];
        }
    }

    if (ch == 'A') {
        for (int i = 0; i < str.size(); ++i) {
            str[i] = '1';
        }
    } else {
        ch = 'A';
        for (int i = str.size() - 1; i >= 0; --i) {
            if (str[i] == '?') {
                if (ch != 'A')
                    str[i] = ch;
            } else {
                ch = str[i];
            }
        }
    }
    std::cout<<str<<std::endl;
    
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
