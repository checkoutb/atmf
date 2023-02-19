
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




// by creating b prefix sum arrays before answering any of the test cases





// tle
void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    int st, en;
    cin >> st >> en;
    
    int arr[20] = { 0 };
    for (int i = st; i <= en; ++i)
    {
        for (int j = 0; (1 << j) <= i; ++j)
        {
            if ((i & (1 << j)) != 0)
                ++arr[j];
        }
    }
    int mx = 0;
    for (int i = 0; i < 20; ++i)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    
    cout << en - st + 1 - mx << endl;
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
