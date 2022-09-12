
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
#define __test1





// g


void fun1(int sz1, int sz2, myvi& vi, int stx, int sty, int enx, int eny, int stp)
{
    if (abs(stx - enx) % stp != 0 || abs(sty - eny) % stp != 0)
    {
        cout << "NO" << endl;
        return;
    }


}


void fun1_e(int sz1, int sz2, myvi& vi, int stx, int sty, int enx, int eny, int stp)
{
    if (abs(stx - enx) % stp != 0 || abs(sty - eny) % stp != 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (sty == eny)
    {
        if (vi[sty] <= min(stx, enx))
        {
            cout << "YES" << endl;
        }
        else if (sty > 1 && vi[sty - 1] < min(stx, enx))
        {
            cout << "YES" << endl;
        }
        else if (sty + 1 < vi.size() && vi[sty + 1] < min(stx, enx))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return;
    }
    int x = stx;
    for (int y = sty + 1; y < eny; ++y)
    {

    }

}


// error
void fun1_e(int sz1, int sz2, myvi& vi, int stx, int sty, int enx, int eny, int stp)
{
    if (abs(stx - enx) % stp != 0 || abs(sty - eny) % stp != 0)
    {
        cout << "NO" << endl;
        return;
    }
    int mx = (sz1 - stx) / stp * stp + stx;

    if (stx == sty)
    {
        int mx2 = stx;
        for (int i = sty - 1; i < eny; ++i)
        {
            //.
        }
    }

#ifdef __test
    cout << "          " << mx << endl;
#endif
    for (int i = sty - 1; i < eny; ++i)
    {
        if (vi[i] >= mx)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


//// .....
//// start from 1.
////void fun1(int sz1, int sz2, myvi& vi, int stx, int sty, int enx, int eny, int stp)
//void fun1(int sz1, int sz2, int mxxx, int stx, int sty, int enx, int eny, int stp)
//{
//    if (abs(stx - enx) % stp != 0 || abs(enx - eny) % stp != 0)
//    {
//        cout << "NO" << endl;
//        return;
//    }
//    int mx = (sz1 - stx) / stp * stp + stx;
//
//#ifdef __test
//    cout << mx << " <> " << mxxx << endl;
//#endif
//
//    if (mx >= mxxx)
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
//}

int main()
{
    int n, m;
    cin >> n >> m;

    int mxxx = -1;
    int t2 = 0;
    vector<int> vi(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> vi[i];
        //cin >> t2;
        //if (t2 > mxxx)
        //    mxxx = t2;
    }


    int w = 0;
    cin>>w;
    
    
    
    for (int e = w; e < w; ++e)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {
        int a, b, c, d, f;
        cin >> a >> b >> c >> d >> f;
        
        fun1(n, m, vi, a, b, c, d, f);
        
        //cout<<endl;
    }
    
    
    return 0;
}
