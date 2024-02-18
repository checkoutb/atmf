
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







/*

uf，有多少个组，那么 max 就是多少

记录下 每个组有没有重复边(就是 2的邻居是4， 4的邻居是2，重复的关系)， 所有有重复边的组可以合起来， 所以就是 没有重复边的组+1 就是 min


*/



void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;

    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin>>vi[i];







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
