
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






// 171340249 	Sep/08/2022 21:40UTC+8 	Ouha 	1710A - Color the Picture 	GNU C++17 	Accepted 	265 ms 	400 KB 

bool fun1_1(int sz1, int sz2, myvi& vi)
{
    int cnt = 0;
    int mx = -1;
    for (int i : vi)
    {
        if (i / sz1 >= 2)
        {
            if (mx == -1)
                mx = i / sz1;

            cnt += (i / sz1);

        }
        else
        {
            break;
        }
        if (cnt >= sz2)
        {
            if (cnt == sz2 + 1)
            {
                if (mx > 2)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

void fun1(int sz1, int sz2, myvi& vi)
{
    std::sort(begin(vi), end(vi), std::greater<int>());

#ifdef __test
    for (int i : vi)
        cout << i << " , ";
    cout << endl;
#endif

    if (fun1_1(sz1, sz2, vi) || fun1_1(sz2, sz1, vi))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
        int sz1, sz2, k;
        cin >> sz1 >> sz2 >> k;
        myvi vi(k);
        
        for (int i = 0; i < k; ++i)
        {
            cin >> vi[i];
        }

        fun1(sz1, sz2, vi);
        
        //cout<<endl;
    }
    
    
    return 0;
}
