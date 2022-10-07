
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

//std::sort(a.begin(), a.end(), std::greater());
//for (int i = 0; i < n; i++) {
//    s[i + 1] = s[i] + a[i];
//}
//
//for (int i = 0; i < q; i++) {
//    int x;
//    std::cin >> x;
//    int ans = std::lower_bound(s.begin(), s.end(), x) - s.begin();
//    if (ans > n) {
//        ans = -1;
//    }
//    std::cout << ans << "\n";
//}


//vector<ll> a(n);
//input(a);
//sort(a.begin(), a.end(), greater<>());



// 174218748 	Oct/01/2022 15:56UTC+8 	Ouha 	1676E - Eating Queries 	GNU C++17 	Accepted 	873 ms 	1800 KB


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> sz2;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    vector<pair<int, int>> vp(sz2);
    for (int i = 0; i < sz2; ++i)
    {
        cin >> vp[i].first;
        vp[i].second = i;
    }
    
    sort(begin(vp), end(vp));
    std::sort(begin(vi), end(vi), std::greater<int>());
    
    for (int i = 1; i < sz1; ++i)
        vi[i] += vi[i - 1];
    
    int qi = 0;     // query index
    for (int i = 0; i < sz1; ++i)       // candy
    {
        while (qi < sz2 && vp[qi].first <= vi[i])
        {
            vp[qi].first = vp[qi].second;
            vp[qi].second = i + 1;
            ++qi;
        }
    }

    while (qi < sz2)
    {
        vp[qi].first = vp[qi].second;
        vp[qi].second = -1;
        ++qi;
    }

    sort(begin(vp), end(vp));

    for (auto& p : vp)
    {
        cout << p.second << endl;
    }

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
