
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








// ....
//186526189 	Dec / 24 / 2022 11:56UTC + 8 	Ouha 	1667A - Make it Increasing 	GNU C++17 	Accepted 	358 ms 	0 KB

void cala1(int st, int en, vector<int>& vi, map<int, long long>& map2, long long& ans);
long long cnta1(map<int, long long>& map2, vector<int>& vi, int idx0);

void fun1()
{
    int sz1;
    cin >> sz1;

    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }

    long long ans = 1LL << 60;
    map<int, long long> map2;
    for (int i = 0; i < sz1; ++i)
    {
        ans = min(ans, cnta1(map2, vi, i));
    }
    cout << ans << endl;
}


// error
void fun1_1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int st = 0;
    int en = sz1 - 1;
    
    long long ans = 1LL << 60;

    map<int, long long> map2;

    cala1(st, en, vi, map2, ans);

    cout << ans << endl;
}

void cala1(int st, int en, vector<int>& vi, map<int, long long>& map2, long long& ans)
{
    while (st < en)
    {
        int md = (st + en) / 2;
        long long t2 = cnta1(map2, vi, md);
        long long t3 = cnta1(map2, vi, md + 1);

        if (min(t2, t3) > ans)
            break;

        if (t2 == t3)
        {
            ans = t2;
            cala1(st, md, vi, map2, ans);
            cala1(md + 1, en, vi, map2, ans);
            break;
        }
        else if (t2 < t3)
        {
            ans = min(ans, t2);
            en = md - 1;
        }
        else
        {
            ans = min(ans, t3);
            st = md + 2;
        }
    }
}

long long cnta1(map<int, long long>& map2, vector<int>& vi, int idx0)
{
    long long ans = 0LL;
    long long num = 0LL;

    for (int i = idx0 + 1; i < vi.size(); ++i)
    {
        if (vi[i] > num)
        {
            ans++;
            num = vi[i];
        }
        else
        {
            ans += num / vi[i] + 1;
            num = vi[i] * (num / vi[i] + 1);
        }
    }
    num = 0LL;
    for (int i = idx0 - 1; i >= 0; --i)
    {
        ans += -1LL * num / vi[i] + 1;
        num = -1LL * vi[i] * (-1LL * num / vi[i] + 1);
    }
    return ans;
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
