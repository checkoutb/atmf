
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






// 171505552 	Sep/09/2022 21:14UTC+8 	Ouha 	1726B - Mainak and Interesting Sequence 	GNU C++17 	Accepted 	826 ms 	0 KB 

// 1111   15
// 1100   12
// 0011   3   还是偶数。  最后一bit  count是偶数。
void fun1(int sz1, int sum2)
{
    if (sz1 > sum2)
    {
        cout << "No" << endl;
        return;
    }
    if (sz1 % 2 == 0 && sum2 % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "Yes" << endl;
    if (sz1 % 2 == 0)
    {
        for (int i = 0; i < sz1 - 2; ++i)
        {
            cout << "1 ";
            --sum2;
        }
        cout << sum2 / 2 << ' ' << sum2 / 2 << endl;
    }
    else
    {
        for (int i = 0; i < sz1 - 1; ++i)
        {
            cout << 1 << ' ';
            --sum2;
        }
        cout << sum2 << endl;
    }
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
        int sz1;
        int sum2;
        cin >> sz1 >> sum2;
        
        fun1(sz1, sum2);
        
        //cout<<endl;
    }
    
    
    return 0;
}
