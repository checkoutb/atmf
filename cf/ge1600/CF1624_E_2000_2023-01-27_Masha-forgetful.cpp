
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






// 190732710 	Jan/27/2023 15:22UTC+8 	Ouha 	1624E - Masha-forgetful 	GNU C++17 	Accepted 	1809 ms 	2100 KB
// 3322

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    
    vector<string> vs(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vs[i];
    
    string tar;
    cin >> tar;
    
    if (sz2 == 1)
    {
        cout << -1 << endl;
        return;
    }

    vector<bool> vb(100, false);
    vector<bool> v2(1000, false);

    vector<pair<int, int>> vp2(100);
    vector<pair<int, int>> vp3(1000);

    int t2 = 0;
    int t3 = 0;
//    for (string& s : vs)
    for (int j = 0; j < sz1; ++j)
    {
        string& s = vs[j];

        t2 = (s[0] - '0') * 10 + (s[1] - '0');
        //t3 = sz2 > 2 ? t2 * 10 + (s[2] - '0') : 0;
        t3 = t2;
        vb[t2] = true;
        vp2[t2] = make_pair(j, 1);

        for (int i = 2; i < sz2; ++i)
        {
            t2 = (t2 * 10 + (s[i] - '0')) % 100;
            t3 = (t3 * 10 + (s[i] - '0')) % 1000;

            if (!vb[t2])
            {
                vb[t2] = true;
                vp2[t2] = std::make_pair(j, i);
            }
            if (!v2[t3])
            {
                v2[t3] = true;
                vp3[t3] = std::make_pair(j, i);
            }
        }
    }
    
    vector<pair<int, int>> vpa(sz2);
    vector<bool> vba(sz2);

    t2 = (tar[0] - '0') * 10 + (tar[1] - '0');
    if (vb[t2])
    {
        vba[1] = true;
        vpa[1] = std::make_pair(2, t2);
    }
    if (sz2 > 2)
    {
        t2 = t2 * 10 + (tar[2] - '0');
        if (v2[t2])
        {
            vba[2] = true;
            vpa[2] = make_pair(3, t2);
        }
    }
    t2 %= 100;
    for (int i = 3; i < sz2; ++i)
    {
        t2 = (t2 * 10 + (tar[i] - '0'));
        if (vba[i - 3] && v2[t2])
        {
            vba[i] = true;
            vpa[i] = make_pair(3, t2);
        }
        t2 %= 100;
        if (!vba[i] && vba[i - 2] && vb[t2])
        {
            vba[i] = true;
            vpa[i] = make_pair(2, t2);
        }
    }
    
    if (!vba[sz2 - 1])
    {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> ans;

    for (int i = sz2 - 1; i >= 0; )
    {
        t2 = vpa[i].second;
        if (vpa[i].first == 2)
        {
            ans.push_back({ vp2[t2].second, vp2[t2].second + 1 , vp2[t2].first + 1 });
            i -= 2;
        }
        else
        {
            ans.push_back({ vp3[t2].second - 1, vp3[t2].second + 1, vp3[t2].first + 1 });
            i -= 3;
        }
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
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
