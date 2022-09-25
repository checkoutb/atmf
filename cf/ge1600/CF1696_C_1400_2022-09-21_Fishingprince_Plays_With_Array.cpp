
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
// 操作是 可以撤销的， 所以 2个数组 都下降到 最小值。




// 少了一个 sum2, 导致v1 最后 多余一些。

//173053415 	Sep / 22 / 2022 19:42UTC + 8 	Ouha 	1696C - Fishingprince Plays With Array 	GNU C++17 	Accepted 	343 ms 	1900 KB
//172962471 	Sep / 21 / 2022 22 : 35UTC + 8 	Ouha 	1696C - Fishingprince Plays With Array 	GNU C++17 	Wrong answer on test 8 	312 ms 	1900 KB
//172958549 	Sep / 21 / 2022 22 : 03UTC + 8 	Ouha 	1696C - Fishingprince Plays With Array 	GNU C++17 	Wrong answer on test 8 	327 ms 	1900 KB
//172958384 	Sep / 21 / 2022 22 : 02UTC + 8 	Ouha 	1696C - Fishingprince Plays With Array 	GNU C++17 	Wrong answer on test 6 	296 ms 	1400 KB


// 我这里是 把 a 下降到最低， 然后 根据b 来 尝试重组 ， 但是 wrong 了。
// 想不出这个反例。。。

// error
void fun1()
{
    int sz1, m, sz2;
    cin >> sz1 >> m;

    ll sum2 = 0;

    myvi v1(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> v1[i];
        sum2 += v1[i];
    }

    cin >> sz2;
    myvi v2(sz2);
    for (int i = 0; i < sz2; ++i)
    {
        cin >> v2[i];
        sum2 -= v2[i];
    }
    if (sum2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    vector<pair<int, ll>> vp;
    for (int i = 0; i < sz1; ++i)
    {
        int t2 = v1[i];
        ll cnt = 1;
        while (t2 % m == 0)
        {
            t2 /= m;
            cnt *= m;
        }
        if (!vp.empty() && vp[vp.size() - 1].first == t2)
        {
            vp[vp.size() - 1].second += cnt;
            continue;
        }
        else
        {
            vp.push_back(std::make_pair(t2, cnt));
        }
    }

#ifdef __test
    cout << " -------- " << endl;
    for (auto& p : vp)
    {
        cout << p.first << " : " << p.second << endl;
    }
#endif


    int idx = 0;
    bool b2 = true;
    for (int i = 0; i < sz2 && b2; ++i)
    {
        if (idx >= vp.size())
        {
#ifdef __test
            cout << i << " 1111111111111 " << endl;
#endif
            b2 = false;
            break;
        }
        ll cnt = 1;
        while (v2[i] > (1LL * vp[idx].first * cnt))
        {
            cnt *= m;
        }

        if (cnt > vp[idx].second || v2[i] != 1LL * vp[idx].first * cnt)
        {
#ifdef __test
            cout << " 222222222 " << idx << ", " << cnt << ", " << vp[idx].second << ", " << v2[i] << " ? " << i << " - " << cnt << endl;
#endif
            b2 = false;
        }
        else
        {
            vp[idx].second -= cnt;
            if (vp[idx].second == 0)
                ++idx;
        }

    }
    cout << (b2 ? "YES" : "NO") << endl;
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
