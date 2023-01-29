
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

#include <stack>
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








// 190189058 	Jan/23/2023 17:45UTC+8 	Ouha 	1638C - Inversion Graph 	GNU C++17 	Accepted 	420 ms 	1200 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    stack<int> stk;
    stk.push(vi[sz1 - 1]);
    int mn = vi[sz1 - 1];
    int t2 = 0;
    for (int i = sz1 - 2; i >= 0; --i)
    {
        t2 = vi[i];
        mn = t2;
        while (!stk.empty() && stk.top() < t2)
        {
            mn = min(mn, stk.top());
            stk.pop();
        }
        stk.push(mn);
    }

    cout << stk.size() << endl;
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
