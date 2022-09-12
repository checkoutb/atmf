
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






// 171239707 	Sep/07/2022 21:37UTC+8 	Ouha 	1714F - Build a Tree and That Is It 	GNU C++17 	Accepted 	639 ms 	0 KB

void fun1(int n, int d12, int d23, int d13)
{
    int c = d13 + d23 - d12;
    if (c % 2)
    {
        cout << "NO" << endl;
        return;
    }
    c = c / 2;
    int b = d23 - c;
    int a = d12 - b;

    if (c < 0 || b < 0 || a < 0 || (a + b + c + 1 > n))
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int st = 4;
    if (c == 0)
        st = 3;
    else if (a == 0)
        st = 1;
    else if (b == 0)
        st = 2;

    int st2 = st;
    int node = st == 4 ? 5 : 4;

    for (int i = 1; i < a; ++i)
    {
        cout << st2 << ' ' << node << endl;
        st2 = node;
        ++node;
    }
    if (a != 0)
    {
        cout << st2 << ' ' << 1 << endl;
    }
    st2 = st;
    
    for (int i = 1; i < b; ++i)
    {
        cout << st2 << ' ' << node << endl;
        st2 = node;
        ++node;
    }
    if (b != 0)
    {
        cout << st2 << ' ' << 2 << endl;
    }

    st2 = st;
    for (int i = 1; i < c; ++i)
    {
        cout << st2 << ' ' << node << endl;
        st2 = node;
        ++node;
    }
    if (c != 0)
    {
        cout << st2 << ' ' << 3 << endl;
    }

    st2 = st;
    for (; node <= n; ++node)
    {
        cout << st2 << ' ' << node << endl;
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
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        
        fun1(n,a,b,c);
        
        //cout<<endl;
    }
    
    
    return 0;
}
