
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





// dp



// g

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<vector<int>> vvi(sz1 + 1);
    int t2, t3;
    for (int i = 1; i < sz1; ++i)
    {
        cin >> t2 >> t3;
        vvi[t2].push_back(t3);
        vvi[t3].push_back(t2);
    }
    
    int cnt = 0;
    int sum2 = 0;

    vector<int> vi(sz1 + 1);        // node's value
    
    vector<int> v2(sz1 + 1);        // count of node's neighbour
    queue<int> que1;        // 1 neighbour
    for (int i = 1; i <= sz1; ++i)
    {
        v2[i] = vvi[i].size();
        if (v2[i] == 1)
        {
            que1.push(i);
        }
    }
    
    while (!que1.empty())
    {
        t2 = que1.front();
        que1.pop();

        if (vi[t2] > 1 || vi[t2] == -1)
            continue;

        if (vi[t2] == 1)
        {
            if (vvi[t2].size() == 1 && vi[vvi[t2][0]] == 1)
            {
                ++cnt;
            }
            vi[t2] = -1;
        }
        else
        {
            ++cnt;
            vi[t2] = vvi[t2].size();
        }

        for (int ngh : vvi[t2])
        {
            if (vi[t2] != -1 && vi[ngh] == 0)
            {
                vi[ngh] = 1;
            }
            --v2[ngh];
            if (v2[ngh] == 1)
            {
                que1.push(ngh);
            }
        }

    }
    
    for (int i = 1; i <= sz1; ++i)
    {
        if (vi[i] == -1)
            vi[i] = 1;

        sum2 += vi[i];
    }

    cout << cnt << ' ' << sum2 << endl;
    for (int i = 1; i <= sz1; ++i)
    {
        cout << vi[i] << ' ';
    }
    cout << endl;
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
