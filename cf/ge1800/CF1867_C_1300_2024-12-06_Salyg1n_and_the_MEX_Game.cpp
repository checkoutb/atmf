
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
#include <set>
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

#include <cstdlib>

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE





// 295160813 	Dec/06/2024 11:36UTC+8 	Ouha 	1867C - Salyg1n and the MEX Game 	C++20 (GCC 13-64) 	Accepted 	936 ms 	6700 KB 



// min not-exist
// ..应该是第一道 交互题吧， 有点乱。
// 但是看不懂 第一个例子，为什么bob第一次是 -7，而不是 -1.  实际上，alice直接+0，那么直接结束，R是4.
// 但是 alice选择+8，为什么？  而且bob竟然选择 -7， 看不懂。 bob直接-1，那么就变成 {2,3,5,7,8}， 0和1 alice 永远补不上啊，那么 mex就是0 了，符合bob的立场啊。
// 第二个例子 {0,1,2} 也不懂，alice+3，变成{0,1,2,3}，但是bob为什么-0？ 这种情况下应该-2啊。 bob如果-0，那么alice+0，bob就无法操作了，游戏结束，R=4，  但是 bob选择-2，那么alice只能+2，然后bob-1，alice只能+1，然后bob-0，alice只能+0 。。好吧，还是 4.
// 在我看来 alice 的操作就是 补最小值。 因为bob始终是 移除最小值。
//
// 还是无法理解第一个例子，alice为什么不是直接补0，直接结束游戏。   bob在alice补8之后，为什么不是 移除1，来让R变成1.
// 还有就是，让结果至少是R，但是没有告诉我R是多少啊。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::set<int> set2;
    int t2 = 0;
    int idx = 0;
    while (set2.size() < sz1 * 2 + 1) {
        if (idx < sz1 && vi[idx] == t2) { // out of bound...
            idx++;
            t2++;
            continue;
        }
        set2.insert(t2);
        t2++;
    }

    while (true) {
        t2 = *set2.begin();
        set2.erase(set2.begin());
        std::cout<<t2<<std::endl;
        std::cout.flush();

        std::cin>>t2;  // bob remove

        if (t2 >= 0) {
            set2.insert(t2);
        } else if (t2 == -1) {
            return;
        } else {
            std::exit(EXIT_FAILURE);
        }
    }
    
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
