
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








// tle..

// bit/fenwick tree    segment tree


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> sz2;
    
    myvi vix(sz1);
    myvi viy(sz1);
    myvvi vvi(sz2);
    int t2;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> t2;
        vvi[i].push_back(t2);
        for (int j = 0, mxj = t2 == 3 ? 4 : 2; j < mxj; ++j)
        {
            cin >> t2;
            vvi[i].push_back(t2 - 1);
        }
    }
    
    for (int i = 0; i < sz2; ++i)
    {
        if (vvi[i][0] == 1)
        {
            ++vix[vvi[i][1]];
            ++viy[vvi[i][2]];
        }
        else if (vvi[i][0] == 2)
        {
            --vix[vvi[i][1]];
            --viy[vvi[i][2]];
        }
        else
        {
            bool allx = true;
            for (int j = vvi[i][1]; j <= vvi[i][3] && allx; ++j)
            {
                if (vix[j] == 0)
                    allx = false;
            }
            bool ally = true;
            for (int j = vvi[i][2]; j <= vvi[i][4] && !allx && ally; ++j)
                if (viy[j] == 0)
                    ally = false;

            if (allx || ally)
                cout << "Yes" << endl;
            else
                cout << "NO" << endl;

        }
    }
    
    
    
}


int main()
{
    int w = 1;
    //cin>>w;
    
    
    
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
