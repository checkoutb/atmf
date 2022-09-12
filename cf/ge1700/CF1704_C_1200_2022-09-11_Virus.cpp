
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








// 171688337 	Sep/11/2022 16:33UTC+8 	Ouha 	1704C - Virus 	GNU C++17 	Accepted 	217 ms 	1400 KB

void fun1()
{
    int sz1;
    cin>>sz1;

    int cnt;
    cin>>cnt;

    myvi vi(cnt);
    for (int i = 0; i < cnt; ++i)
    {
        cin>>vi[i];
        --vi[i];
    }
    sort(begin(vi), end(vi));
    //myvvi gap;      // [,]
    myvi gap;
    for (int i = 1; i < cnt; ++i)
    {
        if (vi[i] > vi[i - 1] + 1)
        {
            //gap.push_back({vi[i - 1] + 1, vi[i] - 1});
            gap.push_back(vi[i] - vi[i - 1] - 1);
        }
    }
    if (vi[cnt - 1] + 1 < (vi[0] + sz1))
    {
        //gap.push_back({vi[cnt - 1]})
        gap.push_back(vi[0] + sz1 - vi[cnt - 1] - 1);
    }

    sort(begin(gap), end(gap));

    #ifdef __test
//    cout<<endl<<" -------------"<<endl;
//    cout<<"         ";
//    for (int i : gap)
//    {
//        cout<<i<<" , ";
//    }
//    cout<<endl<<endl;
    #endif // __test

    int t2 = 0;
    int ans = 0;
    for (int i = gap.size() - 1; i >= 0; --i)
    {
        int t3 = gap[i] - (t2 + t2);
        if (t3 <= 0)
            break;

        ++ans;
        ++t2;

        t3 -= 2;

        if (t3 >= 1)
        {
            ++t2;
            ans += t3;
        }

    }
    cout<<sz1 - ans<<endl;
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
