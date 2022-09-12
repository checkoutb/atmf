
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
#include <queue>
//#include <unordered_set>
//#include <numeric>

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>
#define __test1






// g


vector<int> cnt1perDir(myvvi&& vvi, int i, int j);


// ÏóÏÞ1-4
void fun1(myvvi& vvi)
{
    int sz1 = vvi.size(), sz2 = vvi[0].size();

    std::priority_queue<pair<int, tuple<int, int, int>>> priq;

    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (vvi[i][j] == 1)
            {
                myvi vi2 = cnt1perDir(vvi, i, j);
                int mndir = 1;
                for (int a = 2; a <= 12; ++a)
                {
                    if (vi2[a] < vi2[mndir])
                    {
                        mndir = a;
                    }
                }
                priq.push(make_pair(-vi2[mndir], make_tuple(i, j, mndir)));
                //for (int a = 1; a <= 4; ++a)
                //{
                //    if (vi2[a] == vi2[mndir])
                //    {

                //    }
                //}
            }
        }
    }
    int ans = 0;
    while (!priq.empty())
    {
        pair<int, tuple<int, int, int>> tp = priq.top();
        priq.pop();
        int r = tp.second.get<0>();
        int c = tp.second.get<1>();
        int dir = tp.second.get<2>();
        if (vvi[r][c] == 0)
            continue;

        ans++;

        switch (dir)
        {
        case 1:
        case 5:
        case 6:

            break;
        case 2:
        case 7:
        case 8:

            break;
        case 3:
        case 9:
        case 10:

            break;
        case 4:
        case 11:
        case 12:

            break;
        }

        //switch (dir)
        //{
        //case 1:
        //    ans += 1 + vvi[r - 1][c] + vvi[r][c + 1];
        //    break;
        //case 2:
        //    ans += 1 + vvi[r - 1][c] + vvi[r][c - 1];
        //    break;
        //case 3:
        //    ans += 1 + vvi[r][c - 1] + vvi[r + 1][c];
        //    break;
        //case 4:
        //    ans += 1 + vvi[r][c + 1] + vvi[r + 1][c];
        //    break;
        //case 5:
        //    ans += 1 + vvi[r][c + 1] + vvi[r - 1][c + 1];
        //    break;
        //case 6:
        //    ans += 1 + vvi[r - 1][c] + vvi[r - 1][c + 1];
        //    break;
        //case 7:
        //    ans += 1 + vvi[r - 1][c] + vvi[r - 1][c - 1];
        //    break;
        //case 8:
        //    ans += 1 + vvi[r][c - 1] + vvi[r - 1][c - 1];
        //    break;
        //case 9:
        //    ans += 1 + vvi[r][c - 1] + vvi[r + 1][c - 1];
        //    break;
        //case 10:
        //    ans += 1 + vvi[r + 1][c] + vvi[r + 1][c - 1];
        //    break;
        //case 11:
        //    ans += 1 + vvi[][]
        //}

    }
}

vector<int> cnt1perDir(myvvi&& vvi, int i, int j)
{
    int sz1 = vvi.size(), sz2 = vvi[0].size();
    vector<int> ans(13, 123);
    if (i > 0 && j < sz2 - 1)
    {
        ans[5] = 1 + vvi[i - 1][j + 1] + vvi[i][j - 1];
        ans[6] = 1 + vvi[i - 1][j] + vvi[i - 1][j + 1];
        ans[1] = 1 + vvi[i - 1][j] + vvi[i][j + 1];
    }
    if (i > 0 && j > 0)
    {
        ans[7] = 1 + vvi[i - 1][j] + vvi[i - 1][j - 1];
        ans[8] = 1 + vvi[i][j - 1] + vvi[i - 1][j - 1];
        ans[2] = 1 + vvi[i - 1][j] + vvi[i][j - 1];
    }
    if (i < sz1 - 1 && j > 0)
    {
        ans[9] = 1 + vvi[i][j - 1] + vvi[i + 1][j - 1];
        ans[10] = 1 + vvi[i + 1][j - 1] + vvi[i + 1][j];
        ans[3] = 1 + vvi[i + 1][j] + vvi[i][j - 1];
    }
    if (i < sz1 - 1 && j < sz2 - 1)
    {
        ans[11] = 1 + vvi[i + 1][j + 1] + vvi[i][j + 1];
        ans[12] = 1 + vvi[i + 1][j + 1] + vvi[i + 1][j];
        ans[4] = 1 + vvi[i + 1][j] + vvi[i][j + 1];
    }

    return ans;
}


//void fun1(myvvi& vvi)
//{
//    int sz1 = vvi.size();
//    int sz2 = vvi[0].size();
//
//    int cnt1 = 0;
//    for (int i = 0; i < sz1; ++i)
//    {
//        for (int j = 0; j < sz2; ++j)
//            cnt1 += vvi[i][j];
//    }
//
//    while (cnt1 > 0)
//    {
//        bool chg = false;
//        for (int i = 0; i < sz1; ++i)
//        {
//            for (int j = 0; j < sz2; ++j)
//            {
//
//            }
//        }
//
//        if (!chg)
//        {
//
//        }
//    }
//
//}

//void fun1(myvvi& vvi)
//{
//    int sz1 = vvi.size();
//    int sz2 = vvi[0].size();
//
//    for (int j = 0; j < sz2; ++j)
//    {
//        if (vvi[0][j] == 1)
//        {
//
//        }
//    }
//
//    for (int i = 1; i < sz1; ++i)
//    {
//        if (vvi[i][0] == 1)
//        {
//
//        }
//    }
//
//}

int main()
{
    int w = 0;
    cin>>w;
    
    
    
    for (int e = w; e < w; ++e)
    {
        
    }
    
    for (int e = 0; e < w; ++e)
    {
        int sz1 = 0;
        int sz2 = 0;
        cin >> sz1 >> sz2;
        myvvi vvi(sz1, myvi(sz2, 0));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cin >> vvi[i][j];
            }
        }
        
        fun1(vvi);
        
        cout<<endl;
    }
    
    
    return 0;
}
