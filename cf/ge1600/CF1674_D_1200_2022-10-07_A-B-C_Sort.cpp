
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








// 174938476 	Oct/07/2022 15:06UTC+8 	Ouha 	1674D - A-B-C Sort 	GNU C++17 	Accepted 	327 ms 	800 KB
// 12245

// 成对出现的
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    int mx = -1;
    int a, b;
    int i = 0;
    if (sz1 & 1)
    {
        mx = vi[i++];
    }
    for (; i < sz1;)
    {
        a = vi[i++];
        //b = 1234567;
        //if (i < sz1)
            b = vi[i++];

        if (a < b)
        {
            if (a < mx)
            {
                cout << "NO" << endl;
                return;
            }
            mx = b;
        }
        else
        {
            if (b < mx)
            {
                cout << "NO" << endl;
                return;
            }
            mx = a;
        }
    }
    
    cout << "YES" << endl;

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
