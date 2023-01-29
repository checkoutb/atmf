
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




// D
// 2次 for for 
// 第一次， for(长度) { for(i=长度，i<sz1){ 计算sum， 保存max } }
// 第二次，for(k) { for (上面计算出来的数组) {  } }
//
// ...


// g


// error
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;      // x
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    int st = -1;
    int sz = -1;
    int sum2 = 0;
    int mxst = -1;
    int mxsz = -1;
    int mxsum2 = 0;
    for (int i = 0; i <= sz1; ++i)
    {
        if (mxsz < i)
        {
            st = 0;
            sum2 = 0;
            sz = 0;
            mxst = 0;
            mxsum2 = 0;
            mxsz = 0;
            for (int j = 0; j < sz1; ++j)
            {
                sum2 += vi[j];
                ++sz;
                if (sum2 + min(sz, i) * kk < 0)
                {
                    sum2 = 0;
                    sz = 0;
                    st = j + 1;
                }
                else if (sum2 + min(sz, i) * kk > mxsum2)
                {
                    mxsum2 = sum2;
                    mxsz = sz;
                    mxst = st;
                }
            }
        }
        cout << max(mxsum2 + (kk * min(mxsz, i)), 0) << ' ';
    }
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
