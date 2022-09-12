
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

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>
#define __test1









// 171560438 	Sep/10/2022 11:15UTC+8 	Ouha 	1715B - Beautiful Array 	GNU C++17 	Accepted 	31 ms 	0 KB

// sz1, divide, beauty, sum
void fun1(long long n, long long div, long long b, long long s)
{
    if (s / div < b)
    {
        cout << -1 << endl;
        return;
    }

    if ((div * b + (div - 1) * n) < s)
    {
        cout << -1 << endl;
        return;
    }

    long long t2 = 0;
    
    t2 = (div - 1) + (b * div);
    if (t2 > s)
        t2 = s;

    cout << t2 << ' ';

    t2 = s - t2;

    for (int i = 1; i < n; ++i)
    {
        if (t2 >= div)
        {
            cout << (div - 1) << ' ';
            t2 -= (div - 1);
        }
        else
        {
            cout << t2 << ' ';
            t2 = 0;
        }
    }
    cout << endl;
}


int main()
{
    int w = 0;
    cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        
        fun1(n,k,b,s);
        
        //cout<<endl;
    }
    
    
    return 0;
}
