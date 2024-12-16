
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



// 296792434 	Dec/16/2024 13:13UTC+8 	Ouha 	1861D - Sorting By Multiplication 	C++20 (GCC 13-64) 	Accepted 	436 ms 	100 KB


// 本来都准备g了， 但是看了一眼， 就那一眼， 然后灵光一闪， 就 修改了 ans 的初始值， 然后 AC 了。

//    <无题>
// 众里寻他千百度
// 踏破铁鞋无觅处
// 时来天地皆同力
// 柳暗花明又一村/直挂云帆济沧海/扶摇直上九千里

// 柳暗花明又一村，气势不太够， 百度了下："柳暗花明又一村类似的诗句":
// 直挂云帆济沧海, 可惜前面2句是 找东西。。
// 何妨吟啸且徐行, 感觉可以，吟啸:天地同力后的快乐心情；徐行:不忘初心(前2句构建的意境)   好像也不行，要转好几个弯。 气势也不够， 前3句都是 夸张的写法，
// 任尔东西南北风, 前面是找东西。而且天地同力了，哪还有风哦。
// 
// 直挂云帆济沧海 应该最合适， 4句都带有 夸张。 找东西 也可以是 找一条路。

// 还有 扶摇直上九千里。

// 不过押韵。。




// g




// 9
// 10 5 10 9 6 9 8 9 5   // 4
// -100 -50
// -100 -50 -20 -18
// -100 -50 -20 -18 6 9 80 90 50
//                            500

// 应该是 前缀+后缀, 从前往后，需要乘负数， 从后往前，需要乘正数

// 10 5 4 6 7 5  只乘负数
// -100 -50 4 6 7 5
// -100 -50 -40 6 7 5
// -100 -50 -40 -18 7 5
//                  -14 5
// 只乘正数
// ...  500
//    40 60 70 500
// 10 25 40 60 70 500
//
// -10 -5 4 6 7 5
// -10 -5 4 6 7 50  2ci

// 所以是： 找到 严格上升 子数组 ( 可以只有一个元素)， 子数组前的乘负数， 子数组后的乘正数 ？


void fun1() {
    int sz1;
    std::cin>>sz1;
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    if (sz1 == 1) {
        std::cout<<"0\n";
        return;
    }
    
    std::vector<int> v2(sz1);  // <= idx, all < 0
    v2[0] = 1;
    for (int i = 1; i < sz1; ++i) {
        if (vi[i - 1] <= vi[i]) {
            v2[i] = v2[i - 1] + 1;
        } else {
            v2[i] = v2[i - 1];
        }
    }

    int t2 = 0;
    // int ans = sz1 << 1;
    int ans = v2[v2.size() - 2];
    for (int i = sz1 - 2; i >= 0; --i) {
        if (vi[i] < vi[i + 1]) {
            ;
        } else {
            t2 += 1;
        }
        ans = std::min(ans, t2 + (i > 0 ? v2[i - 1] : 0));
    }

    std::cout<<ans<<std::endl;
}



// [l, r] *x   x can be -12341234
// < < <  no ==
// min op cnt
// 1,2,3,11,5    5*3
// 11,1,2,3,5  11*-1   or   1,2,3,5 * 100
//
// 5 4 3 2 5 1    5,4,3,2 * -1,  1*100
//
// 如果开头是 严格下降，那么可以 乘负数，  其他情况 都是 后面 * 正数？
// 因为负数会改变 大小关系，所以前面已经有序了，就不可能乘负数。  ai是正数
// * 正数 不会改变 大小关系。
void fun1___ERRR()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    if (sz1 == 1) {
        std::cout<<"0\n";
        return;
    }

    int ans = 0;
    int idx = 0;
    if (vi[0] > vi[1]) {
        ans = 1;
        while (idx + 1 < sz1 && vi[idx] > vi[idx + 1]) {
            ++idx;
        }
    }

    // idx <= idx + 1

    for (++idx; idx < sz1; ++idx) {
        if (vi[idx] <= vi[idx - 1]) {
            ++ans;
        }
    }

    std::cout<<ans<<std::endl;
    
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
