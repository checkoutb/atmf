
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

// D

//int res = (1 << 30) - 1;
//for (int i = 0; i < n; ++i)
//    if (a[i] != i) res &= a[i];
//
// no sort...





// 173412324 	Sep/25/2022 18:13UTC+8 	Ouha 	1682B - AND Sorting 	GNU C++17 	Accepted 	280 ms 	1600 KB

// min ?  元素越多， bit and 只会越小。  不是min。 应该是最小集合， 不，
// 1 2 3  213 231 132 312 321   是可以全排列的。
// 不， 可能最小元素 有一个 bit 是1， 但是 其它元素， 有的是1， 有的不是1.
// uf？ 
// 应该就是 最小集合的 & , 不然愧对 1100
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);
    myvi v2(sz1);
    int t2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        vi[i] = t2;
        v2[i] = t2;
    }
    
    sort(begin(v2), end(v2));
    
    int ans = INT_MAX;
    
    for (int i = 0; i < sz1; ++i)
    {
        if (vi[i] != v2[i])
        {
            ans &= vi[i];
        }
    }
    cout << ans << endl;
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
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
