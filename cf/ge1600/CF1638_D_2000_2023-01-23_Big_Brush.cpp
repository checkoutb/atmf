
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

#include <tuple>

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
// queue， 反推


// 有耳朵的，而不是 直线。

// g



// error

bool can1(vector<vector<int>>& vvi, int col);
void fun1_reverse(vector<vector<int>>& vvi, int r, int c);
bool can2(vector<vector<int>>& vvi, int r);

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;

    vector<vector<int>> vvi(sz1, vector<int>(sz2));
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            cin >> vvi[i][j];
        }
    }
    
    int lst = -1;       // last brush's j
    int lsti = -1;
    bool isRow = false;
    for (int i = 1; i < sz1 && lst == -1; ++i)
    {
        for (int j = 1; j < sz2; ++j)
        {
            if (vvi[i][j] == vvi[i - 1][j - 1] && vvi[i][j] == vvi[i - 1][j] && vvi[i][j] == vvi[i][j - 1])
            {
                if (can1(vvi, j - 1))
                {
                    lst = j - 1;
                    lsti = i - 1;
                    break;
                }
                else if (can2(vvi, i - 1))
                {
                    lst = j - 1;
                    lsti = i - 1;
                    isRow = true;
                    break;
                }
            }
        }
    }
    
    if (isRow)
    {
        fun1_reverse(vvi, lsti, lst);
        return;
    }

    if (lst == -1)
    {
        cout << -1 << endl;
        return;
    }

    for (int j = 0; j < sz2; ++j)
    {
        for (int i = 1; i < sz1; ++i)
        {
            if (vvi[i][j] == vvi[i - 1][j])
                goto AAA;
        }
        cout << -1 << endl;
        return;

        AAA:
        continue;
    }

    vector<tuple<int, int, int>> vt;
    
    int samei = -1;
    // --->
    for (int j = 0; j < lst; ++j)
    {
        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (vvi[i][j] == vvi[i + 1][j])
            {
                samei = i;
                break;
            }
            vt.push_back(std::make_tuple(i, j, vvi[i][j]));
            //cout << i << ' ' << j << ' ' << vvi[i][j] << endl;
        }

        for (int i = sz1 - 1; i > samei; --i)
        {
            vt.push_back(std::make_tuple(i - 1, j, vvi[i][j]));
            //cout << i - 1 << ' ' << j << ' ' << vvi[i][j] << endl;
        }

    }

    // <---
    for (int j = sz2 - 1; j > lst + 1; --j)
    {
        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (vvi[i][j] == vvi[i + 1][j])
            {
                samei = i;
                break;
            }
            vt.push_back(std::make_tuple(i, j - 1, vvi[i][j]));
            //cout << i << ' ' << j - 1 << ' ' << vvi[i][j] << endl;
        }
        for (int i = sz1 - 1; i > samei; --i)
        {
            vt.push_back(std::make_tuple(i - 1, j - 1, vvi[i][j]));
            //cout << i - 1 << ' ' << j - 1 << ' ' << vvi[i][j] << endl;
        }
    }
    
    for (int i = 0; i < lsti; ++i)
    {
        if (vvi[i][lst] == vvi[i][lst + 1])
        {
            vt.push_back(std::make_tuple(i, lst, vvi[i][lst]));
        }
    }
    for (int i = sz1 - 1; i > lsti; --i)
    {
        if (vvi[i][lst] == vvi[i][lst + 1])
        {
            vt.push_back(std::make_tuple(i - 1, lst, vvi[i][lst]));
        }
    }

    cout << vt.size() << endl;
    for (std::tuple<int, int, int>& t : vt)
    {
        cout << std::get<0>(t) + 1 << ' ' << std::get<1>(t) + 1 << ' ' << std::get<2>(t) << endl;
    }

}

void fun1_reverse(vector<vector<int>>& vvi, int r, int c)
{
    int sz1 = vvi.size();
    int sz2 = vvi[0].size();

    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 1; j < sz2; ++j)
        {
            if (vvi[i][j] == vvi[i][j - 1])
                goto AAA;
        }
        cout << -1 << endl;
        return;

        AAA:
        continue;
    }

    vector<tuple<int, int, int>> vt;
    int samej = -1;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < sz2 - 1; ++j)
        {
            if (vvi[i][j] == vvi[i][j + 1])
            {
                samej = j;
                break;
            }
            vt.push_back(std::make_tuple(i, j, vvi[i][j]));
        }
        for (int j = sz2 - 1; j > samej; --j)
        {
            vt.push_back(std::make_tuple(i, j - 1, vvi[i][j]));
        }
    }

    for (int i = sz1 - 1; i > r + 1; --i)
    {
        for (int j = 0; j < sz2 - 1; ++j)
        {
            if (vvi[i][j] == vvi[i][j + 1])
            {
                samej = j;
                break;
            }
            vt.push_back(make_tuple(i - 1, j, vvi[i][j]));
        }
        for (int j = sz2 - 1; j > samej; --j)
        {
            vt.push_back(make_tuple(i - 1, j - 1, vvi[i][j]));
        }
    }

    for (int j = 0; j < c; ++j)
    {
        if (vvi[r][j] == vvi[r + 1][j])
        {
            vt.push_back(make_tuple(r, j, vvi[r][j]));
        }
    }
    for (int j = sz2 - 1; j > c; --j)
    {
        if (vvi[r][j] == vvi[r + 1][j])
        {
            vt.push_back(std::make_tuple(r, j - 1, vvi[r][j]));
        }
    }

    cout << vt.size() << endl;
    for (std::tuple<int, int, int>& t : vt)
    {
        cout << std::get<0>(t) + 1 << ' ' << std::get<1>(t) + 1 << ' ' << std::get<2>(t) << endl;
    }
}

bool can2(vector<vector<int>>& vvi, int r)
{
    if (r == 0 || r == vvi.size() - 2)
    {
        for (int j = 0; j < vvi[0].size(); ++j)
        {
            if (vvi[r][j] != vvi[r][j + 1])
                return false;
        }
        return true;
    }
    for (int j = 0; j < vvi[0].size(); ++j)
    {
        if (vvi[r][j] == vvi[r + 1][j])
            continue;
        if (vvi[r][j] == vvi[r - 1][j] && vvi[r + 1][j] == vvi[r + 2][j])
            continue;
        return false;
    }
    return true;
}

bool can1(vector<vector<int>>& vvi, int col)
{
    if (col == 0 || col == vvi[0].size() - 2)
    {
        for (int i = 0; i < vvi.size(); ++i)
        {
            if (vvi[i][col] != vvi[i][col + 1])
                return false;
        }
        return true;
    }

    for (int i = 0; i < vvi.size(); ++i)
    {
        if (vvi[i][col] == vvi[i][col + 1])
            continue;

        if (vvi[i][col] == vvi[i][col - 1] && vvi[i][col + 1] == vvi[i][col + 2])
            continue;

        return false;
    }
    return true;
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
