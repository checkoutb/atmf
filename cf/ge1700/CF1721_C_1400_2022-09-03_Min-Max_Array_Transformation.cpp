
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

//#include <cstdio>
//const int N = 2e5 + 10;
//int T, n, a[N], b[N], ans[N];
//int main() {
//    scanf("%d", &T);
//    while (T--) {
//        scanf("%d", &n);
//        for (int i = 1; i <= n; ++i)scanf("%d", &a[i]);
//        for (int i = 1; i <= n; ++i)scanf("%d", &b[i]);
//        for (int p = 1, i = 1; i <= n; ++i) {
//            while (b[p] < a[i])++p;
//            printf("%d ", b[p] - a[i]);
//        }
//        putchar('\n'), ans[n] = b[n] - a[n];
//        for (int p = n, i = n - 1; i; --i) {
//            if (a[i + 1] > b[i])p = i;
//            ans[i] = b[p] - a[i];
//        }
//        for (int i = 1; i <= n; ++i)printf("%d ", ans[i]);
//        putchar('\n');
//    }
//    return 0;
//}


//for (int i = 1; i <= n; i++) {
//    printf("%d ", *lower_bound(b + 1, b + 1 + n, a[i]) - a[i]);
//}
//printf("\n");
//for (int i = 1, j = 1; i <= n; i++, j = max(j, i)) {
//    while (j < n && a[j + 1] <= b[j])j++;
//    printf("%d ", b[j] - a[i]);
//}



//int j = 1;
//for (int i = 1; i <= n; i++) {
//    j = max(j, i);
//    while (b[j] >= a[j + 1] && j < n)j++;
//    ans2[i] = b[j] - a[i];
//    ans1[i] = b[(lower_bound(b + 1, b + n + 1, a[i]) - b)] - a[i];
//}









// 170749191 	Sep/03/2022 22:10UTC+8 	Ouha 	1721C - Min-Max Array Transformation 	GNU C++17 	Accepted 	779 ms 	1600 KB

// max： a[i] >= b[i-1]  感觉是对的，  但我不知道为什么是对的。  应该是 +正数 后 次序。
// min： 第一个大于等于 的数
// max: 
// 10   20    30      40
//         22   33 33     55
void fun1(myvi& v1, myvi& v2)
{
    int sz1 = v1.size();

    int i2 = 0;
    
    for (int i = 0; i < sz1; ++i)
    {
        while (v2[i2] < v1[i])
            i2++;
        cout << (v2[i2] - v1[i]) << " ";
    }
    cout << endl;

    i2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        while (i2 + 1 < sz1 && v2[i2] >= v1[i2 + 1])
        {
            i2++;
        }
        cout << (v2[i2] - v1[i]) << " ";
        if (i2 == i)
            ++i2;
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
        int sz1 = 0;
        cin >> sz1;

        myvi v1(sz1);
        myvi v2(sz1);

        for (int i = 0; i < sz1; ++i)
            cin >> v1[i];
        for (int i = 0; i < sz1; ++i)
            cin >> v2[i];
        
        fun1(v1, v2);
        
        cout<<endl;
    }
    
    
    return 0;
}
