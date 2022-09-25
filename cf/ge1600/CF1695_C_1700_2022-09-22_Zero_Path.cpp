
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

// 每次移动 +-1， 所以保存 这个格子上的 max 和 min
// 这。。。



static int arr[1001][1001];

//static int arr2[1001][1001];




// tle
void fun1()
{
    int sz1, sz2;
    cin >> sz1 >> sz2;

    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            cin >> arr[i][j];
        }
    }

    if ((sz1 + sz2 - 1) % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }

    vector<set<int>> vsi(sz1);

    int t2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        t2 += arr[i][0];
        vsi[i].insert(t2);
    }

    for (int j = 1; j < sz2; ++j)
    {
        t2 = 0;
        vector<set<int>> vs2(sz1);
        for (int i = 0; i < sz1 - 1; ++i)
        {
            for (int cnt : vsi[i])
            {
                vs2[i].insert(cnt + arr[i][j]);
                //vs2[i + 1].insert(cnt + arr[i + 1][j]);
            }
        }

        for (int cnt : vsi[sz1 - 1])
        {
            vs2[sz1 - 1].insert(cnt + arr[sz1 - 1][j]);
        }


        for (int i = 1; i < sz1; ++i)
        {
            for (int cnt : vs2[i - 1])
            {
                vs2[i].insert(cnt + arr[i][j]);
            }
        }


        swap(vsi, vs2);
    }

    if (vsi[sz1 - 1].find(0) != vsi[sz1 - 1].end())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    //memset(arr, 123456, sizeof(arr));
    //
    //for (int i = 0; i < sz1; ++i)
    //{
    //    for (int j = 0; j < sz2; ++j)
    //    {
    //        cin >> arr2[i][j];
    //    }
    //}
    //
    //int t2 = 0;
    //for (int i = 0; i < sz1; ++i)
    //{
    //    t2 += arr2[i][0];
    //    arr[i][t2] = i + 1;
    //}

    //for (int j = 1; j < sz2; ++j)
    //{
    //    t2 = 0;
    //    for (int i = 0; i < sz1; ++i)
    //    {

    //    }
    //}
    
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
