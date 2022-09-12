
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


// D

//while (t--)
//{
//    scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &d);
//    if (((n - sx) <= d || sy - 1 <= d) && (sx - 1 <= d || m - sy <= d)) puts("-1");
//    else printf("%d\n", n + m - 2);
//}

// 和激光 同 x / y 轴的， 是它 能 影响到的 最远的  y / x 。



// 170798410 	Sep/04/2022 12:32UTC+8 	Ouha 	1721B - Deadly Laser 	GNU C++17 	Accepted 	109 ms 	0 KB 
// 
// border * 2
void fun1(myvi& vi)
{
    int m = vi[0];
    int n = vi[1];
    int x = vi[2];
    int y = vi[3];
    int dis = vi[4];
    bool can = true;
    for (int j = 1; j <= n; ++j)
    {
        if (x - 1 + abs(j - y) <= dis)
        {
            can = false;
            break;
        }
    }

    if (can)
    {
        for (int i = 1; i <= m; ++i)
        {
            if (abs(x - i) + n - y <= dis)
            {
                can = false;
                break;
            }
        }
        if (can)
        {
            cout << m + n - 2;
            return;
        }
    }

    can = true;
    for (int i = 1; i <= m; ++i)
    {
        if (abs(x - i) + y - 1 <= dis)
        {
            can = false;
            break;
        }
    }
    if (can)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (m - x + abs(y - j) <= dis)
            {
                can = false;
                break;
            }
        }
        if (can)
        {
            cout << m + n - 2;
            return;
        }
    }
    cout << -1;
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
        vector<int> vi(5);

        for (int i = 0; i < 5; ++i)
            cin >> vi[i];
        
        fun1(vi);
        
        cout<<endl;
    }
    
    
    return 0;
}
