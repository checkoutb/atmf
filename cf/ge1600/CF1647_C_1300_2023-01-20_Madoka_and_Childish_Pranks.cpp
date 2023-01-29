
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








// 189833532 	Jan/20/2023 19:21UTC+8 	Ouha 	1647C - Madoka and Childish Pranks 	GNU C++17 	Accepted 	327 ms 	200 KB 

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;

    vector<string> vs(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vs[i];
    
    if (vs[0][0] == '1')
    {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (vs[i][j] == '1')
                ++ans;
        }
    }
    cout << ans << endl;

    for (int i = 0; i < sz1; ++i)
    {
        for (int j = sz2 - 1; j > 0; --j)
        {
            if (vs[i][j] == '1')
            {
                cout << (i + 1) << ' ' << (j) << ' ' << (i + 1) << ' ' << (j + 1) << endl;
            }
        }
    }
    
    for (int i = sz1 - 1; i > 0; --i)
    {
        if (vs[i][0] == '1')
        {
            cout << (i) << ' ' << 1 << ' ' << (i + 1) << ' ' << 1 << endl;
        }
    }
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
