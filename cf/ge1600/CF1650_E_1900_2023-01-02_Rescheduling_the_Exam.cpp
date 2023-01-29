
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







// 187586883 	Jan / 02 / 2023 15:21UTC + 8 	Ouha 	1650E - Rescheduling the Exam 	GNU C++17 	Accepted 	343 ms 	800 KB

int try_move(vector<int>& vi, int mx, int mn, int mxen, int mv, int kk);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    vector<int> mxen;
    mxen.push_back(0);
    int mx = vi[0] - 1;

    vector<int> mnen;
    mnen.push_back(0);
    int mn = vi[0] - 1;

    for (int i = 1; i < sz1; ++i)
    {
        int t2 = vi[i] - vi[i - 1] - 1;
        if (t2 > mx)
        {
            mxen.clear();
            mx = t2;
            mxen.push_back(i);
        }
        else if (t2 == mx)
        {
            if (mxen.size() < 3)
                mxen.push_back(i);
        }

        if (t2 < mn)
        {
            mnen.clear();
            mn = t2;
            mnen.push_back(i);
        }
        else if (t2 == mn)
        {
            if (mnen.size() < 3)
                mnen.push_back(i);
        }
    }

    if (mnen.size() > 2)
    {
        cout << mn << endl;
        return;
    }
    else if (mnen.size() == 2)
    {
        if (mnen[0] + 1 != mnen[1])
        {
            cout << mn << endl;
            return;
        }
    }

    int ans = 0;

    if (mnen.size() == 2)
    {
        ans = try_move(vi, mx, mn, mxen[0], mnen[0], kk);
    }
    else
    {
        ans = try_move(vi, mx, mn, mxen[0], mnen[0], kk);
        if (mnen[0] != 0)
        {
            ans = max(ans, try_move(vi, mx, mn, mxen[0], mnen[0] - 1, kk));
        }
    }

    cout << ans << endl;
}

int try_move(vector<int>& vi, int mx, int mn, int mxen, int mv, int kk)
{
    int ans = 0;
    if (mv == vi.size() - 1)
    {
        ans = vi[0] - 1;
        for (int i = 1; i < vi.size() - 1; ++i)
        {
            ans = min(ans, vi[i] - vi[i - 1] - 1);
        }
        ans = min(ans, kk - vi[vi.size() - 2] - 1);
        return ans;
    }

    int t2 = ((mv == vi.size() - 1) ? kk : vi[mv + 1]) - (mv == 0 ? 0 : vi[mv - 1]) - 1;

    if (t2 > mx)
    {
        mx = t2;
        mxen = mv + 1;
    }

    int t3 = kk - vi[vi.size() - 1] - 1;
    int t4 = (mx - 1) / 2;

    if (t3 > t4)
    {
        ans = t3;
        for (int i = 0; i < vi.size(); ++i)
        {
            if (i == mv)
                continue;
            int pre = (i - 1 == mv) ? i - 2 : i - 1;

            pre = pre == -1 ? 0 : vi[pre];

            ans = min(ans, vi[i] - pre - 1);
        }
        return ans;
    }
    else
    {
        ans = t4;
        for (int i = 0; i < vi.size(); ++i)
        {
            if (i == mv)
                continue;
            int pre = (i - 1 == mv) ? i - 2 : i - 1;
            pre = pre == -1 ? 0 : vi[pre];
            ans = min(ans, vi[i] - pre - 1);
        }
        return ans;
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
