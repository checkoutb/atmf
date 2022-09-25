
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

//while (tt--) {
//    int n;
//    cin >> n;
//    string s, t;
//    cin >> s >> t;
//    vector<int> ns(1, 0);
//    vector<int> nt(1, 0);
//    string cs, ct;
//    for (int i = 0; i < n; i++) {
//        if (s[i] != 'b') {
//            cs += s[i];
//            ns.push_back(0);
//        }
//        else {
//            ns.back() += 1;
//        }
//        if (t[i] != 'b') {
//            ct += t[i];
//            nt.push_back(0);
//        }
//        else {
//            nt.back() += 1;
//        }
//    }
//    int sum = 0;
//    bool ok = true;
//    if (cs == ct) {
//        for (int i = 0; i < (int)ns.size() - 1; i++) {
//            sum += ns[i] - nt[i];
//            if (sum > 0 && cs[i] == 'a') {
//                ok = false;
//                break;
//            }
//            if (sum < 0 && cs[i] == 'c') {
//                ok = false;
//                break;
//            }
//        }
//    }
//    cout << (ok && cs == ct ? "YES" : "NO") << '\n';
//}







// 172952119 	Sep/21/2022 21:12UTC+8 	Ouha 	1697C - awoo's Favorite Problem 	GNU C++17 	Accepted 	78 ms 	400 KB

// ab - ba
// bc - cb
// b往 a的前面， c 的后面走。
// a c 往中间聚集。  s[a] >= t[a]   s[c] <= t[c]
void fun1()
{
    int sz1;
    cin >> sz1;
    string s, t;
    cin >> s >> t;
    
    int i = 0;
    int idx = 0;
    for (; i < sz1; ++i)
    {
        if (s[i] != t[i])
        {
            if (i >= idx)
            {
                idx = i;
            }
            if (t[i] == 'b' && s[i] == 'a')
            {
                while (idx < sz1 && s[idx] == 'a')
                {
                    ++idx;
                }
                if (idx == sz1)
                {
                    cout << "NO" << endl;
                    return;
                }
                if (s[idx] == 'b')
                {
                    s[idx] = 'a';
                    ++idx;
                    s[i] = 'b';
                }
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            else if (t[i] == 'c' && s[i] == 'b')
            {
                while (idx < sz1 && s[idx] == 'b')
                {
                    ++idx;
                }
                if (idx == sz1 || s[idx] != 'c')
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    s[idx] = 'b';
                    ++idx;
                    s[i] = 'c';
                }
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    cout << "YES" << endl;
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
