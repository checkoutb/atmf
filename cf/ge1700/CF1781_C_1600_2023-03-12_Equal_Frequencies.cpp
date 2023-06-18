
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







// 197024248 	Mar/12/2023 15:19UTC+8 	Ouha 	1781C - Equal Frequencies 	GNU C++17 	Accepted 	109 ms 	300 KB
// 5389

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    string s;
    cin >> s;
    
    int arr[123] = { 0 };
    
    for (char ch : s)
        ++arr[ch];
    
    //vector<int> vi;
    //for (int i = 'a'; i <= 'z'; ++i)
    //    if (arr[i] > 0)
    //        vi.push_back(arr[i]);

    //map<int, vector<char>> map2;
    //for (char ch = 'a'; ch <= 'z'; ++ch)
    //    if (arr[ch] > 0)
    //        map2[arr[ch]].push_back(ch);

    vector<pair<int, char>> vp;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        if (arr[ch] > 0)
            vp.push_back(std::make_pair(arr[ch], ch));

    std::sort(rbegin(vp), rend(vp));

    int mnchg = sz1;
    int mncnt = -1;
    for (int i = 1; i <= 26; ++i)
    {
        if (sz1 % i == 0)
        {
            int tar = sz1 / i;
            int chg = 0;
            for (int j = 0; j < i && j < vp.size(); ++j)
            {
                chg += min(tar, vp[j].first);

                //if (vp[j].first > tar)
                //    chg += vp[j].first - tar;
                //else
                //    break;
            }
            chg = sz1 - chg;

            if (chg < mnchg)
            {
                mnchg = chg;
                mncnt = i;
            }
        }
    }
    
#ifdef __test
    //cout << mnchg << " - " << mncnt << endl;
#endif

    int tar = sz1 / mncnt;

    vector<int> v2(123, 0);     // too many
    vector<int> v3(123, 0);     // need

    int t2 = 0;

    for (int i = 0; i < vp.size() && i < mncnt; ++i)
    {
        if (vp[i].first > tar)
        {
            v2[vp[i].second] = vp[i].first - tar;     // duoyu de
        }
        else
        {
            v3[vp[i].second] = tar - vp[i].first;     // queshao
        }
        t2 |= (1 << (vp[i].second - 'a'));
    }

    if (vp.size() < mncnt)
    {
        int t3 = mncnt - vp.size();
        for (int i = 0; i < 26 && t3 > 0; ++i)
        {
            if ((t2 & (1 << i)) == 0)
            {
                v3['a' + i] = tar;
                --t3;
            }
        }
    }
    else if (vp.size() > mncnt)
    {
        for (int i = mncnt; i < vp.size(); ++i)
        {
            v2[vp[i].second] = vp[i].first;
        }
    }

    int dyi = 'a';  // duo yu
    int qsi = 'a';  // que shao

    for (int i = 0; i < sz1; ++i)
    {
        if (v2[s[i]] > 0)
        {
            while (v3[qsi] == 0)
                ++qsi;

            --v2[s[i]];
            --v3[qsi];

            s[i] = char(qsi);
        }
        else if (v3[s[i]] > 0)
        {
            //while (v2[dyi] == 0)
            //    ++dyi;
            //--v2[dyi];
            //--v3[s[i]];

            //s[i] = char(dyi);
        }
    }
    cout << mnchg << endl << s << endl;
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
