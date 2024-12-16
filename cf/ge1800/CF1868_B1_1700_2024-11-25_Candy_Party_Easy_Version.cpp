
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
//#include <climits>   // INT_MAX

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
//#include <unordered_map>
//#include <string.h>       // memset
//#include <iomanip>    // std::setprecision(10)
#include <utility>  // pair (include by other header)

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE


// D

	// vector<int> bit(31, 0);
	// auto lowbit = [](int x) {
	//     return x & (-x);
	// };
	// for (int i = 0; i < n; i++) {
	// 	if (a[i] == sum) continue;
	// 	int d = abs(a[i] - sum);
	// 	int p = lowbit(d);
	// 	int e = d + p;
	// 	if (__builtin_popcount(e) == 1) {
	// 	    if (a[i] > sum) bit[__lg(e)]++, bit[__lg(p)]--;
	// 	    else bit[__lg(e)]--, bit[__lg(p)]++;
	// 	} else {
	// 	    cout << "No" << '\n';
	// 	    return;
	// 	}
	// }
	// for (int i = 0; i < 31; i++) {
	// 	if (bit[i]) {
	// 		cout << "No" << '\n';
	// 		return;
	// 	}
	// }
	// cout << "Yes" << '\n';


// 看了文字，但是还是不明白 p, e 的含义。
// d 是 a[i] 和 tar 的差值
// p 是 d 的 最右边的 1 作为唯一1 的 值，  但不知道什么含义。
// e=p+d 是什么？  通过 popcount，反推 是： a[i] 第一次 收到/给出的 糖果数。 但是 再反推 p，完全不知道什么含义。
// 看到 p 是 只有一个1，所以 猜测是 第二次 收到/给出的糖果数，但是 对不上。 因为p 和 d 没有关系啊。
// g。不知道。


// g

// Wrong answer on test 6	  



// 给 其他任意一个人 2^x 粒糖。  给且必须给一次。 不能给自己
// 是否满足2个条件： 1. 任意一个人 会且仅会 收到其他一个人的 糖。  2. 每个人糖的个数相同。
// 由2 知道 每个人 缺/多 多少糖。 可能>=3方的， {0, 10, 8} -> {6,4,8} -> {6,6,6} 不是互换。这个缺 2^x, [3]没有收到糖 。。 所以 只会收到一次，所以 一次成型。 可以是： {0,0,0,3,2}
// 不需要考虑 没有收到糖， 在这种情况下， 他只需要给 他给予的那个人 多1粒， 然后那个人多了1粒，继续给 他给予的那个人，最后 肯定 有人没有给，那么 给回来1粒就可以了。  没有给的话，随便给一个人，然后按着 给予的 顺序 排过去。
// 2^x :  似乎，没有这个限制的话， 必然yes ? 只要糖总数能被人数整除。
// 似乎是产生最少的额外输出？就是 原本有 2粒， 糖数的目标是5， 那么 你可以 从某人手里 拿到 4,8,16,32.. 粒糖， 然后 再把 多余的 2+4-5=1, 2+8-5=5=4+1, 2+16-5=13=8+4+1， 32:16+8+4+1， 因为 只能收一次，所以必然 1 优于 4+1， 优于 8+4+1 吧？
// 但是从谁的手里拿？
//
// 应该从大到小， 转为二进制，如果大于  很容易就知道 需要 给出哪些 2^x。 ？ 会出现 拿一个1就把 2^0,2^1,2^2,合并成一个 2^3 来减少可用样本吗？ 应该不会？。。会出现的：{0b10000 - 0b111, 0b10111}  前面给1到后面，后面给 2^3到前面。
// 。。从小到大。 缺的必然是 大于0b111的 最小的 只包含1个1的数。
//
//
// 。。我似乎漏了一个条件：  只能给一个人。 就意味着，多余的 必须是 2^x 。
// 所以 二进制，和 target比较，  多只能多一个 1，  少也只能少 。 不。
//
// 如果小于 target，那么 需要拿一个 2^x, 给出 一个 2^y, 当然如果 拿到后 正好 等于target 最好，这样不需要给出。
// 如果 大于 target，那么需要 给出一个 2^x, 如果正好等于target，最好， 否则 要拿一个 2^y 。
// 然后对比下 是否 配平。   有没有可能 2个 2^x  配一个 2^(x+1)， 我感觉不可能。


