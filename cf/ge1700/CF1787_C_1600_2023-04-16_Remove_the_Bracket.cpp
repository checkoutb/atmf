
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










// x+y=a;
// >s  <s
// f = a1 * x2 + (a2-x2)*x3 + (a3-x3)*x4 ... + (an_1 - xn_1)*an
// a1 * x2 + a2*x3 - x2*x3 + a3*x4 - x3*x4  +  ... + an_1*an - xn_1*an
// a1*x2 + a2*x3 + a3*x4 + .. + an_2*xn_1 + an_1*an   
//                     - x2*x3 - x3*x4 - ... - xn_2*xn_1 - xn_1*an
// x1,x2,x3..
// a1*x1 +.. + an-1*xn-1
//  - x1*x2 - x2*x3 - xn-1*an
// 1 2 2
// 5 6 8 15 - 
// 5 3 4 3 5
// 5*1 + (3-1)*2 + (4-2)*2 + (3-2)*5
// x==s or y==s ???
// 5*1 + (2)*3 + (1)*2 + 1*5
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    int s;
    cin >> s;
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int xa, xb, suma, sumb;
    
    xa = s;             // always == s
    xb = vi[1] - s;     // always == (s-?)
    suma = vi[0] * xa;
    sumb = vi[0] * xb;
    
    int ta, tb, tsa, tsb;

    for (int i = 1; i < sz1 - 1; ++i)
    {
        
    }
    
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
