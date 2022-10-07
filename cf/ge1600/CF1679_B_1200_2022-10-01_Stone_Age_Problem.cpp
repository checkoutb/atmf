
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
#include <numeric>
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

// segment tree


//int n, q; cin >> n >> q;
//ll ans = 0;
//vector<pair<int, int>> a(n); for (auto& x : a) cin >> x.first, x.second = 0, ans += x.first;
//pair<int, int> last{ -1, -1 };
//for (int qt = 1; qt <= q; qt++) {
//    int t; cin >> t;
//    if (t == 1) {
//        int i, x; cin >> i >> x, --i;
//        ans -= last.second < a[i].second ? a[i].first : last.first;
//        ans += x;
//        a[i] = { x, qt };
//    }
//    else {
//        int x; cin >> x;
//        last = { x, qt };
//        ans = (long long)x * n;
//    }
//    cout << ans << '\n';
//}



//int n, q;
//read(n, q);
//vector<ll> a(n);
//input(a);
//ll res = 0;
//for (auto x : a) res += x;
//vector<int> u(n);
//int last = -1;
//ll color = 0;
//for (int id = 1; id <= q; ++id)
//{
//    int t;
//    read(t);
//    auto f = [&](int i)
//    {
//        if (u[i] < last) return color;
//        return a[i];
//    };
//    auto go = [&](int i, ll x)
//    {
//        u[i] = id;
//        a[i] = x;
//    };
//    if (t == 1)
//    {
//        ll i, x;
//        read(i, x);
//        i -= 1;
//        res -= f(i);
//        go(i, x);
//        res += f(i);
//    }
//    else
//    {
//        ll x;
//        read(x);
//        res = x * n;
//        last = id;
//        color = x;
//    }
//    writeln(res);
//}




// 174185765 	Oct/01/2022 08:49UTC+8 	Ouha 	1679B - Stone Age Problem 	GNU C++17 	Accepted 	1622 ms 	7200 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> sz2;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    myvvi vvi(sz2);
    int t2;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> t2;
        if (t2 == 1)
        {
            cin >> t2;
            vvi[i].push_back(t2 - 1);
            cin >> t2;
            vvi[i].push_back(t2);
        }
        else
        {
            cin >> t2;
            vvi[i].push_back(t2);
        }
    }
    
    ll sum2 = std::accumulate(begin(vi), end(vi), 0LL);

    myvi v2(sz1, -1);       // last operate time
    int lsttm = -1;
    int lstnv = 0;
    for (int i = 0; i < sz2; ++i)
    {
        if (vvi[i].size() == 2)
        {
            int idx = vvi[i][0];
            int nv = vvi[i][1];
            if (v2[idx] < lsttm)
            {
                sum2 = sum2 - lstnv + nv;
            }
            else
            {
                sum2 = sum2 - vi[idx] + nv;
            }
            vi[idx] = nv;
            v2[idx] = i;
        }
        else
        {
            lstnv = vvi[i][0];
            lsttm = i;
            sum2 = 1LL * lstnv * sz1;
        }
        cout << sum2 << endl;
    }
    
}


int main()
{
    int w = 1;
    //cin>>w;
    
    
    
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
