
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


// D



//for (int i = kk; i <= N; i++) {
//    if (a[i] >= 10) a[i] = f(a[i]), ans++;
//    if (b[i] >= 10) b[i] = f(b[i]), ans++;
//    v1[a[i]]++;
//    v2[b[i]]++;
//}



// 171558142 	Sep/10/2022 10:33UTC+8 	Ouha 	1728C - Digital Logarithm 	GNU C++17 	Accepted 	702 ms 	1600 KB

// 一次变成 个位数， 再来一次就 1
// 能不能直接相等消除。
// 不能则 对 >=10的 做一次 f . 这样就 只剩 1-9了。   然后进行 消除
// 然后 对 >1 的 做一次f。  就肯定 全1了。 就全部消除了。  所以 这次 f 也不必，计算 非 1 就可以了。

int f12(int n);

void fun1(myvi& v1, myvi& v2)
{
    int sz1 = v1.size();

    sort(begin(v1), end(v1));
    sort(begin(v2), end(v2));

    int arr1[10] = { 0 };
    int arr2[10] = { 0 };

    int i1 = 0;
    int i2 = 0;
    
    for (int i = 0; i < sz1; ++i)
    {
        while (i2 < sz1 && v2[i2] < v1[i])
        {
            ++i2;
        }
        if (i2 >= sz1)
            break;
        if (v2[i2] == v1[i])
        {
            v1[i] = -1;
            v2[i2++] = -1;
        }
    }
    int ans = 0;

    for (int i = 0; i < sz1; ++i)
    {
        if (v1[i] > 0)
        {
            if (v1[i] > 9)
            {
                arr1[f12(v1[i])]++;
                ++ans;
            }
            else
            {
                arr1[v1[i]]++;
            }
        }
        if (v2[i] > 0)
        {
            if (v2[i] > 9)
            {
                arr2[f12(v2[i])]++;
                ++ans;
            }
            else
            {
                arr2[v2[i]]++;
            }
        }
    }

    for (int i = 2; i < 10; ++i)
    {
        ans += abs(arr1[i] - arr2[i]);
    }
    cout << ans << endl;
}

int f12(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
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
        myvi v1(sz1);
        myvi v2(sz1);
        for (int i = 0; i < sz1; ++i)
            cin >> v1[i];
        for (int i = 0; i < sz1; ++i)
            cin >> v2[i];
        
        fun1(v1, v2);
        
        //cout<<endl;
    }
    
    
    return 0;
}
