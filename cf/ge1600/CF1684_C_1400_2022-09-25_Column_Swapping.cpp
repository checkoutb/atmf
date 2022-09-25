
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







// 173404122 	Sep/25/2022 16:48UTC+8 	Ouha 	1684C - Column Swapping 	GNU C++17 	Accepted 	358 ms 	5700 KB


void fun1()
{
#ifdef __test
    cout << "      ----------- " << endl;
#endif

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
    
    myvi swp;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 1; j < sz2; ++j)
        {
            if (vvi[i][j] < vvi[i][j - 1])
                goto AAA;
        }
        continue;

        AAA:
        myvi v2(begin(vvi[i]), end(vvi[i]));
        sort(begin(v2), end(v2));

#ifdef __test
        cout << &v2 << "  --         -- " << &vvi[i] << endl;
#endif

        for (int j = 0; j < sz2; ++j)
        {
            if (v2[j] != vvi[i][j])
            {
                swp.push_back(j);
            }
        }

        break;
    }
    
    if (swp.size() == 0)
    {
        cout << "1 1" << endl;
        return;
    }
    if (swp.size() > 2)
    {
        cout << -1 << endl;
        return;
    }

    int a = swp[0], b = swp[1];
    int x, y;
    int z = a ^ b;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 1; j < sz2; ++j)
        {
            x = j - 1;
            y = j;
            x = (x == a || x == b) ? z ^ x : x;
            y = (y == a || y == b) ? z ^ y : y;

            if (vvi[i][x] > vvi[i][y])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    cout << a + 1 << ' ' << b + 1 << endl;
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
