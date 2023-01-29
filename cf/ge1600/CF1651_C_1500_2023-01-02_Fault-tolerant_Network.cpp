
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







// error£¬ ÉÙÁË£ºa[0]-b[n],a[n]-b[0].


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    vector<int> v2(sz1);

    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    for (int i = 0; i < sz1; ++i)
        cin >> v2[i];
    
    long long ans = abs(v2[0] - vi[0]) + abs(v2[sz1 - 1] - vi[sz1 - 1]);
    
    int a = vi[0], b = vi[sz1 - 1], c = v2[0], d = v2[sz1 - 1];
    int q, w, z, x;
    q = w = z = x = (1 << 30);

    for (int i = 0; i < sz1; ++i)
    {
        q = min(q, abs(a - v2[i]));
        w = min(w, abs(b - v2[i]));
        z = min(z, abs(c - vi[i]));
        x = min(x, abs(d - vi[i]));
    }

    ans = min(ans, ((long long) q) + w + x + z);
    long long t2 = (long long)abs(v2[0] - vi[0]) + w + x;
    long long t3 = (long long)abs(v2[sz1 - 1] - vi[sz1 - 1]) + q + z;
    ans = min(ans, min(t2, t3));
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
