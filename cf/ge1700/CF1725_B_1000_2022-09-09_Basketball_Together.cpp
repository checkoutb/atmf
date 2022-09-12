
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
//#include <unordered_map>
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

// D

//for (int i = n - 1; i >= 0; --i) {
//    long long c = (d + p[i]) / p[i];
//    cnt += c - 1;
//    if (cnt <= i) {
//        ans = max(ans, n - i);
//    }
//}





// 171508105 	Sep/09/2022 21:42UTC+8 	Ouha 	1725B - Basketball Together 	GNU C++17 	Accepted 	202 ms 	400 KB 
void fun1(myvi& vi, int pow)
{
    sort(begin(vi), end(vi));

    int st = 0;
    int en = vi.size() - 1;
    int ans = 0;

    while (st <= en)
    {
        int t2 = vi[en];
        int t3 = (pow + t2) / t2;       // number of person   .. strict greater
        if (t3 == 1)
            --en;
        else if (st + t3 - 2 < en)
        {
            st += t3 - 1;
            --en;
        }
        else
        {
            break;
        }
        ++ans;
    }
    cout << ans << endl;
}

int main()
{
    int w = 0;
    //cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    //for (int _ = 0; _ < w; ++_)
    {
        int sz1, pow;
        cin >> sz1 >> pow;
        
        myvi vi(sz1);
        for (int i = 0; i < sz1; ++i)
            cin >> vi[i];

        fun1(vi, pow);
        
        //cout<<endl;
    }
    
    
    return 0;
}
