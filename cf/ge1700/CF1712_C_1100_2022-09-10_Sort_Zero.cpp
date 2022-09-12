
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
#include <string.h>

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>
#define __test1

// D

//int suf = n - 1;
//for (int i = n - 2; i >= 0; i--) {
//    if (a[i] <= a[i + 1]) {
//        suf = i;
//    }
//    else {
//        break;
//    }
//}
//int ans = 0;
//for (int i = 0, xd = -1; i < suf || i <= xd; i++) {
//    if (!chk[a[i]]) {
//        ans++;
//        chk[a[i]] = true;
//        xd = max(xd, lst[a[i]]);
//    }
//}


//for (int i = 1; i <= N; i++) {
//    f[i] = f[i - 1];
//    if (vi[a[i]] == 0) f[i]++;
//    vi[a[i]] = 1;
//    qq = std::max(qq, la[a[i]]);
//    if (qq <= i) v[i] = 1;
//}
//for (int i = N; i >= 0; i--) {
//    if (v[i]) ans = std::min(ans, f[i]);
//    if (a[i] > a[i + 1] && i < N) break;
//}




// 171601472 	Sep/10/2022 19:18UTC+8 	Ouha 	1712C - Sort Zero 	GNU C++17 	Accepted 	170 ms 	1500 KB

static bool arr[100005] = { false };
inline int get1(int i)
{
    return arr[i] ? 0 : i;
}
void fun1()
{
    int sz1;
    cin >> sz1;

    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    memset(arr, false, sizeof(arr));
    
    vector<int> stk;
    
    for (int i = 0; i < sz1; ++i)
    {
        int t2 = get1(vi[i]);
        while (!stk.empty() && (stk[stk.size() - 1]) > t2)
        {
            arr[stk[stk.size() - 1]] = true;
            stk.pop_back();
            t2 = 0;
        }
        stk.push_back(get1(vi[i]));

        //if (stk.empty())
        //{
        //    stk.push_back(vi[i]);
        //}
        //else
        //{
        //    int t2 = get1(stk[stk.size() - 1]);
        //    int t3 = get1(vi[i]);
        //}
    }
    int ans = 0;
    for (int i = 1; i <= sz1; ++i)
    {
        if (arr[i])
            ans++;
    }
    cout << ans << endl;
}


int main()
{
    int w = 0;
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
