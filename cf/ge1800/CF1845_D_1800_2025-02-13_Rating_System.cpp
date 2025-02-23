
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


// D
// min sum segment

// 1. /// 大约应该懂了。。但是。。感觉 无法证明。
//
// 1. 假设k是某个值，那么 第一次低于k，到 最后一次低于k， 这个区间 是可以 删除的。
// 2. [l, r] 就是这个区间， 如果 [r+1, x] 是小于0的， 那么 [l, x] 才是 最小的区间， 和 [l,r]是最小区间不符合。 所以 [r+1, x] 始终大于等于0
// mx 是前缀和里 最大的， sum 是加上当前值后的前缀和， 如果 mx-sum 更大了，说明 下降得更多了，那么 这个区间[mx所在下标+1， 当前下标]要删除。 mx 就是 k



// g





// 升降， 一旦到达 k后， 不可能再小于 k。
// 求使得最终rating最大的 k
// 二分？..和谁比较？  应该是 开口向下的 抛物线，不是抛物线，应该是 阶梯。 并不平滑，似乎没有办法 通过 选2个点 来决定 取哪一半
//
//  1. 从前往后，遍历vi， 每次 vi[i]的值 从正变成负 (即 vi[i]正，vi[i+1]负，那么 计算完 vi[i] 后的值 就是 k的可能值) ，这个就是 一个 k的可能值。
//  2. 从后往前， 最后一个是负数，需要 拿掉( 最后的时候额外算下)。 计算 V。 V的起点是 k。 所以只需要计算 V的后一半 / 。。但是好像不对的。。
// 先处理下，将连续的+，连续的-，合并。
// 还是说 取 最小负数的 前一个下标的结果 作为 k ... 如果 相同呢？
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi;
    int t2 = 0;
    std::cin>>t2;
    vi.push_back(t2);

    for (size_t i = 1; i < sz1; ++i) {
        std::cin>>t2;
        if ((t2 < 0 && vi.back() < 0) || (t2 > 0 && vi.back() > 0))
            vi.back() += t2;
        else
            vi.push_back(t2);
    }

    long long ans = -1LL;
    long long mx = -1LL;
    if (vi[0] < 0) {
        
    }
    
    t2 = 0;
    for (size_t i = 0; i < vi.size(); ++i) {
        if (vi[i] < 0) {
            
        } else {
            
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
