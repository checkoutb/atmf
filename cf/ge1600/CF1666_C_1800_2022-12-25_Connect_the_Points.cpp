
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

// D D

//struct node
//{
//    int x, y;
//    bool operator < (const node& k) const
//    {
//        return x < k.x;
//    }
//} a[10];
//void solve()
//{
//    int mi = 1e18, ma = -1e18;
//    for (int i = 1; i <= 3; i++) {
//        cin >> a[i].x >> a[i].y;
//        mi = min(mi, a[i].y);
//        ma = max(ma, a[i].y);
//    }
//    sort(a + 1, a + 1 + 3);
//    cout << 3 << "\n";
//    printf("%lld %lld %lld %lld\n", a[2].x, mi, a[2].x, ma);
//    printf("%lld %lld %lld %lld\n", a[1].x, a[1].y, a[2].x, a[1].y);
//    printf("%lld %lld %lld %lld\n", a[3].x, a[3].y, a[2].x, a[3].y);
//}







//186633264 	Dec / 25 / 2022 13:43UTC + 8 	Ouha 	1666C - Connect the Points 	GNU C++17 	Accepted 	15 ms 	0 KB
void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;
    
    vector<vector<int>> vvi(3, vector<int>(2));
    cin >> vvi[0][0] >> vvi[0][1] >> vvi[1][0] >> vvi[1][1] >> vvi[2][0] >> vvi[2][1];
    
    sort(begin(vvi), end(vvi));

    vector<vector<int>> ans;

    ans.push_back({ vvi[0][0], vvi[0][1], vvi[1][0], vvi[0][1] });
    ans.push_back({ vvi[1][0], vvi[0][1], vvi[1][0], vvi[1][1] });
    
    int mxy = max(vvi[0][1], vvi[1][1]);
    int mny = min(vvi[0][1], vvi[1][1]);

    if (vvi[2][1] > mxy)
    {
        ans.push_back({ vvi[1][0], mxy, vvi[2][0], mxy });
        ans.push_back({ vvi[2][0], mxy, vvi[2][0], vvi[2][1] });
    }
    else if (vvi[2][1] < mny)
    {
        ans.push_back({ vvi[1][0], mny, vvi[2][0], mny });
        ans.push_back({ vvi[2][0], mny, vvi[2][0], vvi[2][1] });
    }
    else
    {
        ans.push_back({ vvi[1][0], vvi[2][1], vvi[2][0], vvi[2][1] });
    }

    vector<vector<int>> ans2;
    for (vector<int>& vi : ans)
    {
        if (vi[0] != vi[2] || vi[1] != vi[3])
            ans2.push_back(vi);
    }

    cout << ans2.size() << endl;
    for (vector<int>& vi : ans2)
    {
        cout << vi[0] << ' ' << vi[1] << ' ' << vi[2] << ' ' << vi[3] << endl;
    }
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
