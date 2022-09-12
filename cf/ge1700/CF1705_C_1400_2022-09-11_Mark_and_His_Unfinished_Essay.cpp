
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








// 171684487 	Sep/11/2022 15:43UTC+8 	Ouha 	1705C - Mark and His Unfinished Essay 	GNU C++17 	Accepted 	171 ms 	500 KB
void fun1()
{
    int sz1,cnt,qsz;
    cin>>sz1>>cnt>>qsz;
    string wd;
    cin>>wd;

    vector<vector<ll>> vvi(cnt, vector<long long>(2));
    for (int i = 0; i < cnt; ++i)
    {
        cin>>vvi[i][0]>>vvi[i][1];
        --vvi[i][0];
        --vvi[i][1];
    }

    vector<ll> vi(qsz);
    for (int i = 0; i < qsz; ++i)
    {
        cin>>vi[i];
        --vi[i];
    }

    ll t2 = sz1;
    vector<vector<ll>> vv2(cnt, vector<ll>(2));     // [st, en]
    for (int i = 0; i < cnt; ++i)
    {
        vv2[i][0] = t2;
        t2 += (vvi[i][1] - vvi[i][0] + 1);
        vv2[i][1] = t2 - 1;
    }

    for (int i = 0; i < qsz; ++i)
    {
        ll q = vi[i];

        for (int j = cnt - 1; j >= 0 && q >= sz1; --j)
        {
            if (q >= vv2[j][0] && q <= vv2[j][1])
            {
                q = vvi[j][0] + (q - vv2[j][0]);
            }
        }
        cout<<wd[q]<<endl;
    }

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
