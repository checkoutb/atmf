
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
#include <cmath>
//#include <limits.h>   // INT_MAX

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
#include <map>
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







// AC


// a
// b = 2^a
// (b1, b2) = b1 ^ b2 = (2^a1) ^ (2^a2)
//  (2^a1)^(2^a2) ==? (2^a2)^(2^a1)
// (2^a1)^(2^a2) == (2^a1) * (2^a1) ... (2^a1)  == ?
// (2^a1)^(2^a2) = 2^(a1 * 2^a2) ....  == 2^(a2 * 2^a1)
// a1 * 2^a2 == a2 * 2^a1 ,  a1, b2 must is 2^x,  and log2(a1) + a2 == log2(a2) + a1
//      a2 - log2(a2) = a1 - log2(a1)
// a1=1,a2=2, 0+2 == 1+1,  1-0 == 2-1
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1, 0);
    for (int i = 0; i < sz1; ++i)
        cin>>vi[i];

    sort(begin(vi), end(vi));

    std::map<int, int> map2;

    // int ans = 0;
    long long ans = 0LL;
    int cnt = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if ((vi[i] & (vi[i] - 1)) == 0)     // 2^x
        {
            int t2 = vi[i] - std::log2(vi[i]);
            ans += map2[t2];
            ++map2[t2];
            cnt = 0;
        }
        else
        {
            if (i > 0 && vi[i] == vi[i - 1])
            {
                ans += cnt;
                cnt += 1;
            }
            else
            {
                cnt = 1;
            }
        }
    }

    cout<<ans<<endl;
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
