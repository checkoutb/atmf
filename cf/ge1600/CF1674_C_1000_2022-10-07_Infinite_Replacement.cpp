
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








// 174939568 	Oct/07/2022 15:18UTC+8 	Ouha 	1674C - Infinite Replacement 	GNU C++17 	Accepted 	186 ms 	0 KB
// 18074

void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    
    string a;
    string b;
    cin >> a >> b;
    
    sz1 = a.size();
    sz2 = b.size();

    for (int i = 0; i < sz2; ++i)
    {
        if (b[i] == 'a' && sz2 > 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    
    if (b[0] == 'a')
    {
        cout << 1 << endl;
        return;
    }

    ll ans = 1LL << sz1;
    
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
