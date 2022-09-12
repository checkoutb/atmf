
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




// 170818920 	Sep/04/2022 16:57UTC+8 	Ouha 	1717B - Madoka and Underground Competitions 	GNU C++17 	Accepted 	31 ms 	0 KB
void fun1(myvi& v)
{
    int n = v[0], k = v[1], r = v[2], c = v[3];
    int t2 = (r - c + n) % k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((i - j + n) % k == t2)
            {
                cout << 'X';
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
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
        myvi v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        
        fun1(v);
        
        //cout<<endl;
    }
    
    
    return 0;
}
