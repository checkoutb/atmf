
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


// D


// std::vector a(n, std::vector<int>(m)), f(a), g(a);



// 174233151 	Oct/01/2022 18:08UTC+8 	Ouha 	1676D - X-Sum 	GNU C++17 	Accepted 	62 ms 	400 KB


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> sz2;
    
    myvvi vvi(sz1, myvi(sz2));
    
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            cin >> vvi[i][j];
        }
    }

    myvi v1(sz1 + sz2 - 1);     // sz1 - i + j - 1
    myvi v2(sz1 + sz2 - 1);     // i + j

    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            v1[sz1 - i + j - 1] += vvi[i][j];
            v2[i + j] += vvi[i][j];
        }
    }
    int mx = 0;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (v1[sz1 - i + j - 1] + v2[i + j] - vvi[i][j] > mx)
            {
                mx = v1[sz1 - i + j - 1] + v2[j + i] - vvi[i][j];
            }
        }
    }
    cout << mx << endl;

    //int mx1, mx2;
    //mx1 = mx2 = 0;
    //
    //myvi v1(sz2);       // '\'
    //myvi v2(sz2);       // '/'
    //
    //int a1, a2;

    //for (int i = 0; i < sz2; ++i)
    //{
    //    v1[i] = vvi[0][i];
    //    v2[i] = v1[i];
    //    //mx1 = max(mx1, v1[i]);
    //    if (mx1 < v1[i])
    //    {
    //        mx1 = v1[i];
    //        mx2 = mx1;
    //        a1 = a2 = i;
    //    }
    //}

    //for (int i = 1; i < sz1; ++i)
    //{
    //    myvi v11(sz2);
    //    myvi v22(sz2);

    //    for (int j = 0; j < sz2; ++j)
    //    {
    //        v11[j] = vvi[i][j] + (j == 0 ? 0 : v1[j - 1]);
    //        if (v11[j] > mx1)
    //        {

    //        }
    //        mx1 = max(mx1, v11[j]);

    //        v22[j] = vvi[i][j] + (j == sz2 - 1 ? 0 : v2[j + 1]);
    //        mx2 = max(mx2, v22[j]);
    //    }

    //    swap(v1, v11);
    //    swap(v2, v22);
    //}
    //
    //cout << mx1 + mx2 << endl;
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