int is_1bit1(int a);
int ge_1bit1(int a);
std::pair<int, int> cal_need_remain(int a, int tar);
    
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    int mn = vi[0];
    int mx = vi[0];
    long long sum2 = 0LL;

    for (int i : vi) {
        mn = std::min(mn, i);
        mx = std::max(mx, i);
        sum2 += i;
    }

    if (mn == mx) {
        std::cout<<"yes\n";
        return;
    }
    if (sum2 % sz1 != 0) {
        std::cout<<"no\n";
        return;
    }

    int tar = sum2 / sz1;

    std::map<int, int> mpneed;
    std::map<int, int> mpremain;
    std::sort(std::begin(vi), std::end(vi));
    int t2 = 0;
    std::pair<int, int> pii = std::make_pair(0, 0);
    for (int i = 0; i < sz1; ++i) {
        t2 = vi[i];
        if (t2 < tar) {
            pii = cal_need_remain(t2, tar);
            if (pii.first == -1) {
                // std::cout<<t2<<", "<<tar<<" ,..";
                std::cout<<"no\n";
                return;
            }
            mpneed[pii.first]++;
            mpremain[pii.second]++;
        } else if (t2 > tar) {
            break;
        }
    }

    int t3, t4;
    for (auto it = mpneed.begin(); it != mpneed.end(); it++) {
        t2 = it->first;
        t3 = it->second;

        if (mpremain.contains(t2)) {
            t4 = mpremain[t2];
            if (t3 <= t4) {
                mpneed[t2] = 0;
                mpremain[t2] = t4 - t3;
            } else {
                mpneed[t2] = t3 - t4;
                mpremain[t2] = 0;
            }
        }
    }

    for (int i = sz1 - 1; i >= 0; --i) {
        t2 = vi[i];
        if (t2 <= tar) {
            break;
        }

        pii = cal_need_remain(t2, tar);

        if (pii.first == -1) {
            std::cout<<"no\n";
            return;
        }

        mpneed[pii.first]++;
        mpremain[pii.second]++;
    }

    for (auto it = mpremain.begin(); it != mpremain.end(); it++) {
        if (it->second != mpneed[it->first]) {
            std::cout<<"no\n";
            return;
        }
    }

    std::cout<<"yes\n";
}

// <need, remain>
// <0/1 bit 1, 0/1 bit 1>
// <-1, ?> == impossible
std::pair<int, int> cal_need_remain(int a, int tar) {
    std::pair<int, int> pii = std::make_pair(0, 0);
    int t2 = 0;
    int t3 = 0;
    if (a > tar) {
        // minus, then add
        // t2 = a - tar;
        // t2 = ge_1bit1(t2);
        // pii->
        // pii->first = ge_1bit1(a - tar);
        t2 = ge_1bit1(a - tar);
        t3 = tar - a + t2;
        if (is_1bit1(t3)) {
            pii.first = t3;
            pii.second = t2;
        } else {
            pii.first = -1;
        }
    } else if (a < tar) {
        // add, then minus
        t2 = ge_1bit1(tar - a);
        t3 = a + t2 - tar;
        if (is_1bit1(t3)) {
            pii.first = t2;
            pii.second = t3;
        } else {
            pii.first = -1;
        }
    } else {
        // unreachable
    }
    return pii;
}

// >=a, only 1 bit 1
int ge_1bit1(int a) {
    if (a == 0)
        return 0;  // not 1 bit 1... // unreachable
    
    int t2 = 1;
    while (t2 < a) {
        t2 <<= 1;
    }
    return t2;
}

int is_1bit1(int a) {
    return ((a & (a-1)) == 0); // 0 is also ok...  // & 的优先级真低啊。
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    std::cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {        
        fun1();
        
        #ifdef __test
        std::cout << "   ---/////--------/////---" << std::endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
