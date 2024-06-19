
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







// AC
// 261990392 	May/21/2024 17:27UTC+8 	Ouha 	1884B - Haunted House 	C++20 (GCC 13-64) 	Accepted 	109 ms 	0 KB


// 2^i, i>=1
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::string str;
    std::cin>>str;

    std::vector<long long> vi(sz1, -1);
    int lst = sz1 - 1;
    for (int i = sz1 - 1; i >= 0; --i) {
        if (str[i] == '1') {
            lst = std::min(lst, i - 1);
            while (lst >= 0 && str[lst] == '1') {
                --lst;
            }
            
            if (lst >= 0) {// find a 0
                vi[i] = i - lst;
                vi[i] += i + 1 < sz1 ? vi[i + 1] : 0;
                str[lst] = '1';
                --lst;
            } else {
                break;
            }
        } else {
            vi[i] = i + 1 < sz1 ? vi[i + 1] : 0;
        }
    }

    std::ranges::reverse(vi);
    for (long long i : vi) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    
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
