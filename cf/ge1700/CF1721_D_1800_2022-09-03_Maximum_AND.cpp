
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
#include <unordered_map>
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

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>

#define __test


// g
// 27,30,0    0,5,9
// 中间会将 30和0 分组，导致 bit1 为 false。。


// vb: can
void fun1(myvi& v1, myvi& v2, int st, int en, vector<bool>& vb, int pw)
{
#ifdef __test
    cout << "        --   " << st << ", " << en << ", " << pw << endl;
    for (int i = st; i <= en; ++i)
    {
        cout << "              " << v1[i] << ", " << v2[i] << endl;
    }
#endif

    if (st > en || pw <= 0)
        return;

    int t2 = 0;
    int cnt1 = 0;
    while (pw > 0)
    {
        pw--;
        if (vb[pw] == false)
            continue;

#ifdef __test
        cout << " st " << pw << endl;
#endif

        cnt1 = 0;
        t2 = 1 << pw;
        int cnt2 = 0;
        for (int i = st; i <= en; ++i)
        {
            cnt1 += (t2 & v1[i]) != 0;          // 0,0   1,1   1,0
            cnt2 += (t2 & v2[i]) != 0;
            //if ((t2 & v1[i]) == (t2 & v2[i])) /// ....
            //    goto AAA;

        }

        //break;

        //AAA:
        //vb[pw] = false;

        if (cnt1 + cnt2 == (en - st + 1))
        {
#ifdef __test
            cout << t2 << " - " << pw << ", " << endl;
#endif
            break;
        }
        else
        {
            vb[pw] = false;
        }

    }
    if (pw <= 0)
        return;

    
    sort(begin(v1) + st, begin(v1) + en + 1, [&](int& a, int& b) { return (a & t2) > (b & t2); });      // 按照cnt1 截断，所以必须 >
    sort(begin(v2) + st, begin(v2) + en + 1, [&](int& a, int& b) { return (a & t2) < (b & t2); });

    fun1(v1, v2, st, st + cnt1 - 1, vb, pw);
    fun1(v1, v2, st + cnt1, en, vb, pw);

}


//// half
//void fun1(myvi& v1, myvi& v2)
//{
//    int ans = 0;
//    int pw = 31;
//    int sz1 = v1.size();
//    while (pw-- > 0)
//    {
//        int t2 = 1 << pw;
//        int cnt1 = 0;
//        int cnt2 = 0;
//        for (int i = 0; i < sz1; ++i)
//        {
//            cnt1 += (t2 & v1[i]) != 0;
//            cnt2 += (t2 & v2[i]) != 0;
//        }
//        if (cnt1 + cnt2 == sz1)
//            break;
//        for (int i = 0; i < sz1; ++i)
//        {
//            v1[i] &= (t2 - 1);
//            v2[i] &= (t2 - 1);
//        }
//    }
//
//    
//
//
//}
//
//// [st, en]
//int dfsa1(myvi& v1, myvi& v2, int st, int en, vector<bool> vb)
//{
//
//
//}


int main()
{
    int w = 0;
    cin>>w;
    
    
    
    for (int e = w; e < w; ++e)
    {
        
    }
    
    for (int e = 0; e < w; ++e)
    {
        int sz1 = 0;
        cin >> sz1;
        vector<int> v1(sz1);
        vector<int> v2(sz1);
        for (int i = 0; i < sz1; ++i)
            cin >> v1[i];
        for (int i = 0; i < sz1; ++i)
            cin >> v2[i];

        vector<bool> vb(31, true);

        fun1(v1, v2, 0, sz1 - 1, vb, 31);
        int ans = 0;
        for (int i = 0; i < vb.size(); ++i)
        {
            if (vb[i])
                ans |= (1 << i);
        }
        cout << ans;
        cout<<endl;
    }
    
    
    return 0;
}
