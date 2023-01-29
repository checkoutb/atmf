
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
#include <numeric>            // accumulate
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








// 187523644 	Jan / 01 / 2023 21:03UTC + 8 	Ouha 	1654C - Alice and the Cake 	GNU C++17 	Accepted 	342 ms 	3900 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    sort(begin(vi), end(vi));
    long long sum2 = std::accumulate(begin(vi), end(vi), 0LL);
    
    priority_queue<long long> priq;
    priq.push(sum2);
    
    for (int i = sz1 - 1; i >= 0; --i)
    {
        while (priq.top() > vi[i])
        {
            long long t2 = priq.top();
            priq.pop();
            priq.push(t2 / 2);
            priq.push((t2 + 1) / 2);
        }
        if (priq.top() == vi[i])
        {
            priq.pop();
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
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
