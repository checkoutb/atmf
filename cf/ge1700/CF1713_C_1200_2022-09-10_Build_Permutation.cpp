
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
#include <cmath>

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


// D


//std::vector<int> p(n);
//int r = n, x = 2 * std::sqrt(n);
//while (r > 0) {
//    while (x * x > 2 * r - 2) {
//        x--;
//    }
//    int v = x * x;
//    for (int i = v - r + 1; i < r; i++) {
//        p[i] = v - i;
//    }
//    r = v - r + 1;
//}





// 171588399 	Sep/10/2022 17:01UTC+8 	Ouha 	1713C - Build Permutation 	GNU C++17 	Accepted 	46 ms 	400 KB

void fun1(int sz1)
{
    
    vector<int> vi(sz1, -1);
    int t2 = sz1 - 1;
    for (int i = sz1 - 1; i >= 0; --i)
    {
        int t3 = i + t2;
        int t4 = std::sqrt(t3);

#ifdef __test
        cout << "          " << i << ", " << t2 << ", " << t4 << ", " << endl;
#endif

        if ((t4 * t4) == (t3))
        {
            vi[i] = t2;
            t2--;
            continue;
        }
        //++t4;

        t4 *= t4;
        t2 = t4 - i - 1;

#ifdef __test
            cout << "    " << t2 << " + " << t3 << ", " << t4 << endl;
#endif
        while (i > t2)
        {
            vi[i] = t4 - i;
            --i;
        }
        i++;
    }
    
    for (int i : vi)
        if (i == -1)
        {
            cout << -1 << endl;
            return;
        }

    for (int i : vi)
        cout << i << ' ';
    cout << endl;

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
        
        fun1(sz1);
        
        //cout<<endl;
    }
    
    
    return 0;
}
