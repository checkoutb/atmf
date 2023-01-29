
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





// ����һ��x����x-1������a-b-a-b,  mx ���Լ��� 2*(x-1), sum���Լ��� 3*(x-1)�� ��Ϊ1���� a-b-a-b,���� ��������������a��
// ��ʣһ������Ҫ���� (mx - 2*(x-1)) * 2 - 1 <= sum - (x-1)*3 ,�� x >= 2mx - sum
//          ���� mx - notmx - mx - notmx - mx - notmx, �������� mx��
// ʵ���Ϸ������룺һ��ʼ mx - notmx - mx - notmx�� ����mx���Ƕ��ˣ���ô��ʱ ����Ҫ ����� �� ������ mx������������ļ��衣


// 188037191 	Jan/05/2023 21:19UTC+8 	Ouha 	1649B - Game of Ball Passing 	GNU C++17 	Accepted 	280 ms 	400 KB

// x
// 1: 
// x-1: 2*(x-1)
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    long long sum2 = 0LL;
    //long long mx = 0LL;
    int mx = 0;

    for (int i = 0; i < sz1; ++i)
    {
        sum2 += vi[i];
        mx = max(mx, vi[i]);
    }
    
    if (sum2 == 0)
    {
        cout << 0 << endl;
        return;
    }

    long long ans = 2LL * mx - sum2;
    ans = max(1LL, ans);
    
    cout << ans << endl;
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
