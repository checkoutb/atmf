
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

// D D

        // ll n, x;
        // cin >> n >> x;
        // ll m = n;
        // while (n > x)
        // {
        //     m += m & -m;
        //     n &= m;
        // }
        // if (n == x)
        //     cout << m << '\n';
        // else
        //     cout << -1 << '\n';
    // ?????


    // ll n, x; cin >> n >> x;
    // ll L = n;
    // ll R = INF;
    // for(ll b = 0; b < 60; ++b) {
    //     ll f;
    //     if ((1ll << b) & n) {
    //         f = ((n >> b) + 1) << b;
    //     } else {
    //         f = n;
    //     }
    //     if ((1ll << b) & x) {
    //         R = min(R, f - 1);
    //     } else {
    //         L = max(L, f);
    //     }
    // }
    // cout << (R >= L ? L : -1) << '\n';



// 207708189 	May/29/2023 11:35UTC+8 	Ouha 	1775C - Interesting Sequence 	GNU C++17 	Accepted 	31 ms 	0 KB 
// 7635


// 3 2 -> -1

/*

1010   1000
1011
1100

10100  1000
11000 16+8

x's tail is all 0
prefix is same

*/

string toB(ll n);

void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;
    
    ll n, x;
    cin>>n;
    cin>>x;
    if (n < x)
    {
        cout<<-1<<endl;
        return;
    }
    else if (n == x)
    {
        cout<<n<<endl;
        return;
    }

    if (x == 0LL)
    {
        int t3 = 0;
        while (n > 0)
        {
            ++t3;
            n >>= 1;
        }
        cout<<(1LL << (t3))<<endl;
        return;
    }

    string ns = toB(n);
    string xs = toB(x);

    if (ns.size() != xs.size())
    {
        cout<<-1<<endl;
        return;
    }
    int sz1 = ns.size();
    int t2 = -1;
    for (int i = 0; i < sz1; ++i)
    {
        if (ns[i] != xs[i])
        {
            if (i == 0 || ns[i - 1] == '1')         // 3 2
            {
                cout<<-1<<endl;
                return;
            }
            t2 = i;
            break;
        }
    }

    for (int i = t2; i < sz1; ++i)
    {
        if (xs[i] != '0')
        {
            cout<<-1<<endl;
            return;
        }
    }

    ll ans = 1LL << (sz1 - 1 - t2 + 1);
    for (int i = t2 - 2; i >= 0; --i)
    {
        if (ns[i] == '1')
            ans |= 1LL << (sz1 - 1 - i);
    }

    cout<<ans<<endl;

    // int sz1 = ns.size();
    // int of = 0;
    // while (xs[sz1 - 1 - of] == '0') {
    //     ++of;
    // }
    
    
    
    
    
}

string toB(ll n)
{
    string ans;
    while (n > 0LL)
    {
        ans.push_back(n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    std::reverse(begin(ans), end(ans));
    return ans;
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
