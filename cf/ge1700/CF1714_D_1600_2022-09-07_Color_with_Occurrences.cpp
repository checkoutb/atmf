
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
#define __test2


// D 

// register bool Flag(true); register int M(A[j].size());


//cin.tie(0); ios::sync_with_stdio(0);
//cin >> t;
//while (t--) {
//    ans = r = l = 0;
//    cin >> s >> n;
//    for (int i = 0; i < n; ++i)
//        cin >> a[i];
//    while (r < s.size()) {
//        int lr = r;
//        for (int i = 0; i <= lr && r < s.size(); ++i)
//            for (int j = 0; j < n; ++j) {
//                bool ac = 1;
//                if (i + a[j].size() > s.size() || i + a[j].size() <= r)ac = 0;
//                for (int k = 0; k < a[j].size() && ac; ++k)
//                    if (a[j][k] != s[i + k])ac = 0;
//                if (ac) {
//                    rt[ans][0] = j;
//                    rt[ans][1] = i;
//                    r = i + a[j].size();
//                }
//            }
//        if (lr == r)break;
//        ++ans;
//    }
//    if (r < s.size())
//        cout << "-1\n";
//    else {
//        cout << ans << "\n";
//        for (int i = 0; i < ans; ++i)
//            cout << rt[i][0] + 1 << " " << rt[i][1] + 1 << "\n";
//    }
//}



// 171233609 	Sep/07/2022 20:46UTC+8 	Ouha 	1714D - Color with Occurrences 	GNU C++17 	Accepted 	46 ms 	200 KB

int finda1(string& s, int st, vector<string>& vs);

void fun1(string& s, vector<string>& vs)
{
    unordered_map<string, int> map2;
    for (int i = 0; i < vs.size(); ++i)
    {
        map2[vs[i]] = i;
    }

    std::sort(begin(vs), end(vs), [](string& s1, string& s2) { return s1.size() > s2.size(); });

    vector<int> vidx(vs.size());
    for (int i = 0; i < vs.size(); ++i)
    {
        vidx[i] = map2[vs[i]] + 1;
    }

#ifdef __test
    //for (string& ss : vs)
    //    cout << ss << endl;
#endif

    vector<int> v1(s.size(), INT_MAX >> 2);     // min step
    vector<int> v2(s.size(), -1);           // vs.index

    for (int i = s.size() - 1; i >= 0; --i)
    {
        int match = finda1(s, i, vs);
        if (match != -1)
        {
            if (i + vs[match].size() == s.size())
            {
                for (int j = i; j < s.size(); ++j)
                {
                    v1[i] = 1;
                    v2[i] = match;
                }
                continue;
            }
            int mn = v1[i];
            for (int j = 1; j <= vs[match].size(); ++j)
            {
                if (mn > v1[i + j])
                {
                    mn = v1[i + j];
                }
            }
            if (mn < v1[i])
            {
                v1[i] = mn + 1;
                v2[i] = match;
            }
        }
    }

    if (v2[0] == -1)
    {
        cout << -1 << endl;
        return;
    }

#ifdef __test
    for (int i : v1)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (int i : v2)
    {
        cout << i << ", ";
    }
    cout << endl;
#endif

    cout << v1[0] << endl;
    cout << vidx[v2[0]] << ' ' << 1 << endl;
    int mn = v1[0] - 1;
    for (int i = 1; i < v2.size(); ++i)
    {
        if (v1[i] == mn)
        {
            cout << vidx[v2[i]] << ' ' << i + 1 << endl;
            mn--;
        }
    }

}

int finda1(string& s, int st, vector<string>& vs)
{
    for (int i = 0; i < vs.size(); ++i)
    {
        for (int j = 0; j < vs[i].size(); ++j)
        {
            if (st + j == s.size() || vs[i][j] != s[st + j])
                goto AAA;
        }
        return i;
        
        AAA:
        continue;
    }
    return -1;
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
        string s;
        cin >> s;
        int sz1;
        cin >> sz1;
        vector<string> vs(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            cin >> vs[i];
        }
        
        fun1(s, vs);
        
        //cout<<endl;
    }
    
    
    return 0;
}
