
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


// D

//sort(a.begin(), a.end());
//long long s = 0;
//long long ans = 0;
//for (int i = 0; i < n; i++) {
//    s += a[i];
//    if (s <= x) {
//        ans += (x - s) / (i + 1) + 1;
//    }
//}






//186050190 	Dec / 20 / 2022 08:44UTC + 8 	Ouha 	1671C - Dolce Vita 	GNU C++17 	Accepted 	358 ms 	1600 KB
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    
    vector<long long> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    long long ans = 0;

    std::sort(begin(vi), end(vi));

    long long t2 = 0;     // day
    long long pfx = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (vi[i] > (kk - pfx))
            break;

        pfx += vi[i];

        t2 = (kk - pfx) / (i + 1);
        ans += t2 + 1;
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
