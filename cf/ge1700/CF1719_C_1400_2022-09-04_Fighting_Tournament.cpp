
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
//#include <queue>
//#include <unordered_set>
//#include <numeric>

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>
#define __test1








// 170809918 	Sep/04/2022 15:12UTC+8 	Ouha 	1719C - Fighting Tournament 	GNU C++17 	Accepted 	732 ms 	8500 KB
void fun1(myvi& vi, myvvi& qry)
{
    int sz1 = vi.size();
    int sz2 = qry.size();

    unordered_map<int, vector<int>> map2;

    int mx = vi[0];
    int round = 1;
    int mxi = 0;
    for (int i = 1; i < sz1; ++i)
    {
        if (mx > vi[i])
        {
            ;
        }
        else
        {
            mx = vi[i];
            mxi = i;
        }
        map2[mxi].push_back(round);
        ++round;
    }
    --round;

#ifdef __test
    for (int i : map2[2])
    {
        cout << "             " << i << endl;
    }
    cout << distance(begin(map2[2]), begin(map2[2])) << endl;
#endif


    for (myvi& v : qry)
    {
        int idx = v[0];
        int rnd = v[1];
        if (rnd >= round)
        {
            if (map2.find(idx) == map2.end())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << map2[idx].size() + (idx == mxi ? (rnd - round) : 0) << endl;
            }
        }
        else
        {
            if (map2.find(idx) == map2.end())
            {
                cout << 0 << endl;
            }
            else
            {
                auto it = upper_bound(begin(map2[idx]), end(map2[idx]), rnd);
                if (it == begin(map2[idx]))
                    cout << 0 << endl;
                else
                    cout << std::distance(begin(map2[idx]), it) << endl;
            }
        }
    }

}

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

        vector<int> vi(sz1);
        myvvi vvi(sz2, myvi(2));

        for (int i = 0; i < sz1; ++i)
            cin >> vi[i];
        for (int i = 0; i < sz2; ++i)
        {
            cin >> vvi[i][0] >> vvi[i][1];
            --vvi[i][0];                    // vi index from 0
        }
        
        fun1(vi, vvi);
        
        //cout<<endl;
    }
    
    
    return 0;
}
