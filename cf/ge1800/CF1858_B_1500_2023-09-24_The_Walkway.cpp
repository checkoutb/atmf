
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








// g

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> sz2 >> kk;        // n m d .. nmd?
    
    vector<int> nums(sz2);
    for (int i = 0; i < sz2; ++i)
    {
        cin>>nums[i];
    }
    bool rm0 = false;
    if (nums[0] == 1)
    {
        rm0 = true;
        nums.erase(nums.begin());
        --sz2;
    }
    if (sz2 == 1)
    {
        cout<<((sz1 - 1) / kk + 1)<<' '<<1<<endl;
        return;
    }

    int cnt = 1;
    int lst = 1;
    int t2 = 0;
    cnt = sz2 + 1;
    for (int i = 0; i < sz2; ++i)
    {
        #ifdef __test
        cout<<"     "<<cnt<<endl;
        #endif
        t2 = nums[i] - lst;
        cnt += (t2 - 1) / kk;
        // cnt += (t2 % kk) != 0;
        // cnt -= (t2 % k) == 0;        // t2 - 1
        lst = nums[i];
    }
    t2 = sz1 - nums[sz2 - 1];
    if (t2 > 1)
        cnt += (t2 - 0) / kk;
    // cnt += (t2 % kk) != 0;

    #ifdef __test
    cout<<"    "<<cnt<<""<<endl;
    #endif

    int mn = cnt;
    int mncnt = 0;
    int t3 = 0;     // after remove
    lst = 1;
    for (int i = 0; i < sz2 - 1; ++i)
    {
        // remove [i]
        t2 = (nums[i] - lst - 1) / kk;
        // t2 += ((nums[i] - lst) % kk) != 0;
        
        t3 = (nums[i + 1] - lst - 1) / kk;
        // t3 += ((nums[i + 1] - lst) % kk) != 0;

        lst = nums[i];

        t2 += (nums[i + 1] - lst - 1) / kk;
        // t2 += ((nums[i + 1] - lst) % kk) != 0;

        t2 = cnt - (t2 + 1 - t3);       // total count

        if (t2 < mn)
        {
            mn = t2;
            mncnt = 1;
        }
        else if (t2 == mn)
            ++mncnt;
        
        #ifdef __test
        cout<<mn<<" - "<<mncnt<<" - "<<nums[i]<<endl;
        #endif
    }

    t3 = (sz1 - nums[sz2 - 2]) / kk;
    // t3 += (((sz1 - nums[sz2 - 2]) % kk) != 0) && t3 > 0;

    t2 = (nums[sz2 - 1] - nums[sz2 - 2] - 1) / kk;
    // t2 += ((nums[sz2 - 1] - nums[sz2 - 2]) % kk) != 0;
    t2 += (sz1 - nums[sz2 - 1]) / kk;
    // t2 += ((sz1 - nums[sz2 - 1]) % kk) != 0;

    t2 = cnt - (t2 + 1 - t3);

    if (t2 < mn)
    {
        mn = t2;
        mncnt = 1;
    }
    else if (t2 == mn)
        ++mncnt;

            
    #ifdef __test
    cout<<mn<<" - "<<mncnt<<" - "<<nums[sz2 - 1]<<endl;
    #endif

    if (mn == cnt && rm0)
    {
        ++mncnt;
    }

    cout<<mn<<' '<<mncnt<<endl;
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
