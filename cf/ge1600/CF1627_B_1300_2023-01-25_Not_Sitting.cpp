
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
#include <queue>
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







// 190462915 	Jan/25/2023 16:27UTC+8 	Ouha 	1627B - Not Sitting 	GNU C++17 	Accepted 	31 ms 	400 KB 

// max( to 4 corner) . priq
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    
    //priority_queue<int> priq;

    vector<int> vi(sz1 * sz2);

    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            vi[i * sz2 + j] = max(i, sz1 - i - 1) + max(j, sz2 - j - 1);
        }
    }
    
    std::sort(begin(vi), end(vi));
    for (int i : vi)
        cout << i << ' ';
    cout << endl;
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
