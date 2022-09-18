
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
//#include <numeric>
#include <unordered_map>
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








// 172520195 	Sep/18/2022 13:32UTC+8 	Ouha 	1702C - Train and Queries 	GNU C++17 	Accepted 	2043 ms 	22100 KB
// ????
// 看了 tutorial 的 代码， 用了 map<int, pair<int, int>>m;
// 所以 尝试把 unordered_map 换成了 map。 AC 了。。



// tle

void fun1()
{
    string emp;
//    cin>>emp;

    int sz1;
    cin>>sz1;
    int qsz;
    cin>>qsz;

    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin>>vi[i];
    }

    myvvi vvi(qsz, myvi(2));
    for (int i = 0; i < qsz; ++i)
    {
        cin>>vvi[i][0]>>vvi[i][1];
    }

    map<int, int> fst;
    map<int, int> lst;

    for (int i = 0; i < sz1; ++i)
    {
        int t2 = vi[i];
        if (fst.find(t2) == fst.end())
        {
            fst[t2] = i + 1;
        }
        lst[t2] = i + 1;
    }

    for (myvi& qry : vvi)
    {
        int a = qry[0];
        int b = qry[1];

        #ifdef __test
        cout<<a<<" + "<<b<<endl;
        #endif // __test

        a = fst[a];
        b = lst[b];

        #ifdef __test
        cout<<a<<" - "<<b<<endl;
        #endif // __test

        if (a != 0 && a < b)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


//        if (fst.find(a) != fst.end() && fst.find(b) != fst.end())
//        {
//            if (fst[a] < lst[b])
//            {
//                cout<<"yes"<<endl;
//            }
//            else
//            {
//                cout<<"no"<<endl;
//            }
//        }
//        else
//        {
//            cout<<"no"<<endl;
//        }

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
