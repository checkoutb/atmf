
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








//186160407 	Dec / 21 / 2022 08:29UTC + 8 	Ouha 	1669H - Maximal AND 	GNU C++17 	Accepted 	389 ms 	800 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;

    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int arr[32] = { 0 };
    
    for (int n : vi)
    {
        for (int i = 0; i < 31; ++i)
        {
            if ((n & (1 << i)) != 0)
            {
                ++arr[i];
            }
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; --i)
    {
        if ((sz1 - arr[i]) <= kk)
        {
            ans |= (1 << i);
            kk -= (sz1 - arr[i]);
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
