
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




// g.




// 这种题目第一次见。。
// sz1=20,  -20 - 20.
// op 50， no down
// ai = ai+aj
//
// <=, 找到最后一个正数，然后不停 << 1.  没说必须<INT_MAX。 而且 20<<20 也不超过INT_MAX
//     当遍历过 这个正数后，不能再对它进行 << 1 了。不过 应该无所谓，直接+前面的。
// 如果没有正数。 全0，不需要操作。
// 找到 第一个负数， 也是不停翻倍。 从后往前遍历。
//
// 。。这种是 找 最后一个正/负数, 还是找 最大/最小?
// 还有，是否找一个 最长连续非降子数组，然后前面的-，后面的+
//
// 10,9,8,7,6,5,4,3,2,1,-1,-2,-3,-4,-5,-6,-7,-8,-9,20
// 如果vi[0] 是最大的呢，好像也可以，加2次前面的，
//
// 1,0,0,0,0,0,0
// 0,0,0,0,0,0,-1
// 1,-1,-1,-1
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<std::pair<int, int>> vpii;

    int mx = 0;
    int mn = 0;
    for (int i : vi) {
        mx = std::max(mx, i);
        mn = std::min(mn, i);
    }

    if (mx == mn) { // sz1 == 1
        std::cout<<0<<std::endl;
        return;
    }

    if (mx > 0) {
        // 0 -> sz1, +mx
        int mxidx = 1;
        for (int i = 2; i < sz1; ++i) {
            if (vi[i] >= vi[mxidx]) {
                mxidx = i;
            }
        }
        
        for (int i = 1; i < sz1; ++i) {
            if (vi[i - 1] <= vi[i])
                continue;
            
            if (i < mxidx) {
                int t2 = vi[i] + vi[i - 1];
                int t3 = vi[i] + vi[mxidx];
                if (t2 >= vi[i - 1] && t2 <= t3) {
                    vpii.push_back(std::make_pair(i, i - 1));
                    vi[i] = t2;
                } else if (t3 >= vi[i - 1]) {
                    vpii.push_back(std::make_pair(i, mxidx));
                    vi[i] = t3;
                } else {
                    while (vi[i] + vi[mxidx] < vi[i - 1]) {
                        vpii.push_back(std::make_pair(mxidx, mxidx));
                        vi[mxidx] += vi[mxidx];
                    }
                    vpii.push_back(std::make_pair(i, mxidx));
                    vi[i] += vi[mxidx];
                }
            } else if (i == mxidx){
                while (vi[i] < vi[i - 1]) {
                    vpii.push_back(std::make_pair(i, i));
                    vi[i] += vi[i];
                }
            } else {
                while (vi[i - 1] > vi[i]) {
                    vpii.push_back(std::make_pair(i, i - 1));
                    vi[i] += vi[i - 1];
                }
            }
        }

    } else {
        // sz1 -> 0, +mn .. mn < 0
        int mnidx = sz1 - 2;
        for (int i = sz1 - 3; i >= 0; --i) {
            if (vi[i] <= vi[mnidx])
                mnidx = i;
        }
        
        for (int i = sz1 - 2; i >= 0; --i) {
            
        }
    }
    
    

    std::cout<<vpii.size()<<std::endl;
    for (auto& [a, b] : vpii) {
        std::cout<<a<<' '<<b<<std::endl;
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
