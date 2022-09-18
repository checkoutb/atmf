
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
#include <set>
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

// 如果有 >=3个 的正数，那么 最大的3个正数的 和 必然 是一个 更大的正数。 不符合条件。
// 如果有 >=3 负数。
// 0 的个数 多于 2的话， 再多也没有用。
// 所以一共最多需要 检查 6个数字 。 brute-force 。。。




// error
// 3个值 也需要成闭包。
// 是不是 要么 全0 ，要么 就3个元素，且成闭包？
// 不是  1 0 0 0 0 -1        3 0 0 0 -3
void fun1()
{
    int sz1;
    cin>>sz1;

    myvi v(sz1);
//    bool not0 = false;
    int cnt0 = 0;
    int mx = -1000000009;
    int mn = 1000000009;
    for (int i = 0; i < sz1; ++i)
    {
        cin>>v[i];
//        if (v[i] != 0)
//            not0 = true;
        if (v[i] == 0)
            ++cnt0;
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }

    if (v.size() == 3)
    {
        int t2 = v[0] + v[1] + v[2];
        if (t2 == v[0] || t2 == v[1] || t2 == v[2])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        if (cnt0 == sz1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            if (cnt0 + 2 == sz1)
            {
                if (mn + mx == 0)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }

}


// ？？？ 。。。。。我。。
// ai+aj+ak=al  <=> ai+aj=al-ak
// 那么的简单，却又那么的难。 ... too naive。。 真的不简单。。
void fun1_error()
{
    int sz1;
    cin>>sz1;

    myvi v(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin>>v[i];
    }

    set<int> set2;
    for (int k = sz1 - 1; k >= 2; --k)
    {
        for (int i = 0; i < sz1; ++i)
        {

        }
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

        //cout<<endl;
    }


    return 0;
}
