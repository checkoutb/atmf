
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





// 170815106 	Sep/04/2022 16:13UTC+8 	Ouha 	1717C - Madoka and Formal Statement 	GNU C++17 	Accepted 	748 ms 	1600 KB
void fun1(myvi& v1, myvi& v2)
{
    int sz1 = v1.size();

    for (int i = 0; i < sz1; ++i)
    {
        if (v1[i] > v2[i])
        {
            cout << "NO";
            return;
        }
        else if (v1[i] < v2[i])
        {
            if (v2[i] - 1 > v2[(i + 1) % sz1])
            {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
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
        cin >> sz1;

        vector<int> vi(sz1);
        vector<int> v2(sz1);

        for (int i = 0; i < sz1; ++i)
            cin >> vi[i];
        for (int i = 0; i < sz1; ++i)
            cin >> v2[i];


        
        fun1(vi, v2);
        
        cout<<endl;
    }
    
    
    return 0;
}
