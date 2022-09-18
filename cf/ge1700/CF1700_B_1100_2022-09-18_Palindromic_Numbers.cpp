
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








// 172543200 	Sep/18/2022 17:49UTC+8 	Ouha 	1700B - Palindromic Numbers 	GNU C++17 	Accepted 	31 ms 	300 KB

void fun1()
{
    int sz1;
    cin>>sz1;

    string s;
    cin>>s;

    string ans(sz1, ' ');
    if (s[0] == '9')        // 90000+10001=100001  99999+10012=
    {
        // 做 111111111
        int carry = 0;
        for (int i = sz1 - 1; i >= 1; --i)
        {
            int t2 = s[i] - '0';
            int t3 = 1 + carry;
            if (t2 > t3)
            {
                t3 += 10;
                carry = -1;
                ans[i] = '0' + t3 - t2;
            }
            else
            {
                carry = 0;
                ans[i] = '0' + t3 - t2;
            }

//            int t2 = s[i] - '0';
//            if (t2 > 1)
//            {
//                s[i]++;
//                //t2 = 10 + t2;
//                ans[i] = '0' + 10 - t2;
//            }
//            else
//            {
//                ans[i] = '0' + 1 - t2;
//            }
        }
        ans[0] = '0' + 11 + carry - 9;
    }
    else
    {
        // 不进位，全部9
        for (int i = 0; i < sz1; ++i)
        {
            ans[i] = '0' + '9' - s[i];
        }
    }
    cout<<ans<<endl;
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
