
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
#include <map>
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





// 310525301 	Mar/14/2025 15:47UTC+8 	Ouha 	1823C - Strongly Composite 	C++20 (GCC 13-64) 	Accepted 	77 ms 	4000 KB 



// 拆分到质数，然后 2个相同的质数 就是一个 b的元素
// 似乎 factor的 count必须偶数？ 不然剩余的质数无法组成 强合数吧, bu 2,3,5->30->{1,2,3,5,6,15,10}. 3ge 不，可以和 2个相同质数 的 合并  2，2，3 12 不 为了最多
std::vector<int> vprm;
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::map<int, int> mp2;
    int t2;
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        for (int i = 0; i < vprm.size() && t2 > 1; ++i) {
            while (t2 % vprm[i] == 0) {
                ++mp2[vprm[i]];
                t2 = t2 / vprm[i];
            }
        }
        if (t2 > 1) {
            ++mp2[t2];
        }
    }

    
    int ans = 0;
    int cnt1 = 0;
    for (std::map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++) {
        t2 = it->second;
        ans += t2 / 2;
        cnt1 += t2 % 2;
    }

    ans += cnt1 / 3;
    cnt1 %= 3;

    std::cout<<ans<<std::endl;
    
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


    bool barr[3163] = {false}; // can be divide
    vprm.push_back(2);
    for (int i = 3; i < 3163; i += 2) {
        if (!barr[i]) {
            vprm.push_back(i);
            for (int j = i + i; j < 3163; j += i) {
                barr[j] = true;
            }
        }
    }

    
    
    for (int _ = 0; _ < w; ++_)
    {
        if (_ == -1)
            fun1(true);
        fun1();
        
        #ifdef __test
        std::cout << "   ---/////--------/////---" << std::endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
