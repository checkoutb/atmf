
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










// 203017546 	Apr / 22 / 2023 15:15UTC + 8 	Ouha 	1799C - Double Lexicographically Minimum 	GNU C++17 	Accepted 	326 ms 	300 KB
// 4101


// bbcca
// bab
// bbab
void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;

    string s;
    cin >> s;
    
    int sz1 = s.size();

    int arr[123] = { 0 };
    for (int i = 0; i < sz1; ++i)
    {
        ++arr[s[i]];
    }

    vector<pair<char, int>> vp;
    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (arr[i] != 0)
        {
            vp.push_back(std::make_pair((char)i, arr[i]));
        }
    }
    
    string ans(sz1, '-');
    int st = 0, en = sz1 - 1;
    char ch = 'a';
    int cnt = 0;
    for (int i = 0; i < vp.size(); ++i)
    {
        ch = vp[i].first;
        cnt = vp[i].second;

        if (cnt % 2 == 1)
        {
            for (int j = cnt / 2; j > 0; --j)
            {
                ans[st++] = ch;
                ans[en--] = ch;
            }

            if (i < vp.size() - 2)          // abbcc
            {
                ans[en--] = ch;
                for (int j = i + 1; j < vp.size(); ++j)
                {
                    ch = vp[j].first;
                    cnt = vp[j].second;
                    while (cnt-- > 0)
                    {
                        ans[st++] = ch;
                    }
                }
            }
            else if (i == vp.size() - 1)
            {   
                            // a
                ans[st++] = ch;
            }
            else
            {
                        // abb   abbb
                char ch2 = vp[i + 1].first;
                while (st < en)
                {
                    ans[st++] = ch2;
                    if (st < en)
                        ans[en--] = ch2;
                }
                ans[st++] = ch;
            }

            break;
        }
        else
        {
            for (int j = cnt / 2; j > 0; --j)
            {
                ans[st++] = ch;
                ans[en--] = ch;
            }
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
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
