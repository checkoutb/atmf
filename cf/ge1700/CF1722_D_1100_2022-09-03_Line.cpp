
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

// D

//std::priority_queue<int> heap;
//int max(int x, int y) { return x > y ? x : y; }
//int main() {
//    scanf("%d", &T);
//    while (T--) {
//        scanf("%d %s", &n, s + 1);
//        long long ans = 0;
//        for (int i = 1; i <= n; ++i) {
//            int l = i - 1, r = n - i;
//            if (s[i] == 'L')ans += l, heap.push(r - l);
//            else ans += r, heap.push(l - r);
//        }
//        while (heap.size()) {
//            ans += max(0, heap.top());
//            printf("%lld ", ans), heap.pop();
//        }
//        putchar('\n');
//    }
//    return 0;
//}


//while (t--) {
//    cin >> n >> s;
//    long long sum = 0;
//    for (int i = 0; i < n; i++) {
//        if (s[i] == 'L') sum += i, a[i] = n - 2 * i - 1;
//        else sum += n - i - 1, a[i] = 2 * i + 1 - n;
//    }
//    sort(a, a + n, greater<int>());
//    for (int i = 0; i < n; i++) {
//        if (a[i] > 0) sum += a[i];
//        cout << sum << ' ';
//    }
//    cout << '\n';
//}


// 170731627 	Sep/03/2022 19:22UTC+8 	Ouha 	1722D - Line 	GNU C++17 	Accepted 	109 ms 	2300 KB
void fun1(string& s)
{
    int sz1 = s.size();
    long long sum2 = 0;
    vector<int> vi;
    for (int i = 0; i < sz1; ++i)
    {
        //sum2 += s[i] == 'L' ? i : (sz1 - 1 - i);
        if (s[i] == 'L')
        {
            sum2 += i;
            if (i < sz1 / 2)                // <
                vi.push_back(i);
        }
        else
        {
            sum2 += (sz1 - 1 - i);
            if (i >= sz1 / 2)               // >=
                vi.push_back(sz1 - i - 1);
        }
    }
    sort(begin(vi), end(vi));
    int idx = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (idx < vi.size())
        {
            sum2 = sum2 - vi[idx] + (sz1 - 1 - vi[idx]);
            idx++;
        }
        cout << sum2 << " ";
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
        string s;
        cin >> s;

        fun1(s);
        
        cout<<endl;
    }
    
    
    return 0;
}
