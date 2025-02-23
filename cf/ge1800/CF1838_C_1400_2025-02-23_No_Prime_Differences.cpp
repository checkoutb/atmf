
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





// 307405194 	Feb/23/2025 20:03UTC+8 	Ouha 	1838C - No Prime Differences 	C++20 (GCC 13-64) 	Accepted 	250 ms 	100 KB 

// 坑还是挺多的。。 1的前面必须是 1+3*sz1 ， 不然 5 4 过不了  .. 所以 必然是 vi[0]==0 或者说 vi[0] = 1 + sz1.
// 所以 也可以当作 分成2部分， 一部分是 1+偶数*sz1 另外一部分是 1+奇数*sz1,奇数那侧需要注意 1+sz1 不能和1 相邻




// ..如果 列 不是 质数，那么直接 1234...填充， 因为 左右相差1， 上下相差 列。
// 如果列是质数， 如果行不是质数，那么 竖着填充
// 如果行是质数，列是质数。。。 ？
// 1 6 11 16 21
// 6 16 1 21 11
// 1 8 15 22 29 36 43
// 43  29  15  1  22  36 8
// 以1为中间列/行， 2边分别是 2n+1，3n+1。   2n+1的外面是 4n+1,6n+1 8n+1...  3n+1的外面是 5n+1，7n+1.。。 最后把 n+1 放入最外层的缺口。
// 不判断 prime了，直接 1放中间
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2;

    // std::vector<std::vector<int>> vvi(sz1, std::vector<int>(sz2));
    // int mx = sz1 * sz2;

    // vvi[0][sz2 / 2] = 1;
    // for (int i = sz2 / 2 - 1; i >= 0; --i) {
    //     vvi[0][i] = 2 * sz1 + vvi[0][i + 1];
    // }
    // for (int i = sz2 / 2 + 1; i < sz2; ++i) {
    //     vvi[0][i] = 
    // }
    

    int mx = sz1 * sz2;
    std::vector<int> vi(sz2);
    vi[sz2 / 2] = 1;
    vi[sz2 / 2 - 1] = 1 + 3 * sz1;
    for (int i = sz2 / 2 - 2; i >= 0; --i) {
        if (2 * sz1 + vi[i + 1] < mx)
            vi[i] = 2 * sz1 + vi[i + 1];
        else
            break;
    }

    for (int i = sz2 / 2 + 1; i < sz2; ++i) {
        if (2 * sz1 + vi[i - 1] < mx)
            vi[i] = 2 * sz1 + vi[i - 1];
        else
            break;
    }
    if (vi[0] == 0) {
        vi[0] = 1 + sz1;
    } else {
        vi.back() = 1 + sz1;
    }

    for (int i = 0; i < sz1; ++i) {
        int t2 = i;
        for (int j = 0; j < sz2; ++j) {
            std::cout<<vi[j] + t2<<' ';
        }
        std::cout<<std::endl;
    }
    
    
}

// bool isPrime(int a) {
//     for (int i = 2; i * i <= a; ++i) {
//         if (a % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }


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
