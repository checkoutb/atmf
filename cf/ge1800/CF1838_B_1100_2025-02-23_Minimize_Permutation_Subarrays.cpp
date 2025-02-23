
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





// Feb/23/2025 20:20UTC+8 	Ouha 	1838B - Minimize Permutation Subarrays 	C++20 (GCC 13-64) 	Accepted 	93 ms 	0 KB



// 1 - n
// 似乎是 把1换到n前面 或 把n换到1后面 ?
// 或者说， 把 n 放到 1 和 2 中间？ yes!
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    int idx1 = -1;
    int idx2 = -1;
    int idxn = -1;

    for (int i = 0; i < sz1; ++i) {
        if (vi[i] == 1)
            idx1 = i;
        else if (vi[i] == 2)
            idx2 = i;
        else if (vi[i] == sz1)
            idxn = i;
    }

    ++idx1, ++idx2, ++idxn;
    if (idx1 < idx2) {
        if (idxn < idx1) {
            std::cout<<idxn<<' '<<idx1<<std::endl;
        } else if (idxn > idx2) {
            std::cout<<idxn<<' '<<idx2<<std::endl;
        } else {
            // any
            std::cout<<idx1<<' '<<idx1<<std::endl;
        }
    } else {
        // idx2 < idx1
        if (idxn < idx2) {
            std::cout<<idxn<<' '<<idx2<<std::endl;
        } else if (idxn > idx1) {
            std::cout<<idxn<<' '<<idx1<<std::endl;
        } else {
            std::cout<<"1 1\n";
        }
    }
    
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
