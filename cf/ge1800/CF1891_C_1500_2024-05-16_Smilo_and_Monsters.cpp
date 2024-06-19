
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
// 261159800 	May/16/2024 15:42UTC+8 	Ouha 	1891C - Smilo and Monsters 	C++20 (GCC 13-64) 	Accepted 	421 ms 	0 KB



// x = 0
// 1. kill one, ++x
// 2. kill x, x = 0

void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::ranges::sort(vi);

    int lst = sz1 - 1;
    int x = 0;
    long long cnt = 0;       // ll
    for (int i = 0; i <= lst; ++i) {
        if (i == lst) {
            // (x + need) = vi[lst] - need
            // ++cnt;
            int t2 = (vi[lst] - x) / 2 + (vi[lst] - x) % 2 + 1;
            t2 = std::min(t2, vi[lst]);
            cnt += t2;
            
        } else {
            x += vi[i];
            if (x >= vi[lst]) {  // kill vi[lst]
                if (i == lst - 1) {
                    int t2 = x - vi[lst];
                    cnt += vi[i] - t2;
                    cnt += std::min(t2 / 2 + 1 + t2 % 2, t2);
                        
                    ++cnt;
                    --lst;
                } else {
                    cnt += vi[i];
                    x = x - vi[lst]; // when x == vi[lst], kill lst, x=0, then type 1 kill remain vi[i]
                    --lst;
                    ++cnt;
                }
            } else { // cannot kill vi[lst]
                cnt += vi[i];
            }
        }
    }
    
    std::cout<<cnt<<std::endl;
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
