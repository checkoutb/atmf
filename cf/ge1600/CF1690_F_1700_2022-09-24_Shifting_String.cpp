
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









// error
//
// 6
// ccbbbc
// 1 5 6 4 3 2

void fun1()
{
    int sz1;
    cin >> sz1;
    string s;
    cin >> s;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
        --vi[i];
    }
    
    myvi v2(sz1);
    int t2, cnt;
    for (int i = 0; i < sz1; ++i)
    {
        t2 = vi[i];
        cnt = 1;
        while (s[i] != s[t2])
        {
            ++cnt;
            t2 = vi[t2];
        }
        v2[i] = cnt;
    }

    bool arr[201] = { false };
    myvi prm;
    for (int i = 2; i <= sz1; ++i)
    {
        if (arr[i] == false)
        {
            prm.push_back(i);
            for (int j = i; j < 201; j += i)
            {
                arr[j] = true;
            }
        }
    }

    ll ans = 1LL;
    
    myvi cntvi(prm.size(), 0);

    for (int i = 0; i < sz1; ++i)
    {
        t2 = v2[i];

        for (int j = 0; j < prm.size() && t2 != 1; ++j)
        {
            cnt = 0;
            while (t2 % prm[j] == 0)
            {
                t2 /= prm[j];
                ++cnt;
            }
            cntvi[j] = max(cnt, cntvi[j]);
        }
    }

#ifdef __test
    for (int i : prm)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (int i : cntvi)
        cout << i << "- ";
    cout << endl;

    cout << "       ---------- " << endl;
    for (int i : v2)
    {
        cout << i << ", ";
    }
    cout << endl;
#endif

    for (int i = 0; i < prm.size(); ++i)
    {
        while (cntvi[i]-- > 0)
        {
            ans = ans * prm[i];
        }
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
