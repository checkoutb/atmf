
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


// D

// 由于 sum of digit 的下降非常快。 保存 值大于9 的 下标，用 set，有序的。
// lower_bound(l), 直到 r。 由于 下降非常快， 所以 每个下标 2次后 就不可能再 进入 set了。
// 6
// 





// g

void fun1()
{
    int sz1, sz2;
    cin >> sz1 >> sz2;


}



// tle 41
// 999999..9 -> 81 -> 9 ->   . < 10
void fun1_tttlllee()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];

    myvi v2(sz1);

    int tp, l, r, x, t2, cnt;
    int st{ sz1 }, en{ -1 };
    for (int i3 = 0; i3 < sz2; ++i3)
    {
        cin >> tp;
        if (tp == 1)
        {
            cin >> l >> r;
            --l, --r;
            v2[l] += 1;
            if (r + 1 < sz1)
                v2[r + 1] -= 1;
            st = min(st, l);
            en = max(en, r);
        }
        else
        {
            cin >> x;
            --x;
            cnt = 0;

            if (x < st || x > en)           // for tle 32
            {
                cout << vi[x] << endl;
                continue;
            }

            for (int i = st; i <= en; ++i)
            {
                cnt += v2[i];
                for (int j = 0; j < cnt && vi[i] >= 10; ++j)
                {
                    t2 = vi[i];
                    vi[i] = 0;
                    while (t2 > 0)
                    {
                        vi[i] += t2 % 10;
                        t2 /= 10;
                    }
                }
                v2[i] = 0;
            }
            if (en + 1 < sz1)
                v2[en + 1] = 0;
            st = sz1, en = -1;

            cout << vi[x] << endl;
        }
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
