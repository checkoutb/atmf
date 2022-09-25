
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

// 必然是 k 个全部用完。
// 第一个skip 会使得 增加 n-i 点伤害， 由于是全部用完的， 所以 多造成了 k-1 点伤害。
// 第二个 skip  会 增加 n-idx 点伤害， 由于是全部用完， 所以 多造成了 k-2 点伤害。
// k 是用完的， 所以 最后 一个 skip  多造成 0 点伤害。
//  多造成的 伤害 始终是 k(k-1)/2。
// 所以 n-idx 进行 贪婪。




// 6 5    4 1 100 100 1 1
//error
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> kk;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    vector<pair<int, int>> vp(sz1);

    for (int i = 0; i < sz1; ++i)
    {
        vp[i].first = vi[i] - (sz1 - 1 - i);
        vp[i].second = i;
    }
    
    sort(begin(vp), end(vp));
    int cnt = 0;
    for (int i = sz1 - 1; i >= 0 && cnt < kk; --i)
    {
        if (vp[i].first <= 0)
        {
            break;
        }
        ++cnt;
        vi[vp[i].second] = -1;
    }

    int skp = 0;
    for (int i = sz1 - 1; i >= 0 && cnt < kk; --i)
    {
        if (vi[i] != -1)
        {

            vi[i] = -1;
            ++cnt;
        }
    }

    ll ans = 0LL;
    cnt = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (vi[i] == -1)
        {
            ++cnt;
            continue;
        }
        ans += cnt + vi[i];
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
