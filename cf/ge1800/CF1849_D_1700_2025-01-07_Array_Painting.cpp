
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





// 300011619 	Jan/07/2025 17:09UTC+8 	Ouha 	1849D - Array Painting 	C++20 (GCC 13-64) 	Accepted 	171 ms 	100 KB

// 提交的那次是 Accepted， 刷新下就是 Happy New Year! 了。 所有 AC 都是 HNY。



// 0,1,2  blue
// 1 coin blue->red
// red+blue, desc red, blud->red
//
// 按0分割， 如果不是 全1. 1个coin 就可以 扩展到 两侧的 各一个0 变成red。 如果全1，1个coin，只能某侧的0变red
// 只有 0,1,2
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    bool exist2 = false;
    int lastnot0 = -1;
    int ans = 0;
    for (int i = 0; i < sz1; ++i) {
        int t2 = vi[i];
        switch (t2) {
        case 0:
            if (lastnot0 != -1) {
                ++ans;
                if (exist2) { // 2 side's 0, both change
                    int j = lastnot0 - 1;
                    if (j < 0)
                        j = 0;
                    for (; j <= i; ++j) {
                        vi[j] = 3;
                    }
                    exist2 = false;
                } else {
                    int j = lastnot0 == 0 ? 0 : lastnot0 - 1;
                    if (vi[j] == 0) {  // only change one side 's 0.  prefix 0 is priority
                        for (; j < i; ++j) {
                            vi[j] = 3;
                        }
                    } else {
                        for (; j <= i; ++j)
                            vi[j] = 3;
                    }
                }
                lastnot0 = -1;
            }
            break;
        case 1:
            if (lastnot0 == -1)
                lastnot0 = i;
            break;
        case 2:
            if (lastnot0 == -1)
                lastnot0 = i;
            exist2 = true;
            break;
        }
    }

    if (lastnot0 != -1) {
        ans++;
        for (int j = lastnot0 == 0 ? 0 : lastnot0 - 1; j < sz1; ++j)
            vi[j] = 3;
    }

    for (int i = 0; i < sz1; ++i) {
        if (vi[i] == 0)
            ++ans;
    }
    
    std::cout<<ans<<std::endl;
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    //std::cin>>w;
    
    
    
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
