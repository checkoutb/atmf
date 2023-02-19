
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


// D D

//ll dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };
//function<void(ll, ll)> dfs = [&](ll i, ll j) -> void {
//    vis[i][j] = 1;
//    ctr++;
//    for (ll X = 0; X < 4; ++X) {
//        ll mask = (1LL << X);
//        if (!(adj[i][j] & mask)) {  // not a wall
//            ll ni = i + dx[X];
//            ll nj = j + dy[X];
//            if (!valid(ni, nj)) continue;
//            dfs(ni, nj);
//        }
//    }
//};

//sort(ans.begin(), ans.end(), greater<ll>());






// 194185614 	Feb/19/2023 13:00UTC+8 	Ouha 	1600J - Robot Factory 	GNU C++17 	Accepted 	733 ms 	7200 KB
// 3287

// 8  4   2    1
// Up Right Down Left
// 0  
// 1 
int dfsa1(vector<vector<int>>& vvi, int r, int c);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    myvvi vvi(sz1, myvi(sz2));
    
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            cin >> vvi[i][j];
        }
    }
    vector<int> ans;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (vvi[i][j] != -1)
            {
                ans.push_back(dfsa1(vvi, i, j));
            }
        }
    }
    sort(begin(ans), end(ans));
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << endl;
}

int dfsa1(vector<vector<int>>& vvi, int r, int c)
{
    if (vvi[r][c] == -1)
        return 0;

    int t2 = vvi[r][c];
    vvi[r][c] = -1;
    int ans = 1;
    if ((t2 & 8) == 0)
    {
        ans += dfsa1(vvi, r - 1, c);
    }
    if ((t2 & 4) == 0)
        ans += dfsa1(vvi, r, c + 1);
    if ((t2 & 2) == 0)
        ans += dfsa1(vvi, r + 1, c);
    if ((t2 & 1) == 0)
        ans += dfsa1(vvi, r, c - 1);

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
