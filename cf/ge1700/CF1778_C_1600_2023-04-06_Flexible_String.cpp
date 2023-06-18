
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







// 200985196 	Apr / 06 / 2023 22:36UTC + 8 	Ouha 	1778C - Flexible String 	GNU C++17 	Accepted 	607 ms 	400 KB
// dfs中 k==0 少一个 return。导致 tle。
// 5980
// 
// tle

void dfsa1(vector<bool>& vb, vector<bool>& v2, int idx, int kk, long long& ans, string& sa, string& sb);

// ... 10C5 = 252
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    string sa, sb;
    cin >> sa >> sb;
    
    vector<bool> vb(123, false);

    for (int i = 0; i < sz1; ++i)
    {
        if (sa[i] != sb[i])
            vb[sa[i]] = true;
    }
    int t2 = 0;
    for (int i = 'a'; i <= 'z'; ++i)
        t2 += vb[i];
    
    if (t2 <= kk)
    {
        cout << (1LL * (1 + sz1) * sz1 / 2) << endl;
        return;
    }

    vector<bool> v2(123, false);

    long long ans = 0LL;
    
    dfsa1(vb, v2, 'a', kk, ans, sa, sb);

    cout << ans << endl;
}

void dfsa1(vector<bool>& vb, vector<bool>& v2, int idx, int kk, long long& ans, string& sa, string& sb)
{
    if (kk == 0)
    {
        long long t2 = 0;
        long long t3 = 0;
        for (int i = 0, mxi = sa.size(); i < mxi; ++i)
        {
            if (sa[i] == sb[i] || v2[sa[i]])
            {
                ++t3;
            }
            else
            {
                t2 += (t3 + 1) * t3 / 2;
                t3 = 0LL;
            }
        }
        t2 += (t3 + 1) * t3 / 2;

        if (t2 > ans)
            ans = t2;

        return;                                   // lose this, cause tle...
    }

    if (idx - 1 == 'z')
        return;

    dfsa1(vb, v2, idx + 1, kk, ans, sa, sb);

    if (vb[idx])
    {
        v2[idx] = true;
        dfsa1(vb, v2, idx + 1, kk - 1, ans, sa, sb);
        v2[idx] = false;
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
