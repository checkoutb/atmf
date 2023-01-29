
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

#include <stack>
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




// D
//      iota(begin(uf), end(uf), 0);
//      uf[vvi[i][1]] = uf[vvi[i][2]];
// ..........................


// g

//Test: #4, time: 202 ms., memory : 262144 KB, exit code : -1, checker exit code : 0, verdict : MEMORY_LIMIT_EXCEEDED
//Input
//1000
//2 483182 483182
//1 483182
//2 139857 189487


inline int ufa1(vector<int>& vi, int idx);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<vector<int>> vvi(sz1, vector<int>(3));
    int t2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        if (t2 == 1)
        {
            vvi[i][0] = 1;
            cin >> vvi[i][1];
        }
        else
        {
            vvi[i][0] = 2;
            cin >> vvi[i][1];
            cin >> vvi[i][2];
        }
    }
    
    vector<int> uf(500001, -1);
    
    myvi ans;
    int a, b;
    stack<int> stk;
    for (int i = sz1 - 1; i >= 0; --i)
    {
        if (vvi[i][0] == 1)
        {
            //ans.push_back(ufa1(uf, vvi[i][1]));           // WHY this will memory limit exceeded.

            //t2 = ufa1(uf, vvi[i][1]);       // memory limit.
            //ans.push_back(t2);


            //t2 = vvi[i][1];
            //while (uf[t2] != -1 && uf[t2] != t2)
            //{
            //    t2 = uf[t2];
            //}
            //uf[vvi[i][1]] = t2;       // just change one. not every. so maybe this is the reason of TLE.


            t2 = vvi[i][1];
            stk.push(t2);
            while (uf[t2] != -1 && uf[t2] != t2)            // M L E ....
            {
                t2 = uf[t2];
                stk.push(t2);
            }
            while (!stk.empty())
            {
                uf[stk.top()] = t2;
                stk.pop();
            }

            ////ans.emplace_back(t2);
            ans.push_back(t2);
        }
        else
        {
            uf[vvi[i][1]] = vvi[i][2];
        }
    }

    //std::reverse(begin(ans), end(ans));
    for (int i = 0; i < ans.size() / 2; ++i)
    {
        t2 = ans[i];
        ans[i] = ans[ans.size() - i - 1];
        ans[ans.size() - 1 - i] = t2;
    }

    for (int i : ans)
        cout << i << ' ';
    cout << endl;
}

inline int ufa1(vector<int>& vi, int idx)
{
    return (vi[idx] == -1 || vi[idx] == idx) ? idx : (vi[idx] = ufa1(vi, vi[idx]));
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
