
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





// 190605778 	Jan/26/2023 10:46UTC+8 	Ouha 	1626C - Monsters And Spells 	GNU C++17 	Accepted 	77 ms 	100 KB 

void fun1()
{
    int sz1;
    cin >> sz1;
    
    myvi vtm(sz1);
    myvi vhp(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vtm[i];
    for (int i = 0; i < sz1; ++i)
        cin >> vhp[i];

    long long ans = 0LL;
    ll dmg = vhp[sz1 - 1];
    ll tm = vtm[sz1 - 1];
    ll t2 = 0LL;
    ll myst = 0LL;
    for (int i = sz1 - 2; i >= 0; --i)
    {
        t2 = tm - dmg + 1;      // dmg==1 's time
        myst = -vhp[i] + vtm[i] + 1;    // [i]'s dmg == 1 's time
        if (t2 > vtm[i])        // aaa  AAA
        {
            ans += (dmg + 1) * (dmg) / 2;
            dmg = vhp[i];
            tm = vtm[i];
        }
        else if (t2 <= myst)        // AbAaaaA
        {
            //ans += (dmg + 1) * (dmg) / 2;
            //--i;
            //dmg = i >= 0 ? vhp[i] : 0;
            //tm = i >= 0 ? vtm[i] : 0;
        }
        else
        {
            // abAAaaA
            dmg += t2 - myst;
            //ans += (dmg + 1) * dmg / 2;
            //--i;
            //dmg = i >= 0 ? vhp[i] : 0;
            //tm = i >= 0 ? vtm[i] : 0;
        }
    }
    ans += (dmg + 1) * (dmg) / 2;
    cout << ans << endl;
}




// error
void fun1___()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vtm(sz1);
    vector<int> vhp(sz1);

    for (int i = 0; i < sz1; ++i)
        cin >> vtm[i];
    for (int i = 0; i < sz1; ++i)
        cin >> vhp[i];
    
    stack<pair<int, long long>> stk;

    ll t2 = 1LL * (1 + vhp[0]) * (vhp[0]) / 2;
    ll dmg = vhp[0];

    stk.push(std::make_pair(0, t2));


    //// <index, damage, ans>
    //stack<vector<long long>> stk;

    //ll t2 = 1LL * (1 + vhp[0]) * (vhp[0]) / 2;
    //ll dmg = vhp[0];

    //stk.push({ 0, dmg, t2 });

    vector<int> vsttm(sz1);      // first 1
    vector<int> vdmg(sz1);
    vdmg[0] = dmg;
    vsttm[0] = vtm[0] - vhp[0] + 1;

    for (int i = 1; i < sz1; ++i)
    {
        if ((vtm[i] - vtm[i - 1]) >= (vhp[i]))
        {
            t2 = (stk.empty() ? 0 : stk.top().second) + 1LL * (1 + vhp[i]) * (vhp[i]) / 2;
            dmg = vhp[i];
            stk.push(std::make_pair(i, t2));
            vdmg[i] = dmg;
            vsttm[i] = vtm[i] - vhp[i] + 1;
        }
        else if (dmg + (vtm[i] - vtm[i - 1]) >= vhp[i])
        {
            t2 = 1LL * (dmg + 1 + dmg + vtm[i] - vtm[i - 1]) * (vtm[i] - vtm[i - 1]) / 2;
            dmg += vtm[i] - vtm[i - 1];
            stk.push(std::make_pair(i, stk.top().second + t2));
            vdmg[i] = dmg;
            vsttm[i] = vsttm[i - 1];
        }
        else
        {
            int tm = vtm[i] - vhp[i] + 1;
            
            while (!stk.empty() && vsttm[stk.top().first] >= tm)
            {
                stk.pop();
            }

            if (stk.empty())
            {
                t2 = 1LL * (1 + vhp[i]) * (vhp[i]) / 2;
                dmg = vhp[i];
                vsttm[i] = vtm[i] - vhp[i] + 1;
                vdmg[i] = dmg;
                stk.push(std::make_pair(i, t2));
            }
            else if (tm > vtm[stk.top().first])
            {
                t2 = 1LL * (1 + vhp[i]) * (vhp[i]) / 2;
                dmg = vhp[i];
                vsttm[i] = vtm[i] - vhp[i] + 1;
                vdmg[i] = dmg;
                stk.push(std::make_pair(i, stk.top().second + t2));
            }
            else
            {
                dmg = vtm[i] - vsttm[stk.top().first] + 1;
                t2 = 1LL * (1 + dmg) * (dmg) / 2;
                vsttm[i] = vsttm[stk.top().first];
                vdmg[i] = dmg;

                stk.pop();
                stk.push(std::make_pair(i, (stk.empty() ? 0LL : stk.top().second) + t2));
            }
        }
    }
    ll ans = stk.top().second;
    //while (!stk.empty())
    //{
    //    ans += stk.top().second;
    //    stk.pop();
    //}
    cout << ans << endl;



    //long long ans = 1LL * (1 + vhp[0]) * (vhp[0]) / 2;
    //long long dmg = vhp[0];

    //for (int i = 0; i < sz1; ++i)
    //{
    //    if ((vtm[i] - vtm[i - 1]) >= (vhp[i]))
    //    {
    //        ans += 1LL * (1 + vhp[i]) * (vhp[i]) / 2;
    //        dmg = vhp[i];
    //    }
    //    else if (dmg + (vtm[i] - vtm[i - 1]) >= vhp[])
    //    {
    //        ans += 1LL * (dmg + 1 + dmg + vtm[i] - vtm[i - 1]) * (vtm[i] - vtm[i - 1]) / 2;
    //    }
    //    else
    //    {
    //        
    //    }
    //}

    
    
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
