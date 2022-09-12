
//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>

//#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <cmath>

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>


// D

//const int N = 1e3 + 10;
//int T, n, q;
//long long sum[N][N];
//int main() {
//    scanf("%d", &T);
//    while (T--) {
//        scanf("%d %d", &n, &q);
//        for (int i = 1; i <= 1000; ++i)for (int j = 1; j <= 1000; ++j)sum[i][j] = 0;
//        for (int x, y, i = 1; i <= n; ++i) {
//            scanf("%d %d", &x, &y);
//            sum[x][y] += x * y;
//        }
//        for (int i = 1; i <= 1000; ++i)for (int j = 1; j <= 1000; ++j)sum[i][j] += sum[i][j - 1];
//        for (int i = 1; i <= 1000; ++i)for (int j = 1; j <= 1000; ++j)sum[i][j] += sum[i - 1][j];
//        for (int sx, sy, tx, ty, i = 1; i <= q; ++i) {
//            scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
//            printf("%lld\n", sum[sx][sy] + sum[tx - 1][ty - 1] - sum[sx][ty - 1] - sum[tx - 1][sy]);
//        }
//    }
//    return 0;
//}
// 。。。



//for (int i = 1; i < N; i++)
//    for (int j = 1; j < N; j++)
//        r[i][j] += r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1];
//while (q--) {
//    int h1, w1, h2, w2;
//    scanf("%d %d %d %d", &h1, &w1, &h2, &w2);
//    printf("%lld\n", r[h2 - 1][w2 - 1] - r[h1][w2 - 1] - r[h2 - 1][w1]
//        + r[h1][w1]);
//}


// 长和宽 都小于 自己的 所有 矩形的 和。





// map 和 数组 性能差好多。 而且我这里还是 固定约 8mb 大小的数组。并且 最多 10万vvi，  使用率 最多 10% 。

// 3 是 sum2 溢出
// 9 是 prefix sum 溢出

//170725160 	Sep / 03 / 2022 18:16UTC + 8 	Ouha 	1722E - Counting Rectangles 	GNU C++17 	Accepted 	1700 ms 	14300 KB
//170725047 	Sep / 03 / 2022 18 : 15UTC + 8 	Ouha 	1722E - Counting Rectangles 	GNU C++17 	Wrong answer on test 9 	1247 ms 	10400 KB
//170720260 	Sep / 03 / 2022 17 : 30UTC + 8 	Ouha 	1722E - Counting Rectangles 	GNU C++17 	Time limit exceeded on test 12 	6000 ms 	10300 KB
//170720070 	Sep / 03 / 2022 17 : 28UTC + 8 	Ouha 	1722E - Counting Rectangles 	GNU C++17 	Wrong answer on test 9 	5413 ms 	9100 KB
//170719867 	Sep / 03 / 2022 17 : 26UTC + 8 	Ouha 	1722E - Counting Rectangles 	GNU C++17 	Wrong answer on test 3 	1231 ms 	500 KB
//170719790 	Sep / 03 / 2022 17 : 26UTC + 8 	Ouha 	1722E - Counting Rectangles 	GNU C++17 	Wrong answer on test 1 	0 ms 	100 KB

static long long arr[1001][1001];         // vs 最大1MB，3个解决方法： 1. malloc 。  2. 修改vs栈堆保留大小。 3. static

void fun2(myvvi& vvi, myvvi& qry)
{

    long long sum2 = 0;

    memset(arr, 0, sizeof(arr));

    //cout << sizeof(arr) << endl;      // byte

    sort(begin(vvi), end(vvi));

    int sz1 = vvi.size();
    int sz2 = qry.size();

    for (int i = 0; i < sz1; ++i)
    {
        arr[vvi[i][0]][vvi[i][1]] += vvi[i][0] * vvi[i][1];
    }
    long long t2 = 0;
    for (int i = 1; i < 1001; ++i)
    {
        t2 = 0;
        for (int j = 1; j < 1001; ++j)
        {
            t2 += arr[i][j];
            arr[i][j] = t2;
        }
    }

    for (int i = 0; i < sz2; ++i)
    {
        int h1 = qry[i][0];
        int h2 = qry[i][2];
        int w1 = qry[i][1];
        int w2 = qry[i][3];

        sum2 = 0;

        for (int a = h1 + 1; a < h2; ++a)
        {
            sum2 += (arr[a][w2 - 1] - arr[a][w1]);
        }

        cout << sum2 << endl;
    }

}


// tle...
void fun1(myvvi& vvi, myvvi& qry)
{
    long long sum2 = 0;

    //int arr[1001][1001] = { {0} };

    map<int, map<int, long long>> mmap2;          // < ==, < <=, xx>>

    sort(begin(vvi), end(vvi));

    int sz1 = vvi.size();

    long long t2 = vvi[0][0] * vvi[0][1];
    mmap2[vvi[0][0]][vvi[0][1]] = t2;

    for (int i = 1; i < sz1; ++i)
    {
        if (vvi[i][0] == vvi[i - 1][0])
        {
            t2 += vvi[i][0] * vvi[i][1];
            mmap2[vvi[i][0]][vvi[i][1]] = t2;
        }
        else
        {
            t2 = vvi[i][0] * vvi[i][1];
            mmap2[vvi[i][0]][vvi[i][1]] = t2;
        }
    }

    for (int i = 0; i < qry.size(); ++i)
    {
        int h1 = qry[i][0];
        int h2 = qry[i][2];
        int w1 = qry[i][1];
        int w2 = qry[i][3];
        sum2 = 0;
        for (auto it = mmap2.upper_bound(h1); it != mmap2.end() && it->first < h2; it++)
        {
            map<int, long long>& map2 = it->second;
            auto it_1 = map2.upper_bound(w1);
            auto it_2 = map2.lower_bound(w2);
            int t3 = -1;
            if (it_1 != map2.begin())
                it_1 = prev(it_1);
            else
                if (it_1->first > w1)
                    t3 = 0;
                
            int t5 = -1;
            if (it_2 != map2.begin())
                it_2 = prev(it_2);
            else
                if (it_2->first >= w2)
                    t5 = 0;

            t2 = (t5 == -1 ? it_2->second : t5) - (t3 == 0 ? 0 : it_1->second);
            sum2 += t2;
        }
        cout << sum2 << endl;
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
        int sz1 = 0;        // number of rectangle
        int sz2 = 0;        // count of query
        
        cin >> sz1 >> sz2;

        vector<vector<int>> vvi(sz1, vector<int>(2));
        vector<vector<int>> qry(sz2, vector<int>(4));

        for (int i = 0; i < sz1; ++i)
        {
            cin >> vvi[i][0] >> vvi[i][1];
        }

        for (int i = 0; i < sz2; ++i)
        {
            cin >> qry[i][0] >> qry[i][1] >> qry[i][2] >> qry[i][3];
        }

        fun2(vvi, qry);
        
        //cout<<endl;
    }
    
    
    return 0;
}
