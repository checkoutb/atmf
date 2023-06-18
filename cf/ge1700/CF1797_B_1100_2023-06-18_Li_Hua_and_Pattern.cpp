
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









// 210023922 	Jun/18/2023 14:26UTC+8 	Ouha 	1797B - Li Hua and Pattern 	GNU C++17 	Accepted 	577 ms 	4200 KB
// 11911

// 4 -> 2
// 3 -> 2

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    
    //vector<vector<int>> vvi(vector<int>(0, sz1), sz1);
    vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));

    for (int i = 0; i < sz1; ++i)
        for (int j = 0; j < sz1; ++j)
            cin >> vvi[i][j];
    
    for (int i = 0; i < (sz1 / 2 + sz1 % 2) && kk >= 0; ++i)
    {
        for (int j = 0; j < sz1; ++j)
        {
            if (vvi[i][j] != vvi[sz1 - 1 - i][sz1 - 1 - j])
            {
                vvi[i][j] = vvi[sz1 - i - 1][sz1 - 1 - j];
                --kk;
            }
        }
    }
    //cout << ((kk >= 0) ? "yes" : "no") << endl;
    //cout << ((kk >= 0 && kk % 2 == 0) ? "yes" : "no") << endl;
    if (kk < 0) {
        cout << "no" << endl;
    } 
    else 
    {
        if (sz1 % 2 == 1)
        {
            cout << "yes" << endl;
        }
        else
        {
            if (kk % 2 == 0)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
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
        
        #ifdef __test
        cout << _ << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
