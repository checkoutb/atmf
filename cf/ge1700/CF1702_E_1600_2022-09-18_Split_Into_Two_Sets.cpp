
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
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE


// D

// uf

//    vector<int> deg(n);
//    dsu d(2 * n);
//    for (int i = 0; i < n; i++) {
//      int x, y;
//      cin >> x >> y;
//      --x; --y;
//      deg[x] += 1;
//      deg[y] += 1;
//      d.unite(x, y + n);
//      d.unite(x + n, y);
//    }
//    bool ok = true;
//    for (int i = 0; i < n; i++) {
//      if (deg[i] > 2) {
//        ok = false;
//      }
//      if (d.get(i) == d.get(i + n)) {
//        ok = false;
//      }
//    }





// 172513482 	Sep/18/2022 11:21UTC+8 	Ouha 	1702E - Split Into Two Sets 	GNU C++17 	Accepted 	514 ms 	11900 KB

void fun1()
{
    int sz1;
    cin>>sz1;

    vector<vector<int>> vvi(sz1, myvi(2));

    myvvi vv2(sz1 + 1);

    myvi vi(sz1);

    for (int i = 0; i < sz1; ++i)
    {
        cin>>vvi[i][0]>>vvi[i][1];
        vv2[vvi[i][0]].push_back(i);
        vv2[vvi[i][1]].push_back(i);
    }

    for (int i = 0; i < sz1; ++i)
    {
        if (vv2[i + 1].size() != 2)             // 找不出例子 来 反证 这个if，但是 不加的话，是错的。  // {1,2},{2,3},{2,4},{2,5}
        {
            cout<<"NO"<<endl;
            return;
        }
        if (vi[i] != 0)
            continue;

        int a = vvi[i][0], b = vvi[i][1];
        if (a == b)
        {
            cout<<"NO"<<endl;
            return;
        }

        //vi[i] = 1;

        int flg = 1;

        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            for (int i4 = 0, mxi4 = q.size(); i4 < mxi4; ++i4)
            {
                int idx = q.front();
                q.pop();

                if (vi[idx] == flg)
                    continue;

                if (vi[idx] != 0)
                {
                    cout<<"NO"<<endl;
                    return;
                }

                vi[idx] = flg;
                a = vvi[idx][0];
                b = vvi[idx][1];

                for (int j = 0; j < vv2[a].size(); ++j)     // sz == 2
                {
                    if (vv2[a][j] != idx)
                        q.push(vv2[a][j]);
                }
                for (int j = 0; j < vv2[b].size(); ++j)
                {
                    if (vv2[b][j] != idx)
                        q.push(vv2[b][j]);
                }

            }

            flg = (flg == 1 ? -1 : 1);
        }

    }

    cout<<"yes"<<endl;

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
