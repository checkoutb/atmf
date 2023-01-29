
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





// g

// error
// [1001]1 -> 10011
// 1[0011] -> 10011

uint64_t inverseModp(uint64_t a, uint64_t p);
uint32_t nCrModp(uint32_t n, uint32_t r, uint32_t p);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    
    string s;
    cin >> s;

    if (kk == 0)
    {
        cout << 1 << endl;
        return;
    }

    const int MOD = 998244353;

    vector<int> vi;
    for (int i = 0; i < sz1; ++i)
    {
        if (s[i] == '1')
            vi.push_back(i);
    }
    
    if (vi.size() < kk)
    {
        cout << 1 << endl;
        return;
    }

    int st, en;
    int ans = 0;
    for (int i = 0; i + kk <= vi.size(); ++i)
    {
        st = i == 0 ? 0 : (vi[i - 1] + 1);
        en = (i + kk == vi.size()) ? (sz1 - 1) : (vi[i + kk] - 1);
        ans = (ans + nCrModp(en - st + 1, kk, MOD)) % MOD;
    }
    cout << ans << endl;
}

// p MUST be prime and less than 2^63
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

    uint64_t result = 1; //intermediary results may overflow 32 bits

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
