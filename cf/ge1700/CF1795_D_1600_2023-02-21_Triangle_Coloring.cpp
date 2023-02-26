
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

//n /= 3;
//for (int i = 0; i < n; ++i)
//{
//    vi a(3);
//    for (int i = 0; i < 3; ++i)
//    {
//        cin >> a[i];
//    }
//
//    sort(a.begin(), a.end());



// nCr 的写法 和变种 好多。。





// 194453963 	Feb / 21 / 2023 20:45UTC + 8 	Ouha 	1795D - Triangle Coloring 	GNU C++17 	Accepted 	296 ms 	1200 KB
// 4570

// butong yanse de dian de bian de weight
// 1-2, 1-3, 2-3
// n/2 yinggai wusuowei, jiushi  R-B-R, B-R-B  de xuanze
// meige triple zui duo jiu 2tiao bian. biran  R-B-R huo BRB
// ? danshi  emample kan budong.. wanquan bushi wo xiang de .
// haoba, qiu de shi cnt.. bushi  sum..
// 2-2-2, 3 * 2     you 3zhong sheqi
// 3-3-1, 1     . biran sheqi 1
// 1-2-3, 1 * 2     biran sheqi 1
// 3-2-2,       2zhong sheqi
// if min() == 2th_min()
// nC(n/2) wo bu hui .
uint32_t nCrModp(uint32_t n, uint32_t r, uint32_t p);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];

    const int MOD = 998244353;
    
    ll ans = nCrModp(sz1 / 3, sz1 / 6, MOD);
    
    for (int i = 0; i < sz1; i += 3)
    {
        sort(begin(vi) + i, begin(vi) + i + 3);
        if (vi[i] == vi[i + 2])
        {
            ans = ans * 3 % MOD;
        }
        else if (vi[i] == vi[i + 1])
        {
            ans = ans * 2 % MOD;
        }
    }
    cout << ans << endl;
}

uint64_t inverseModp(uint64_t a, uint64_t p) {

    uint64_t ex = p - 2, result = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            result = (result * a) % p;
        }
        a = (a * a) % p;
        ex /= 2;
    }
    return result;
}

// p MUST be prime
uint32_t nCrModp(uint32_t n, uint32_t r, uint32_t p)
{
    if (r > n - r) r = n - r;
    if (r == 0) return 1;
    if (n / p - (n - r) / p > r / p) return 0;

    uint64_t result = 1;

    for (uint32_t i = n, x = 1; i > r; --i, ++x) {
        if (i % p != 0) {
            result *= i % p;
            result %= p;
        }
        if (x % p != 0) {
            result *= inverseModp(x % p, p);
            result %= p;
        }
    }
    return result;
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
