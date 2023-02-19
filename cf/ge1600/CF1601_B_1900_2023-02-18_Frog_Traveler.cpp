
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









// tle
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> va(sz1 + 1);
    vector<int> vb(sz1 + 1);

    for (int i = 1; i <= sz1; ++i)
        cin >> va[i];
    for (int i = 1; i <= sz1; ++i)
        cin >> vb[i];
    
    vector<int> vi(sz1 + 1, -1);        // min steps
    vector<int> v2(sz1 + 1, -1);        // last step/position
    vector<int> v4(sz1 + 1, 0);
    
    vi[sz1] = 0;

    //int stp = 0;
    queue<int> que1;
    que1.push(sz1);
    int t2 = 0;
    int t3 = 0;
    while (!que1.empty() && vi[0] == -1)
    {
        //for (int e = 0, mxe = que1.size(); e < mxe; ++e)
        int mxe = que1.size();
        while (mxe-- > 0)
        {
            t2 = que1.front();      // now position (meter)
            que1.pop();
            if (t2 - va[t2] <= 0)
            {
                vi[0] = vi[t2] + 1;
                v2[0] = t2;
                //v4[0] = 
                break;
            }
            for (int i = 1; i <= va[t2]; ++i)
            {
                t3 = t2 - i + vb[t2 - i];
                //t3 = t3 < 0 ?
                if (vi[t3] == -1)
                {
                    vi[t3] = vi[t2] + 1;
                    v2[t3] = t2;
                    v4[t3] = t2 - i;
                    que1.push(t3);
                }
            }
        }
    }
    
    if (vi[0] == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << vi[0] << endl;
        vector<int> v3(vi[0]);
        int idx = v3.size() - 2;
        t2 = v2[0];
        while (t2 != -1 && idx >= 0)
        {
            v3[idx--] = v4[t2];
            t2 = v2[t2];
        }
        for (int i : v3)
            cout << i << ' ';
        cout << endl;
    }

}


int main()
{
    int w = 1;
    // cin>>w;
    
    
    
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
