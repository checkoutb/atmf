
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







// 195013129 	Feb/26/2023 12:43UTC+8 	Ouha 	1786B - Cake Assembly Line 	GNU C++17 	Accepted 	592 ms 	800 KB 
// 6033


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    int w, h;
    cin >> w >> h;
    myvi vi(sz1);
    myvi v2(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    for (int i = 0; i < sz1; ++i)
        cin >> v2[i];
    
    // cake move left
    int st = vi[0] - v2[0] - w + h;
    int en = vi[0] - v2[0] + w - h;
    int t2, t3;
    for (int i = 1; i < sz1; ++i)
    {
        t2 = vi[i] - v2[i] - w + h;
        t3 = vi[i] - v2[i] + w - h;
        st = max(st, t2);
        en = min(en, t3);
        if (st > en)
        {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
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
