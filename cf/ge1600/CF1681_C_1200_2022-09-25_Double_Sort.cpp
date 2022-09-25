
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









// 173423265 	Sep/25/2022 20:03UTC+8 	Ouha 	1681C - Double Sort 	GNU C++17 	Accepted 	46 ms 	100 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi v1(sz1);
    myvi v2(sz1);

    for (int i = 0; i < sz1; ++i)
        cin >> v1[i];

    for (int j = 0; j < sz1; ++j)
        cin >> v2[j];
    
    vector<pair<int, int>> vp;
    for (int i = 0; i < sz1; ++i)
    {
        int mni = i;
        for (int j = i + 1; j < sz1; ++j)
        {
            if (v1[j] < v1[mni])
            {
                mni = j;
            }
            else if (v1[j] == v1[mni])
            {
                if (v2[j] < v2[mni])
                {
                    mni = j;
                }
            }
        }
        if (i != mni)
        {
            vp.push_back(make_pair(i, mni));
            swap(v2[i], v2[mni]);
            swap(v1[i], v1[mni]);
        }

    }
    
    for (int i = 1; i < sz1; ++i)
    {
        if (v2[i] < v2[i - 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << vp.size() << endl;
    for (pair<int, int>& p : vp)
    {
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
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
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
