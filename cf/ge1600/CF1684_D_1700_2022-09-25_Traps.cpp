
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

// ��Ȼ�� k ��ȫ�����ꡣ
// ��һ��skip ��ʹ�� ���� n-i ���˺��� ������ȫ������ģ� ���� ������� k-1 ���˺���
// �ڶ��� skip  �� ���� n-idx ���˺��� ������ȫ�����꣬ ���� ������� k-2 ���˺���
// k ������ģ� ���� ��� һ�� skip  ����� 0 ���˺���
//  ����ɵ� �˺� ʼ���� k(k-1)/2��
// ���� n-idx ���� ̰����




// 6 5    4 1 100 100 1 1
//error
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> kk;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    vector<pair<int, int>> vp(sz1);

    for (int i = 0; i < sz1; ++i)
    {
        vp[i].first = vi[i] - (sz1 - 1 - i);
        vp[i].second = i;
    }
    
    sort(begin(vp), end(vp));
    int cnt = 0;
    for (int i = sz1 - 1; i >= 0 && cnt < kk; --i)
    {
        if (vp[i].first <= 0)
        {
            break;
        }
        ++cnt;
        vi[vp[i].second] = -1;
    }

    int skp = 0;
    for (int i = sz1 - 1; i >= 0 && cnt < kk; --i)
    {
        if (vi[i] != -1)
        {

            vi[i] = -1;
            ++cnt;
        }
    }

    ll ans = 0LL;
    cnt = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (vi[i] == -1)
        {
            ++cnt;
            continue;
        }
        ans += cnt + vi[i];
    }
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
