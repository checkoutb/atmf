
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


// D D

// �л�����Ȼ���� kk
// �޻�������sort������ dp[v] - ��v��ʼ���path��
//       




// tle

// ���� emoji �� unicode�� ���ֶ�ɾ�� ���� �����ύ��

// 1����ͼ  oriented graph   dirtected graph
// some�� һЩ��������ĳ����
// 1û�� loop �� �ظ��ߡ�
//
// binary search�� ����xx�ĵ��Ҳ���ȥ��
// dfs��child��С������ Ȼ�󱣴�һ�� stack/vector ����¼ ���ֵ ���С�������
//   1ÿ��node��¼�� ��Сֵ�ͳ��ȡ� ��Сֵ���С� �� �������nodeʱ ��Сansֵ
//
// 1����˵ ������ loop ô���� example 1 ������loop �ġ���
//      It's guaranteed that graph doesn't contain loops and multi-edges.
//  ������loop �� �Ի�������
int mxdeptha1(myvi& vi, myvvi& vvi, vector<bool>& vst, int node, int depth, int lmt, int kk);

void fun1()
{
    ll sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2 >> kk;
    int r = 0;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
        r = max(vi[i], r);
    }

    //vector<pair<int, int>> vp(sz2);
    vector<vector<int>> vvi(sz1);
    int st, en;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> st >> en;
        --st, --en;
        vvi[st].push_back(en);
    }

    //if (kk > sz1)
    //{
    //    cout << -1 << endl;
    //    return;
    //}
    
    int l = 1;
    ++r;
    int ans = -1;
    while (l <= r)
    {
        int md = (l + r) / 2;

        //vector<bool> vst(sz1);
        int mxdep = 0;
        for (int i = 0; i < sz1 && mxdep < kk; ++i)
        {
            if (vi[i] <= md)
            {
                vector<bool> vst(sz1);
                int t2 = mxdeptha1(vi, vvi, vst, i, 1, md, kk);
                if (t2 > mxdep)
                    mxdep = t2;
            }
        }
        if (mxdep >= kk)
        {
            ans = md;
            r = md - 1;
        }
        else
        {
            l = md + 1;
        }

    }

    cout << ans << endl;
    
}

// no circle, so there is an end.
// 2��ѡ�� �����������ȣ�  ��ȴ���kk�ͷ��ء���  ���ܻ��á���
int mxdeptha1(myvi& vi, myvvi& vvi, vector<bool>& vst, int node, int depth, int lmt, int kk)
{
    if (vvi[node].empty())
    {
        return depth;
    }
    if (vst[node])
    {
        //return depth;
        return INT_MAX;     // ��loop ���ȱ�Ȼ���� kk��
    }
    vst[node] = true;
    //if (depth >= kk)
    //    return depth;

    int ans = depth;
    for (int chd : vvi[node])
    {
        if (vi[chd] <= lmt)
        {
            ans = max(ans, mxdeptha1(vi, vvi, vst, chd, depth + 1, lmt, kk));
        }
    }
    return ans;
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
