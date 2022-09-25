
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







// 173061220 	Sep/22/2022 20:52UTC+8 	Ouha 	1695B - Circle Game 	GNU C++17 	Accepted 	109 ms 	0 KB

// odd£¬ mike alway win £¬ just take all
// event, sum(odd idx) > sum(even idx) ?  .. they just take one stone. .. no... first min lose...
void fun1()
{
    int sz1;
    cin >> sz1;

    //ll sum1 = 0;
    //ll sum0 = 0;
    //ll t2 = 0;

    int t2 = 0;
    int mn1 = 2000000000;
    int mn2 = mn1;
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        if (i % 2 == 1)
        {
            if (t2 < mn1)
            {
                mn1 = t2;
                idx1 = i;
            }
        }
        else
        {
            if (t2 < mn2)
            {
                mn2 = t2;
                idx2 = i;
            }
        }
    }
    
    if (sz1 % 2 == 1)
    {
        cout << "Mike" << endl;
        return;
    }

    if (mn1 < mn2)
    {
        cout << "Mike" << endl;
    }
    else if (mn1 > mn2)
    {
        cout << "Joe" << endl;
    }
    else
    {
        if (idx2 < idx1)
        {
            cout << "Joe" << endl;
        }
        else
        {
            cout << "Mike" << endl;
        }
    }

    //if (sum0 > sum1)
    //{
    //    cout << "Mike" << endl;
    //}
    //else
    //{
    //    cout << "Joe" << endl;
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
