
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








// 174957977 	Oct/07/2022 18:26UTC+8 	Ouha 	1672C - Unequal Array 	GNU C++17 	Accepted 	373 ms 	800 KB
// 11041

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);

    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    int fst = -1;
    int lst = -1;
    for (int i = 1; i < sz1; ++i)
    {
        if (vi[i] == vi[i - 1])
        {
            if (fst == -1)
                fst = i;
            lst = i;
        }
    }
    
    if (fst == lst)
    {
        cout << 0 << endl;
        return;
    }
    
    //int ans = (lst - fst + 1) / 2;
    int ans = (lst - fst - 1);
    ans = max(1, ans);
    
    cout << ans << endl;
    return;
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
