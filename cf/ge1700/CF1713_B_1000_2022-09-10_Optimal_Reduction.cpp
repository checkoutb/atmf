
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

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>
//#include <unordered_map>

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>
#define __test1









// 171595963 	Sep/10/2022 18:18UTC+8 	Ouha 	1713B - Optimal Reduction 	GNU C++17 	Accepted 	187 ms 	0 KB
void fun1()
{
    
    int sz1;
    cin >> sz1;
    
    //int a = 0;
    int lst;
    cin >> lst;

    int t2;
    bool ans = true;
    bool up = true;
    for (int i = 1; i < sz1; ++i)
    {
        cin >> t2;
        if (t2 < lst)
        {
            up = false;
        }
        else if (t2 > lst)
        {
            if (!up)
                ans = false;
        }
        lst = t2;
    }
    
    cout << (ans ? "YES" : "NO") << endl;
}


int main()
{
    int w = 0;
    cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {
        
        
        fun1();
        
        //cout<<endl;
    }
    
    
    return 0;
}
