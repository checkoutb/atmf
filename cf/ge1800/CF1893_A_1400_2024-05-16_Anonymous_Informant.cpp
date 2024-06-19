
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
// 261153626 	May/16/2024 14:48UTC+8 	Ouha 	1893A - Anonymous Informant 	C++20 (GCC 13-64) 	Accepted 	359 ms 	0 KB


// †
// first meet
// 0,2,0,4,0,2    040202, g   020204 020402
// last element is last fixed point x
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>kk;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    int idx = sz1 - 1;
    while (kk-- > 0) {
        #ifdef __test
        std::cout<<kk<<", "<<idx<<", "<<vi[idx]<<std::endl;
        #endif
        
        if (vi[idx] == -1) {
            kk = 0;
            break;
        }
        if (vi[idx] > sz1) {
            kk = 1;
            break;
        }
        int t2 = idx;
        idx = (idx - vi[idx] + sz1) % sz1;
        vi[t2] = -1;
        if (vi[idx] == -1) {
            //kk = 0;
            //break;
        } else {

        }
        if (kk == 0) {
            break;
        }
    }
        
    
    if (kk == 0)
        std::cout<<"Yes\n";
    else
        std::cout<<"No\n";
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










