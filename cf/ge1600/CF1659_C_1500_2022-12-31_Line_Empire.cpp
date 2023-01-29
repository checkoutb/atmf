
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
//#include <numeric>            // accumulate
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








// 187402279 	Dec/31/2022 11:33UTC+8 	Ouha 	1659C - Line Empire 	GNU C++17 	Accepted 	358 ms 	2400 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    long long mov, att;
    cin >> mov >> att;
    
    vector<int> vi(sz1);

    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    vector<long long> v2(sz1);
    long long sum2 = 0LL;
    for (int i = sz1 - 2; i >= 0; --i)
    {
        sum2 += att * (sz1 - 1 - i) * (vi[i + 1] - vi[i]);
        v2[i] = sum2;
    }

    long long ans = sum2 + att * (sz1) * vi[0];

    for (int i = 0; i < sz1; ++i)
    {
        ans = min(ans, v2[i] + 1LL * (mov + att) * vi[i]);
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
