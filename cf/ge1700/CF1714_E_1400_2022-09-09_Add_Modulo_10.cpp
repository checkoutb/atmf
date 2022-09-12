
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

//p = x % 10;
//q = (x / 10) % 2;
//if (p == 0 | p == 5)
//s.insert(x += (p == 5 ? 4 : -1));
//else
//s.insert((p == 3 | p == 6 | p == 7 | p == 9) ? q : q ^ 1);
//
// 是否发生了 进位。


//cin >> x;
//while (x % 10 != 0 && x % 10 != 2)
//{
//    x += x % 10;
//}
//if (x % 10 == 2)
//{
//    x %= 20;
//}
//s.insert(x);
//
// MOD 20



// 171499636 	Sep/09/2022 20:07UTC+8 	Ouha 	1714E - Add Modulo 10 	GNU C++17 	Accepted 	374 ms 	800 KB

// 0 - 0
// 1 2 4 8 6 2 4 8 6 2 4
// 2 4 8 6
// 3 6 2 4 8
// 4 8 6 2 
// 5 0 0 0
// 6 2 4 8
// 7 4 8 6
// 8 6 2 4
// 9 8 6 2 4
//
// 2 4 8 16 22 24 28 36 42 44 48 56 62
// 12 14 18 26 32 34 38 46 52
void fun1(myvi& vi)
{
    int sz1 = vi.size();
    int en0 = -1;
    int en2 = -1;

    for (int i = 0; i < sz1; ++i)
    {
        int t2 = vi[i];
        while (true)
        {
            int t3 = t2 % 10;
            if (t3 == 0 || t3 == 2)
                break;

            t2 += t3;
        }

        if (t2 % 10 == 0)
        {
            if (en0 == -1)
            {
                en0 = t2;
            }
            else
            {
                if (en0 != t2)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        else
        {
            if (en2 == -1)
            {
                en2 = (t2 / 10) % 2;
            }
            else
            {
                if (en2 != (t2 / 10) % 2)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        if (en2 != -1 && en0 != -1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

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
        cin >> sz1;

        myvi v(sz1);

        for (int i = 0; i < sz1; ++i)
            cin >> v[i];
        
        fun1(v);
        
        //cout<<endl;
    }
    
    
    return 0;
}
