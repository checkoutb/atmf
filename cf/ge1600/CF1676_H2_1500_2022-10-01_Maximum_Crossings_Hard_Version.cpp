
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
#include <set>
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







// tle
void fun1__tle()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);
    
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    multiset<int> mset2;
    
    ll ans = 0LL;

    for (int i = 0; i < sz1; ++i)
    {
        int t2 = vi[i];

        ans += std::distance(std::lower_bound(begin(mset2), end(mset2), t2), end(mset2));

        mset2.insert(t2);
    }
    
    cout << ans << endl;
}


int main()
{
    int w = 1;
    cin>>w;
    
    //multiset<int> mset2;
    //mset2.insert(1);
    //mset2.insert(2);

    //cout << std::distance(begin(mset2), std::lower_bound(begin(mset2), end(mset2), 3)) << endl;

    
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
