
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





// ....无法理解，solution用了 2个set，我总觉得 set 肯定比 vector 慢。



// .. tle
void fun1_()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2 >> kk;
    int cntq;
    cin >> cntq;

    vector<int> vr(sz1, -1);
    vector<int> vc(sz2, -1);
    //vector<vector<int>> vvi(cntq, vector<int>(2));
    int t2, t3;
    for (int i = 1; i <= cntq; ++i)
    {
        cin >> t2 >> t3;
        vr[t2 - 1] = i;
        vc[t3 - 1] = i;
    }

    int mnr = INT_MAX;
    int mnc = INT_MAX;

    for (int i = 0; i < sz1 && mnr != -1; ++i)
    {
        mnr = min(mnr, vr[i]);
    }
    for (int i = 0; i < sz2 && mnc != -1; ++i)
    {
        mnc = min(mnc, vc[i]);
    }

    //mnr = mnr == -1 ? INT_MAX : mnr;
    //mnc = mnc == -1 ? INT_MAX : mnc;

    const long long MOD = 998244353LL;

    long long ans = 1LL;

    int cntr = 0;
    int cntc = 0;

    int pw = 0;
    vector<bool> vb(cntq + 1);
    for (int i = 0; i < sz1; ++i)
    {
        if (vr[i] >= mnc && vr[i] > 0 && !vb[vr[i]])
        {
            vb[vr[i]] = true;
            ++pw;
        }
    }
    for (int i = 0; i < sz2; ++i)
    {
        if (vc[i] >= mnr && vc[i] != -1 && !vb[vc[i]])
        {
            vb[vc[i]] = true;
            ++pw;
        }
    }

    long long k2 = kk;
    vector<long long> vll;
    vll.push_back(k2);         // k2^(2^idx)
    for (int i = 1; (1 << i) <= pw; ++i)
    {
        vll.push_back(vll[i - 1] * vll[i - 1] % MOD);
    }

    for (int i = vll.size() - 1; i >= 0; --i)
    {
        if (pw >= (1 << i))
        {
            ans = (ans * vll[i]) % MOD;
            pw -= (1 << i);
        }
    }

    cout << ans << endl;
}


// tle
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2 >> kk;
    int cntq;
    cin >> cntq;

    vector<vector<int>> vvi(cntq, vector<int>(2));
    int t2, t3;
    for (int i = 0; i < cntq; ++i)
    {
        //cin >> t2 >> t3;
        cin >> vvi[i][0] >> vvi[i][1];
        //--vvi[i][0];
        //--vvi[i][1];
    }

    const long long MOD = 998244353LL;
    
    long long ans = 1LL;

    vector<int> vr(sz1, -1);
    vector<int> vc(sz2, -1);
    int cntr = 0;
    int cntc = 0;
    
    //vector<int> vi(cntq);
    int pw = 0;
    for (int i = cntq - 1; i >= 0; --i)
    {
        if (cntc == sz2 || cntr == sz1)
            break;

        t2 = vvi[i][0] - 1;
        t3 = vvi[i][1] - 1;
        bool live = false;
        
        if (cntc != sz2 && vr[t2] == -1)
        {
            vr[t2] = i;
            ++cntr;
            live = true;
        }
        if (cntr != sz1 && vc[t3] == -1)
        {
            vc[t3] = i;
            ++cntc;
            //++vi[i];
            live = true;
        }
        if (live)
            ++pw;

        //if (vr[vvi[i][0]] == -1 && cntc != sz2)
        //{
        //    vr[vvi[i][0]] = i;
        //    ++cntr;
        //}
        //if (vc[vvi[i][1]] == -1 && cntr != sz1)
        //{
        //    vc[vvi[i][1]] = i;
        //    ++cntc;
        //}
    }

    
    long long k2 = kk;
    //for (int i = 0; i < sz1; ++i)
    //{
    //    if (vr[i] != -1)
    //        ++vi[vr[i]];
    //}
    //
    //for (int i = 0; i < sz2; ++i)
    //{
    //    if (vc[i] != -1)
    //        ++vi[vc[i]];
    //}

    //for (int i = 0; i < cntq; ++i)
    //{
    //    if (vi[i] != 0)
    //    {
    //        ans = (ans * k2) % MOD;
    //    }
    //}
    
    //while (pw > 0)
    //{
    //    ans = (ans * k2) % MOD;
    //    --pw;
    //}

    //int mxi = std::log(pw) / std::log(2) + 1;
    //vector<long long> vll;
    //vll.push_back(1LL);
    //long long tll;
    //for (int i = 1; i <= mxi; ++i)
    //{
    //    tll = vll[i - 1] * vll[i - 1] % MOD;
    //    vll.push_back(tll);
    //}

    vector<long long> vll;
    vll.push_back(k2);         // k2^(2^idx)
    for (int i = 1; (1 << i) <= pw; ++i)
    {
        vll.push_back(vll[i - 1] * vll[i - 1] % MOD);
    }

    for (int i = vll.size() - 1; i >= 0; --i)
    {
        if (pw >= (1 << i))
        {
            ans = (ans * vll[i]) % MOD;
            pw -= (1 << i);
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
