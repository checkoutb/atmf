
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


// 为了 无限，所以 必须有一个 大于等于2的能整除n
// 用埃氏筛 main中预先计算 所有数的 最小除数。
// 如果 n的最小除数 大于 m 就是yes，就是能终止。

// 就是， 转换思路，变成： 能不能 无限循环。 为了无限循环，你肯定要把 m 变成 n的某个除数。
// 只要 m 大于这个除数，我们就有办法 变到这个除数。


// 看了hint 还是不理解。 无限次后肯定0 或者 某个非0. 


// tle.. 用埃氏筛 错了.  直接mod下降也是错。不知道该怎么下降了。。
// 有个想法，但是太难了： 当前m个算法，判断是否可以 m-1个 并列最大， 是否m-2个并列最大。。

// ... 并列最多 就同时进入下一轮。
void fun1()
{
    int sz1, sz2, kk;
    // std::cin >> sz1;
    
    int n, m;
    std::cin>>n>>m;

    if (n == 1 || m == 1) {
        std::cout<<"yes"<<std::endl;
        return;
    }
    
    if (n % 2 == 0 || n <= m) {
        std::cout<<"no"<<std::endl;
        return;
    }

    while (m > 1) {
        if (n % m == 0) {
            std::cout<<"no"<<std::endl;
            return;
        }
        m = n % m;
    }
    // for (int i = 2; i * i <= m; ++i) {
    //     if (n % i == 0) {
    //         std::cout<<"no"<<std::endl;
    //         return;
    //     }
    // }
    
    // int t2;
    // while (m > 1) {
    //     if (n % m == 0) {
    //         std::cout<<"no"<<std::endl;
    //         return;
    //     }
    //     --m;
    //     // t2 = n % m;
        

    //     // m = t2;
    // }
    std::cout<<"yes"<<std::endl;
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
