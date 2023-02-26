
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







// Ï¸½Ú¡£¡£¡£
// 194687719 	Feb/23/2023 22:46UTC+8 	Ouha 	1793D - Moscow Gorillas 	GNU C++17 	Accepted 	530 ms 	3100 KB
// 3485

// error  y?

ll calCnt(int t2);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<pair<int, int>> vpp(sz1);
    vector<pair<int, int>> vp2(sz1);
    
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vpp[i].first;
        vpp[i].second = i;
    }
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vp2[i].first;
        vp2[i].second = i;
    }
    
    sort(begin(vpp), end(vpp));
    sort(begin(vp2), end(vp2));

    int stp = vpp[0].second;
    int enp = stp;
    int st2 = vp2[0].second;
    int en2 = st2;
    int tmn = min(st2, stp);
    int tmx = max(en2, enp);
    int tlen = tmn;
    ll ans = 1LL * (tlen) * (tlen + 1) / 2;
    tlen = tmx - tmn - 1;
    ans += 1LL * tlen * (tlen + 1) / 2;
    tlen = sz1 - tmx - 1;
    ans += 1LL * tlen * (tlen + 1) / 2;
    int t2, t3;
    for (int i = 1; i < sz1; ++i)
    {
        t2 = vpp[i].second;
        t3 = vp2[i].second;
        if (t2 > t3)
            swap(t2, t3);

        if ((tmn <= t2 && t2 <= tmx) || (tmn <= t3 && t3 <= tmx))
        {
            ;
        }
        else
        {
            if (t2 < tmn)
            {
                if (t3 < tmn)
                {
                    ans += 1LL * (sz1 - tmx) * (tmn - t3);
                    //ans += calCnt(tmn - t3 - 1);
                    //ans += calCnt(sz1 - tmx - 1);
                }
                else
                {
                    ans += 1LL * (tmn - t2) * (t3 - tmx);
                    //ans += 1LL * (tmn - t2) * (sz1 - t3);             // ...
                    //ans += calCnt(tmn - t2 - 1);
                    //ans += calCnt(sz1 - t3 - 1);
                }
            }
            else
            {
                ans += 1LL * (tmn + 1) * (t2 - tmx);            // * (t3 - tmx)
                //ans += calCnt(tmn);
                //ans += calCnt(sz1 - t3 - 1);
            }
        }

        stp = min(stp, vpp[i].second);
        enp = max(enp, vpp[i].second);
        st2 = min(st2, vp2[i].second);
        en2 = max(en2, vp2[i].second);
        tmn = min(tmn, min(stp, st2));
        tmx = max(tmx, max(enp, en2));
    }

    cout << ans + 1 << endl;        // + [0, sz1 - 1]
}

ll calCnt(int t2)
{
    return 1LL * t2 * (t2 + 1) / 2;
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
