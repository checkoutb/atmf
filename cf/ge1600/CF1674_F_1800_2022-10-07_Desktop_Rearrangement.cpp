
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

//cin >> x >> y;
//--x; --y;
//if (a[x][y] == '*') {
//    cnt--;
//    from = getf();
//    if (a[from.second][from.first] == '*') rogue++;
//    a[x][y] = '.';
//    if (mp(y, x) >= from) rogue--;
//}
//else {
//    if (a[from.second][from.first] == '*') rogue--;
//    cnt++;
//    from = getf();
//    a[x][y] = '*';
//    if (mp(y, x) >= from) rogue++;
//}

//pi getf() {
//    return mp(cnt / n, cnt % n);
//}

//#define pb push_back
//#define mp make_pair





// 174930569 	Oct/07/2022 13:36UTC+8 	Ouha 	1674F - Desktop Rearrangement 	GNU C++17 	Accepted 	1076 ms 	3500 KB 
// 3792


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2 >> kk;
    
    vector<string> vs(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vs[i];

    vector<pair<int, int>> vp(kk);
    for (int i = 0; i < kk; ++i)
    {
        cin >> vp[i].first >> vp[i].second;
        --vp[i].first;
        --vp[i].second;
    }
    
    int cnt = 0;        // count of *
    for (string& s : vs)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            cnt += s[i] == '*';
        }
    }
    
    int x2 = 0;
    int y2 = 0;
    int len = 0;
    int cntst = 0;      // count of * that in the rearranged area
    for (int j = 0; j < sz2 && len < cnt; ++j)
    {
        for (int i = 0; i < sz1; ++i)
        {
            cntst += vs[i][j] == '*';

            ++len;
            if (len >= cnt)
            {
                x2 = i;
                y2 = j;
                break;
            }
        }
    }
    //int mov = cnt - cntst;

    for (auto &[x, y] : vp)
    {
        if (vs[x][y] == '*')
        {
            if (y < y2 || (y == y2 && (x <= x2)))
            {
                --cntst;
                vs[x][y] = '.';
            }

            if (vs[x2][y2] == '*')
            {
                --cntst;
            }

            vs[x][y] = '.';
            --cnt;
            --x2;
            if (x2 < 0)
            {
                --y2;
                x2 = sz1 - 1;
            }

        }
        else
        {
            //vs[x][y] = '*';

            ++x2;
            if (x2 == sz1)
            {
                ++y2;
                x2 = 0;
            }

            if (vs[x2][y2] == '*')
            {
                ++cntst;
            }

            if (y < y2 || (y == y2 && (x <= x2)))
            {
                ++cntst;
            }

            vs[x][y] = '*';

            ++cnt;

        }
        cout << cnt - cntst << endl;
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
