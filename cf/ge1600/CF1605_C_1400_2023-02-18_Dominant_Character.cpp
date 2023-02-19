
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

// + 1 then 2 then 3 then 6

//cin >> n >> a;
//if (~a.find("aa"))return 2;
//if (~a.find("aba") || ~a.find("aca"))return 3;
//if (~a.find("abca") || ~a.find("acba"))return 4;
//if (~a.find("abbacca") || ~a.find("accabba"))return 7;
//return -1;



// 194077639 	Feb/18/2023 14:37UTC+8 	Ouha 	1605C - Dominant Character 	GNU C++17 	Accepted 	561 ms 	2900 KB
// 13633

void fun1()
{
    int sz1;
    string s;
    cin >> sz1;
    cin >> s;

    int ans = sz1 + 2;
    int mx = 7;
    int cnta, cntb, cntc;
    for (int i = 0; i < sz1 && ans != 2; ++i)
    {
        if (s[i] != 'a')
            continue;

        cnta = 1;
        cntb = cntc = 0;
        for (int j = i + 1; j < i + mx && j < sz1; ++j)
        {
            switch (s[j])
            {
            case 'a':
                ++cnta;
                break;
            case 'b':
                ++cntb;
                break;
            default:
                ++cntc;
            }
            if (cnta > cntb && cnta > cntc)
            {
                ans = j - i + 1;
                mx = ans;
            }
        }
    }

    cout << (ans > sz1 ? -1 : ans) << endl;
}


// error  ..   abbacca
void fun1_err()
{
    int sz1, sz2, kk;
    cin >> sz1;
    string s;
    cin >> s;

    int ans = sz1 << 1;
    for (int i = 0; i < sz1; ++i)
    {
        if (s[i] == 'a')
        {
            if (i + 1 < sz1 && s[i + 1] == 'a')
            {
                ans = 2;
                break;
            }
            if (i + 2 < sz1 && s[i + 2] == 'a')
            {
                ans = 3;
            }
            else if (i + 3 < sz1 && s[i + 3] == 'a')            // abca
            {
                if (s[i + 1] != s[i + 2])
                {
                    ans = min(ans, 4);
                }
            }
        }
    }
    
    cout << (ans > sz1 ? -1 : ans) << endl;
}


int main()
{
    string s;
    cin >> s;
    cout << ~s.find("aa") << endl;
    cout << s.find("aa") << endl;
    cout << ~s.find("notexist") << endl;
    cout << s.find("notexist") << endl;
    cout << ~1 << endl;
    cout << ~- 1 << endl;

    int w = 1;
    cin>>w;
    
    
    
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
