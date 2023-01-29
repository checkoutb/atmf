
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









//186160901 	Dec / 21 / 2022 08:52UTC + 8 	Ouha 	1669G - Fall Down 	GNU C++17 	Accepted 	61 ms 	200 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    
    vector<string> vs(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vs[i];
    }
    
    for (int j = sz2 - 1; j >= 0; --j)
    {
        int lst = sz1;      // immovable
        for (int i = sz1 - 1; i >= 0; --i)
        {
            switch (vs[i][j])
            {
            case '*':
                if (i == lst - 1)
                {
                    --lst;
                }
                else
                {
                    vs[--lst][j] = '*';
                    vs[i][j] = '.';
                }
                break;
            case 'o':
                lst = i;
                break;
            case '.':

                break;
            }
        }
    }

    for (string& s : vs)
        cout << s << endl;
    
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
