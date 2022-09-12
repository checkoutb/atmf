
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
#define __test2







// g



//void fun1(myvi& v1, myvvi& qry)
//{
//
//}



void fun1(myvi& v1, myvvi& qry)
{
#ifdef __testgggg
    cout << "     11  " << v1.size() << " ??  " << qry.size() << endl;
#endif
    int sz1 = v1.size(), sz2 = qry.size();


    long long ans = 1LL;
    int cnt = 1;
    long long tmp = 1LL;

    for (int i = 1; i < sz1; ++i)
    {
        if (v1[i] != v1[i - 1])
        {
            tmp = 1 + tmp + i;
        }
        else
        {
            tmp = 1 + tmp;
        }
        ans += tmp;
#ifdef __test
        cout << "        " << i << " " << ans << " -- " << tmp << endl;
#endif
    }


//    for (int i = 1; i < sz1; ++i)
//    {
//        if (v1[i] != v1[i - 1])
//        {
//            ++cnt;
//        }
//        ans += cnt;
//        tmp += ans;
//
//#ifdef __test
//        cout << "      " << i << ": " << ans << " - " << cnt << " ... " << tmp << endl;
//
//#endif
//
//    }
//    ans = tmp;


    for (int i = 0; i < sz2; ++i)
    {
        int idx = qry[i][0];
        int nv = qry[i][1];
#ifdef __test555
        cout << "          " << idx << " ----- " << nv << endl;
#endif
        int a = idx == 0 ? -1 : v1[idx - 1];
        int b = v1[idx];
        int c = idx == sz1 - 1 ? -1 : v1[idx + 1];

        int cnt1 = 1 + ((a == -1 ? b : a) != b) + (b != (c == -1 ? b : c));
        int cnt2 = 1 + ((a == -1 ? nv : a) != nv) + (nv != (c == -1 ? nv : c));

        v1[idx] = nv;

        if (cnt1 == cnt2)
        {
            cout << ans << endl;
        }
        else if (cnt1 > cnt2)
        {
            if (cnt1 - cnt2 == 1)
            {
                if (idx == 0 || idx == sz1 - 1)
                {
                    cout << ans - (sz1 - 1) << endl;
                    ans -= (sz1 - 1);
                }
                else
                {
                    if (a == nv)
                    {
                        long long t2 = 1LL * (idx) * (sz1 - idx);
                        cout << ans - t2 << endl;
                        ans -= t2;
                    }
                    else
                    {
                        long long t2 = 1LL * (idx + 1) * (sz1 - idx - 1);
                        cout << ans - t2 << endl;

                        ans -= t2;
                    }
                }
            }
            else    // 2
            {
                ans -= (sz1 - 1) + (1LL * idx * (sz1 - 1 - idx) * 2);
                cout << ans << endl;
                //cout << ans - ((idx + 1) * (sz1 - idx) - 1) << endl;
                //ans -= ((idx + 1) * (sz1 - idx) - 1);
            }
        }
        else
        {
            if (cnt2 - cnt1 == 1)
            {
                if (idx == 0 || idx == sz1 - 1)
                {
                    cout << ans + (sz1 - 1) << endl;
                    ans += sz1 - 1;
                }
                else
                {
                    if (a == b)
                    {
                        long long t2 = 1LL * (idx - 1 + 1) * (sz1 - idx);
                        cout << ans + t2 << endl;
                        ans += t2;
                    }
                    else
                    {
                        long long t2 = 1LL * (idx + 1) * (sz1 - idx - 1);
                        cout << ans + t2 << endl;
                        ans += t2;
                    }
                }
            }
            else    // 2
            {
                ans += (sz1 - 1) + (1LL * idx * (sz1 - 1 - idx) * 2);
                cout << ans << endl;
                //cout << ans + ((idx + 1) * (sz1 - idx) - 1) << endl;
                //ans += ((idx + 1) * (sz1 - idx) - 1);
            }
        }

        //if ((nv == v1[idx]))
        //{
        //    cout << ans << endl;
        //}
        //else if (idx != 0 && v1[idx] == v1[idx - 1])
        //{
        //    if (idx < sz1 - 1 && nv == v1[idx + 1])
        //    {
        //        cout << ans << endl;
        //    }
        //    else
        //    {

        //    }
        //}
    }

}

int main()
{
    int w = 0;
    //cin>>w;           // ....
    
    
    
    for (int e = w; e < w; ++e)
    {
        
    }
    
    //for (int e = 0; e < w; ++e)
    {
        int sz1 = 0;
        int sz2 = 0;
        cin >> sz1;
        cin >> sz2;

        myvi v1(sz1);
        myvvi vv2(sz2, vector<int>(2));

        for (int i = 0; i < sz1; ++i)
            cin >> v1[i];

        for (int i = 0; i < sz2; ++i)
        {
            cin >> vv2[i][0] >> vv2[i][1];
            --vv2[i][0];
        }
        
#ifdef __testertert
        cout << sz1 << " --- " << sz2 << endl;
        for (int i : v1)
            cout << i << " , ";
        cout << endl;
        for (myvi& v : vv2)
        {
            cout << v[0] << " + " << v[1] << endl;
        }
#endif


        fun1(v1, vv2);
        
        //cout<<endl;
    }
    
    
    return 0;
}
