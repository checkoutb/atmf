
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




// 。。完全错了。


// 不带0的算术。。
// g

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    ll x;
    cin >> x;
    
    string s;
    cin >> s;

    stack<ll> stk;
    ll t2 = 1LL;
    string ans;
    int idx = -1;
    for (int i = sz1 - 1; i >= 0; --i)
    {
        if (s[i] == '*')
        {
            stk.push(t2);
            t2 *= (kk + 1);
            if (t2 >= x)
            {
                idx = i;
                break;
            }
        }
    }
    
    for (int i = 0; i < idx; ++i)
        if (s[i] == 'a')
            ans.push_back('a');
    
    ll t3;
    for (int i = idx; i < sz1; ++i)
    {
        if (s[i] == '*')
        {
            t3 = stk.top();
            t2 = x / t3;

            if (x % t3 == 0 && t3 != 1)
                --t2;

            for (ll j = 0LL; j < t2; ++j)
                ans.push_back('b');
            
            x -= t2 * stk.top();

            stk.pop();
        }
        else
        {
            ans.push_back('a');
        }
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
