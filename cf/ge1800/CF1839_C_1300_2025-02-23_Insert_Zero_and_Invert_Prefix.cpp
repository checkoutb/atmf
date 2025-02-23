
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





// 307396812 	Feb/23/2025 18:45UTC+8 	Ouha 	1839C - Insert Zero and Invert Prefix 	C++20 (GCC 13-64) 	Accepted 	77 ms 	100 KB



// 只能放入0， 所以最后一个是1的话，就不可能
// 这个题目和 binary cafe 一样啊， 灵光不闪 就没机会。
// 这把我闪了：  寻找 11..110 这种。 这种就是 push_front 然后 下标=1的个数处 插入一个0.  而且从后往前找。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    if (vi.back() != 0) {
        std::cout<<"NO\n";
        return;
    } else {
        std::cout<<"YES\n";
    }

    int t2 = 0;
    int cnt = 0;
    std::vector<int> v2;
    for (int i = sz1 - 1; i >= 0; --i) {
        if (vi[i] == 0) {
            t2 = i;
            cnt = 0;
            // v2.push_back(i);
            --i;
            while (vi[i] == 1) {
                --i;
                ++cnt;
                v2.push_back(0);
            }
            ++i;
            v2.push_back(cnt);
        }
    }
    // std::reverse(std::begin(v2), std::end(v2));
    for (int i : v2) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
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
