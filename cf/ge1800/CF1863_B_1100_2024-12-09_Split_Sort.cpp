
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
//#include <iomanip>    // std::setprecision(10)
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





// 295701861 	Dec/09/2024 13:38UTC+8 	Ouha 	1863B - Split Sort 	C++20 (GCC 13-64) 	Accepted 	140 ms 	0 KB



// <p, >=p
// 如果在数列中 1,2,..x 已经有序， x+1 在 x 前面，那么需要一次 操作
// 就是看 前面有没有比当前大的， 有(不管有几个)就 操作一次，  不。
// 当前值是 x，如果 x+1 在前面，那么 操作一次。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    
    std::vector<bool> vb(sz1 + 2); // has appeard?

    int cnt = 0;
    
    for (int a : vi) {
        if (vb[a + 1])
            ++cnt;
        vb[a] = true;
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
