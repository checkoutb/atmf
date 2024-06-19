
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
// 261162912 	May/16/2024 16:08UTC+8 	Ouha 	1891B - Deja Vu 	C++20 (GCC 13-64) 	Accepted 	530 ms 	0 KB


// each j, / 2^x, + 2^(x-1)
// once / 2^x,  never will be / 2^y, y>=x
// / 2^x , suffix x bit all 0
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2;

    std::vector<int> vi(sz1), v2(sz2);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    for (int i = 0; i < sz2; ++i) {
        std::cin>>v2[i];
    }

    std::vector<int> v3;
    int t2 = 33;
    for (int i = 0; i < sz2; ++i) {
        if (v2[i] < t2) {
            v3.push_back(v2[i]);
            t2 = v2[i];
        }
    }

    std::vector<int> v4(v3.size());
    t2 = 0;
    for (int i = v3.size() - 1; i >= 0; --i) {
        t2 |= (1 << v3[i]) / 2;
        v4[i] = t2;
        v3[i] = (1 << (v3[i])) - 1;
    }

    for (int i = 0; i < sz1; ++i) {
        t2 = vi[i];
        for (int j = 0; j < v3.size(); ++j) {
            if ((t2 & v3[j]) == 0) {
                vi[i] += v4[j];
                break;
            }
        }
    }
    
    for (int i = 0; i < sz1; ++i) {
        std::cout<<vi[i]<<' ';
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
