
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

//for (register int i = 1; i <= n; ++i) {
//    if (i > m && a[i - m] == 1)
//        nul[i] = nul[i - m] + 1;
//    else
//        nul[i] = 0;
//}
//for (register int i = n; i >= 0; --i) {
//    if (i + m <= n && a[i + m] == 1)
//        nur[i] = nur[i + m] + 1;
//    else
//        nur[i] = 0;
//}
//for (register int i = 1; i <= n; ++i) {
//    if (vis[a[i]])
//        continue;
//    ans += 1ll * (nul[i] + 1) * (nur[i] + 1) - 1;
//}
// vis 是预先筛选的 prime。




// 193722220 	Feb/15/2023 22:01UTC+8 	Ouha 	1609C - Complex Market Analysis 	GNU C++17 	Accepted 	748 ms 	800 KB
// 8475

// prime * 1 * 1 * 1 * 1 .. * 1
// 1 * 1 * 1 * prime * 1 * 1
bool isPrime(int n);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    int e;
    cin >> e;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];

    ll cnt = 0LL;
    ll cnt2 = 0LL;
    ll ans = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        if (isPrime(vi[i]))
        {
            cnt2 = cnt = 0LL;
            for (int j = i - e; j >= 0; j -= e)
            {
                if (vi[j] == 1)
                    ++cnt;
                else
                    break;
            }
            for (int j = i + e; j < sz1; j += e)
                if (vi[j] == 1)
                    ++cnt2;
                else
                    break;

            //cnt = cnt * (cnt + 1) / 2LL;
            //if (cnt0 == 0LL && cnt == 0LL)
            //    continue;
            //cnt0 = cnt0 == 0LL ? 1LL : cnt0;
            //cnt = cnt == 0LL ? 1LL : cnt;
            //ans += cnt0 * cnt * 2LL;
            if (cnt2 != 0LL)
                ans += cnt2 * (cnt + 1LL);
            if (cnt != 0LL)
                //ans += cnt * (cnt2 + 1LL);
                ans += cnt;
        }
    }
    
    cout << ans << endl;
}

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
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
