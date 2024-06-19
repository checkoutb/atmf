
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
// 261146377 	May/16/2024 13:49UTC+8 	Ouha 	1894B - Two Out of Three 	C++20 (GCC 13-64) 	Accepted 	78 ms 	0 KB 


// 1,2,3
// ai=aj, bi=1,bj=2
// ai=aj, bi=1,bj=3
// ai=bj, bi=2,bj=3
// if and only if 2
// -1
// all x, 1111222
// there exists.
//
// 1. all x, 121212121, no 3
// 2. all y, 1313133311, no 2
// 3. other, all 1
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        std::cin>>vi[i];
    }
    bool arr[101] = {false};
    int cnt = 0;

    std::vector<int> v2(sz1);
    int lst = -1;
    for (int i = 0; i < sz1; ++i) {
        if (arr[vi[i]]) {
            if (cnt < 2 && vi[i] != lst) {
                ++cnt;
                v2[i] = cnt + 1;
                lst = vi[i];
            } else {
                v2[i] = 1;
            }
        } else {
            v2[i] = 1;
            arr[vi[i]] = true;
        }
    }

    if (cnt == 2) {
        for (int i : v2) {
            std::cout<<i<<' ';
        }
        std::cout<<std::endl;
    } else {
        std::cout<<-1<<std::endl;
    }
    
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt:";
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
