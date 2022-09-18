
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









// 172438186 	Sep/17/2022 17:31UTC+8 	Ouha 	1703E - Mirror Grid 	GNU C++17 	Accepted 	140 ms 	400 KB

void fun1()
{
    int sz1;
    cin>>sz1;

    myvvi vv(sz1, myvi(sz1));
    string s;
    for (int i = 0; i < sz1; ++i)
    {
        cin>>s;
        for (int j = 0; j < sz1; ++j)
        {
            vv[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < (sz1 + 1) / 2; ++i)
    {
        for (int j = 0; j < sz1 / 2; ++j)
        {
            int t2 = vv[i][j] + vv[j][sz1 - 1 - i] + vv[sz1 - 1 - i][sz1 - 1 - j] + vv[sz1 - 1 - j][i];
            ans += min(t2, 4 - t2);
        }
    }
    cout<<ans<<endl;
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
