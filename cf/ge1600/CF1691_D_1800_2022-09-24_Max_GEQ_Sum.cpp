
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
//#include <numeric>
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

// ��stack ��� ��һ���� [i] ��ģ�����x����һ�� �� [i] ��ģ�����y��
// ���� i �ķ�Χ ���� [x+1, y-1]
// so only checking subarrays which start or end at index i suffices.
// ������ ���ֳ�3�����֣� (x,i),[i,i],(i,y)�� ������� max(xxx) < sum(xxx)
// .. buzhidao le.



// wrong answer expected NO, found YES [2141st token]
// .. ������ ��������� �� �벻����




// divide and conquer
// max subarray sum   ..
// dp[idx][length]
void fun1()
{
    int sz1;
    cin >> sz1;

    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    ll mx = -1234567890LL;
    ll sum2 = 0LL;
    
    for (int i = 0; i < sz1; ++i)
    {
        sum2 += vi[i];
        mx = mx > vi[i] ? mx : vi[i];
        if (sum2 >= 0)
        {
            if (mx < sum2)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (mx < sum2)
            {
                cout << "NO" << endl;
                return;
            }

            sum2 = 0LL;
            mx = -1234567890LL;
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
