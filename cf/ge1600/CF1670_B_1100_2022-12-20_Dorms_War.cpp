
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








// tle...................


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    string pwd;
    cin >> pwd;
    cin >> sz2;

    bool arr[123] = { false };
    char ch;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> ch;
        arr[ch] = true;
    }
    
    int lst = -1;
    int ans = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (arr[pwd[i]])
        {
            //ans = max(ans, t2) + (lst != (i - 1) && lst != -1);

            if (lst == -1)
            {
                ans = i;
            }
            else
            {
                int t2 = i - lst - 1;
                ans = max(ans, t2 + 1);
            }

            lst = i;
        }
    }
    if (lst > 0)
        ans = max(ans, 1);

    cout << ans << endl;
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
