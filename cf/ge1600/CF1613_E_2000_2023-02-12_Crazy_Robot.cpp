
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







// error

int dfsmemo(vector<string>& vs, int r, int c);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    vector<string> vs(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vs[i];
    }
    
    // + , -
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (vs[i][j] == '.' || vs[i][j] == '-')
            {
                vs[i][j] = '.';
                dfsmemo(vs, i, j);
            }
        }
    }
    
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (vs[i][j] == '-')
                vs[i][j] = '.';
        }
    }
    for (string& s : vs)
        cout << s << endl;
}


static int arr[5] = {1,0,-1,0,1};

// is there a way/path that never goto lab ?
// false: no way or out of bound or #
//bool dfsmemo(vector<string>& vs, int r, int c)
// 1: always lab
// 2: can no lab
// 3: no way
int dfsmemo(vector<string>& vs, int r, int c)
{
    if (r < 0 || c < 0 || r == vs.size() || c == vs[0].size() || vs[r][c] == '#')
        return 3;
    if (vs[r][c] == 'L' || vs[r][c] == '+')
        return 1;
    if (vs[r][c] == '-')
        return 2;

    vs[r][c] = '-';

    int cnt = 0;
    int t2;
    bool golab = false;
    for (int i = 1; i < 5; ++i)
    {
        t2 = dfsmemo(vs, r + arr[i], c + arr[i - 1]);
        if (t2 == 1)
            golab = true;
        else if (t2 == 2)
            ++cnt;
    }

    if (cnt > 1 || (golab == false))
    {
        return 2;
    }
    vs[r][c] = '+';
    return 1;
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
