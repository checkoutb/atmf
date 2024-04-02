
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







// AC



// > prev
// subarray after min, is sorted ?
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    std::vector<int> vi(sz1, 0);
    for (int i = 0; i < sz1; ++i)
        cin>>vi[i];


    int dis = std::distance(std::begin(vi), std::min_element(begin(vi), end(vi)));

    for (int i = dis + 1; i < sz1; ++i)
    {
        if (vi[i] < vi[i - 1])
        {
            std::cout<<-1<<std::endl;
            return;
        }
    }

    std::cout<<dis<<std::endl;
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
