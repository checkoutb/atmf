
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
//#include <limits.h>   // INT_MAX

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>
//#include <unordered_map>
//#include <string.h>       // memset

using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = vector<vector<int>>;
using myvi = vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE








// 173406235 	Sep/25/2022 17:11UTC+8 	Ouha 	1682C - LIS or Reverse LIS? 	GNU C++17 	Accepted 	389 ms 	800 KB


// longest strictly increasing subseq
// 不重复 个数 /2  ？？ bu 
//  1 2 3 4 4 3 2 1    4
// 但 个数 大于2 是无用的。
// 最大值 肯定守中间， 而且 只需要 一个就可以了
// 倒 V 。
// 计算 最长 LIS， 然后 剩余的 元素 倒序 放 MAX 右侧。  个数>2 的踢掉。
// 剩余的元素 必然是 左侧的 元素的 子集。  就可以开始平衡了
/*

1 2 2 3 3 3 3 3 4 5

把4放到右边
1 2 3 5
            5 4 3 2

        5
      4   _
    3       3
  2           2
1               _
*/
// 就是 累加， 每个元素值 最多加2次。。  max呢
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    sort(begin(vi), end(vi));
    
    int cnt = 2;        // [0] [1]

    for (int i = 2; i < sz1; ++i)
    {
        if (vi[i] != vi[i - 2])
        {
            ++cnt;
        }
    }
    
    cout << (cnt + 1) / 2 << endl;

}


int main()
{
    int w = 1;
    cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {        
        fun1();
        
        #ifdef __test
        cout << "---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
