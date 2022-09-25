
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
#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>
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

//int l = 0, r = 0, ans = 1;
//for (int i = 0; i < n; ) {
//    int cnt = 1;
//    int mcnt = 1, rr = i;
//    for (int j = i + 1; j < n; ++j) {
//        if (a[j] == a[i]) {
//            cnt++;
//        }
//        else {
//            cnt--;
//        }
//        if (cnt <= 0) break;
//        if (cnt > mcnt) {
//            mcnt = cnt;
//            rr = j;
//        }
//    }
//    if (mcnt > ans) {
//        ans = mcnt;
//        l = i;
//        r = rr;
//    }
//    ++i;
//    i = max(i, rr);
//}




//#define ft first
//#define sc second
//using namespace std;
//const int N = 2e5 + 10;
//int n, b, l, r;
//pair<int, int> a[N];
//void lulu_solution()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a[i].ft;           // 。。。。。。。。。
//        a[i].sc = i;              // 。。。。。
//    }
//    sort(a + 1, a + n + 1);                       // 。。。。。
//    int j = 1;
//    int res = -1e9;
//    int cnt = 0;
//    int nmin = 1e9;
//    int lf = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        cnt += 2;
//        if (nmin > cnt - a[i].sc - 2)
//        {
//            lf = a[i].sc;
//        }
//        nmin = min(nmin, cnt - a[i].sc - 2);
//        //   if (i==5) cout <<cnt << " " << a[i].sc << " " << nmin << "\n";
//        if ((cnt - a[i].sc - nmin) > res)
//        {
//            b = a[i].ft;
//            l = lf;
//            r = a[i].sc;
//        }
//        res = max(res, cnt - a[i].sc - nmin);
//        if (i == n || (i < n && a[i].ft != a[i + 1].ft))
//        {
//            nmin = 1e9;
//            cnt = 0;
//        }
//    }
//    cout << b << " " << l << " " << r << "\n";
//
//}






// 173271972 	Sep/24/2022 13:17UTC+8 	Ouha 	1692H - Gambling 	GNU C++17 	Accepted 	405 ms 	8800 KB


// 1st appear,  last appear
// count ..  no
// range: count(x) - (sz_range - count(x)) is max
// 2 * cnt - sz_range    max
// [l] == [r]
// 
// nonono .. max subarray sum ... who?
// when 1/2, won't continue.
// but .   1 1 1 2 2 2 1 2 2  .. how to start from first 2 ?
// ok  still need map .  map<a, pair<last idx, money>>
//
// ? when 2*cnt - sz_range < 0, restart . can? yes!.
// <last idx, money> == 2*cnt - sz
void fun1()
{
    int sz1;
    cin >> sz1;

    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }

    int a = vi[0];
    int l = 0;
    int r = 0;
    int mul = 1;        // 2*cnt-sz
    int cnt, sti, szr;
    // a, <cnt, st_idx>
    map<int, pair<int, int>> map2;
    
    for (int i = 0; i < sz1; ++i)
    {
        int t2 = vi[i];
        if (map2.find(t2) == map2.end())
        {
            map2[t2] = std::make_pair(1, i);
        }
        else
        {
            pair<int, int>& p = map2[t2];
            cnt = p.first + 1;
            sti = p.second;
            szr = i - sti + 1;
            if (cnt * 2 > szr)
            {
                if (cnt * 2 - szr > mul)
                {
                    mul = cnt * 2 - szr;
                    l = sti;
                    r = i;
                    a = t2;
                }
                ++p.first;
            }
            else
            {
                p.first = 1;
                p.second = i;
            }
        }
    }
    
    cout << a << ' ' << l + 1 << ' ' << r + 1 << endl;
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
