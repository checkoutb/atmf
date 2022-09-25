
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
//#include <numeric>
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


// D


//static inline void writeln()
//{
//    write('\n');
//}
//
//template<typename T, typename... Args>
//void writeln(const T& x, const Args&... args)
//{
//    write(x), writeln(args...);
//}
//
//for (int i = 0; i < n; ++i)
//{
//    if (!(max(b[(i + n - 1) % n], b[(i + 1) % n]) < b[i] || min(b[(i + n - 1) % n], b[(i + 1) % n]) > b[i]))
//        return writeln("NO");
//}



//if (n & 1) {
//    cout << "NO" << endl;
//    return;
//}
//for (int i = 0; i < n / 2; i++) b[2 * i] = a[i];
//for (int i = n / 2; i < n; i++) b[2 * (i - n / 2) + 1] = a[i];
//for (int i = 0; i + 1 < n; i++) {
//    if (b[i] == b[i + 1]) {
//        cout << "NO" << endl;
//        return;
//    }
//}
//cout << "YES" << endl;
//for (int i = 0; i < n; i++) {
//    cout << b[i] << " \n"[i == n - 1];
//}



// 173380721 	Sep/25/2022 11:07UTC+8 	Ouha 	1685A - Circular Local MiniMax 	GNU C++17 	Accepted 	436 ms 	900 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    sort(begin(vi), end(vi));
    
    myvi v2(sz1);

    int j = 0;
    for (int i = 0; i < sz1; i += 2, ++j)
    {
        v2[i] = vi[j];
    }
    for (int i = 1; i < sz1; i += 2, ++j)
    {
        v2[i] = vi[j];
    }

    for (int i = 0; i < sz1; ++i)
    {
        if (v2[i] < v2[(i + 1) % sz1])
        {
            if (v2[i] >= v2[(i - 1 + sz1) % sz1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (v2[i] > v2[(i + 1) % sz1])
        {
            if (v2[i] <= v2[(i - 1 + sz1) % sz1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    for (int i : v2)
    {
        cout << i << ' ';
    }
    cout << endl;
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
