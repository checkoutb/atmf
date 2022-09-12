
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

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
#include <queue>
//#include <unordered_set>
//#include <numeric>
//#include <unordered_map>
//#include <string.h>       // memset

using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = vector<vector<int>>;
using myvi = vector<int>;

#define __test1

// D D

// Divide the vertices into two categories according to their degrees' parity.


//for (int i = 1; i <= n; i++)
//    if (degree[i] % 2 == 1)
//        ans = min(ans, a[i]);
//for (int i = 1; i <= m; i++)
//    if (degree[x[i]] % 2 == 0 && degree[y[i]] % 2 == 0)
//        ans = min(ans, a[x[i]] + a[y[i]]);




// 171610655 	Sep/10/2022 20:52UTC+8 	Ouha 	1711B - Party 	GNU C++17 	Accepted 	358 ms 	3800 KB

// 偶数个 pair，直接全部邀请就ok 了
// 奇数个 pair。。踢掉一个人，可能导致 断开2个 pair。。导致 还是奇数， 而且 可能 踢开3个人的 unhappy < 踢开一个人的。
// 还有 那个 priq ? 记得是的。
void fun1()
{
    int n, m;
    cin >> n >> m;
    
    myvi vi(n);     // unhappy
    for (int i = 0; i < n; ++i)
        cin >> vi[i];
    
    //myvvi vv2(n);
    //for (int i = 0; i < n; ++i)
    //{
    //    vv2[i] = { vi[i], i };
    //}
    //sort(begin(vv2), end(vv2));

    //myvvi vvi(m, myvi(2));
    //for (int i = 0; i < m; ++i)
    //    cin >> vvi[i][0] >> vvi[i][1];

    myvvi vvi(n);
    int t2, t3;
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> t2 >> t3;
        cnt++;
        --t2;
        --t3;
        vvi[t2].push_back(t3);
        vvi[t3].push_back(t2);
    }

    if (cnt % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }


    // 不行，因为 不邀请以后， pair 就断了， 下次 邀请 pair 的另一个人时， 无法知道 这个pair 断开。
    //// unhappy, last invite 。 就是 最后那道leetcode。
    //priority_queue<vector<int>, myvvi, greater<myvi>> priq;

    //for (int i = 0; i < n; ++i)
    //{
    //    priq.push({ vv2[i][0], i });
    //}

    // 这个 是不是 最多 不邀请 2个人， 就可以 必然 是 偶数pair？

    int ans = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        if (vvi[i].empty())
            continue;

        int p1 = i;
        int p2 = -1;
        if (vvi[p1].size() % 2 == 1)
        {
            ans = min(ans, vi[p1]);
        }
        else
        {
            for (int j = 0; j < vvi[p1].size(); ++j)
            {
                if (vvi[p1][j] > p1)
                {
                    p2 = vvi[p1][j];
                    if ((vvi[p1].size() + vvi[p2].size() - 1) % 2 == 1)
                    {
                        ans = min(ans, vi[p1] + vi[p2]);
                    }
                }
            }
        }
    }
    cout << ans << endl;

}


int main()
{
    int w = 0;
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
