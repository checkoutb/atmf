
//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>

#include <cstdio>
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
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>

using namespace std;

// D



//#define F(i, l, r) for(int i=l;i<=r;++i)
//string g[60], s;
//int tc, n, m;
//
//int main() {
//    cin >> tc; while (tc--) {
//        cin >> n >> m;
//        g[0] = g[n + 1] = string(m + 2, '.');
//        F(i, 1, n)cin >> g[i], g[i] = "." + g[i] + ".";
//        s = "YES\n";
//        F(i, 1, n)F(j, 1, m)if (g[i][j] - '.') {
//            int p = 1, q = 1, c = 0;
//            F(x, -1, 1)F(y, -1, 1)if ((x | y) && g[i + x][j + y] - '.')p *= x, q *= y, c++;
//            if (c - 2 | (p | q) * (p + q - 1))s = "NO\n";
//        }
//        cout << s;
//    }
//}


//typedef long long ll;
//const ll N = 110;
//char str[N][N];
//void solve() {
//    ll n, m;
//    scanf("%lld%lld", &n, &m);
//    memset(str, 0, sizeof(str));
//    for (ll i = 1; i <= n; i++) {
//        scanf("%s", str[i] + 1);
//    }
//    for (ll i = 1; i <= n; i++) {
//        for (ll j = 1; j <= m; j++) {
//            if (str[i][j] == '*') {
//                ll cnt = 0, xx = 0, yy = 0;
//                for (ll x = i - 1; x <= i + 1; x++) {
//                    for (ll y = j - 1; y <= j + 1; y++) {
//                        if (str[x][y] == '*') {
//                            cnt++, xx += x, yy += y;
//                        }
//                    }
//                }
//                if (cnt != 3 || xx % 3 == 0 || yy % 3 == 0) {
//                    puts("NO");
//                    return;
//                }
//            }
//        }
//    }
//    puts("YES");
//    return;
//}
//
//int main() {
//    ll t;
//    scanf("%lld", &t);
//    while (t--) {
//        solve();
//    }
//    return 0;
//}




//#define int long long
//#define endl '\n'
//using namespace std;
//#define c1 100000000
//#define c2 10
//#define c3 1000
//#define kN 60
//int w[kN][kN], n, m;
//
//signed main() {
//    ios::sync_with_stdio(0), cin.tie(0);
//    int T; cin >> T;
//    while (T--) {
//        cin >> n >> m;
//        for (int i = 0; i < n + 2; ++i)for (int j = 0; j < m + 2; ++j)w[i][j] = 0;
//        for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j) {
//            char c; cin >> c;
//            if (c == '*')w[i][j] = c1 + i * c2 + j;
//        }
//        bool ok = 1;
//        for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)if (w[i][j]) {
//            int s = 0, t = 0, mx = 0;
//            for (int x = -1; x < 2; ++x)for (int y = -1; y < 2; ++y) {
//                if (x || y)s += w[i + x][j + y], mx = max(mx, w[i + x][j + y]);
//                if (!x || !y)t += w[i + x][j + y];
//            }
//            if ((s + c3) / w[i][j] != 2)ok = 0;
//            if (s == w[i][j] * 2)ok = 0;
//            if (mx * 2 - s == 1 || mx * 2 - s == c2)continue;
//            if ((t + c3) / w[i][j] != 3)ok = 0;
//        }
//        cout << (ok ? "YES\n" : "NO\n");
//    }
//}




// ???



// 170711735 	Sep/03/2022 16:17UTC+8 	Ouha 	1722F - L-shapes 	GNU C++17 	Accepted 	46 ms 	200 KB


bool touch(int sz1, int sz2, vector<string>& vs, int i2, int j2);

// . *
void fun1(int sz1, int sz2, vector<string>& vs)
{
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            if (vs[i][j] == '*')
            {
                if (j + 1 < sz2 && vs[i][j + 1] == '*')
                {
                    if (i + 1 < sz1 && vs[i + 1][j + 1] == '*')
                    {
                        vs[i][j] = '.';
                        vs[i][j + 1] = '.';
                        vs[i + 1][j + 1] = '.';

                        if (touch(sz1, sz2, vs, i, j) || touch(sz1, sz2, vs, i, j + 1) || touch(sz1, sz2, vs, i + 1, j + 1))
                        {
                            ;
                        }
                        else
                        {
                            vs[i][j] = vs[i][j + 1] = vs[i + 1][j + 1] = '#';
                            continue;
                        }

                    }
                    else if (i + 1 < sz1 && vs[i + 1][j] == '*')
                    {
                        vs[i][j] = vs[i][j + 1] = vs[i + 1][j] = '.';
                        if (touch(sz1, sz2, vs, i, j) || touch(sz1, sz2, vs, i, j + 1) || touch(sz1, sz2, vs, i + 1, j))
                        {
                            ;
                        }
                        else
                        {
                            vs[i][j] = vs[i][j + 1] = vs[i + 1][j] = '#';
                            continue;
                        }
                    }
                } 
                else if (i + 1 < sz1 && vs[i + 1][j] == '*')
                {
                    if (j > 0 && vs[i + 1][j - 1] == '*')
                    {
                        vs[i][j] = vs[i + 1][j - 1] = vs[i + 1][j] = '.';

                        if (touch(sz1, sz2, vs, i, j) || touch(sz1, sz2, vs, i + 1, j - 1) || touch(sz1, sz2, vs, i + 1, j))
                        {
                            ;
                        }
                        else
                        {
                            vs[i][j] = vs[i + 1][j - 1] = vs[i + 1][j] = '#';
                            continue;
                        }
                    }
                    else if (j + 1 < sz2 && vs[i + 1][j + 1] == '*')
                    {
                        vs[i][j] = vs[i + 1][j + 1] = vs[i + 1][j] = '.';

                        if (touch(sz1, sz2, vs, i, j) || touch(sz1, sz2, vs, i + 1, j + 1) || touch(sz1, sz2, vs, i + 1, j))
                        {
                            ;
                        }
                        else
                        {
                            vs[i][j] = vs[i + 1][j + 1] = vs[i + 1][j] = '#';
                            continue;
                        }
                    }
                }
            }
            else
            {
                continue;
            }


            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

bool touch(int sz1, int sz2, vector<string>& vs, int i2, int j2)
{
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            int ni = i2 + i;
            int nj = j2 + j;
            if (ni >= 0 && nj >= 0 && ni < sz1 && nj < sz2 && vs[ni][nj] != '.')
            {
                return true;
            }
        }
    }
    return false;
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
        int sz2 = 0;
        cin >> sz1;
        cin >> sz2;

        vector<string> vs(sz1);
        for (int a = 0; a < sz1; ++a)
        {
            cin >> vs[a];
        }

        fun1(sz1, sz2, vs);

        cout<<endl;
    }
    
    
    return 0;
}
