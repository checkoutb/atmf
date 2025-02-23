import os
import sys
import time
import platform

# mk xxxx.cpp

def mk_cpp():
    '''
    1722G 	
Even-Odd XOR 
    '''
    
    # print("-------------")
    
    code = input("plz input No. & name  ").strip()
    
    name = input("").strip()
    diff = input("plz input diff   2ch  ").strip()
    
    # print(code + "---" + name)

    name = name.replace("'", "")
    name = name.replace(" ", "_")
    name = name.replace("(", "")
    name = name.replace(")", "")
    name = name.replace("?", "")
    no = code[0:-1]
    lv = code[-1:]
    
    if (lv.isdigit()):
        no = code[0:-2]
        lv = code[-2:]
    
    f_name = "/CF" + no.zfill(4) + "_" + lv + "_" + diff + "00_" + time.strftime("%Y-%m-%d", time.localtime()) + "_" + name + ".cpp"
    
    dir_name = "ge" + str(int(int(int(no)/100)*100))
    if int(no) < 100:
        dir_name = "gt000"

    content = """
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
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
//#include <unordered_map>
//#include <string.h>       // memset
//#include <iomanip>    // std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;
//#include <utility>  // pair (include by other header)

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE









// 
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    
    
    
    
    
}


int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    int w = 1;
    
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:"<<std::endl;
    #endif
    std::cin>>w;  // <------   remove or not
    
    
    
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
"""

    # print(f_name)
    name = dir_name + f_name
    pwd = os.getcwd() + "/" + name
    print(pwd)

    # if os.path.isfile(pwd):
    if os.path.exists(name):
        print("already exists, so exit...")
        sys.exit()

    # 如果是/开头，那么是 根目录文件下。
    if not os.path.isdir(dir_name):
        os.makedirs(dir_name)

    # not a file, 已经能确保不会删除其他文件了。
    if not os.path.isfile(name):
        fd = open(name, mode="a+", encoding='utf-8')
        fd.write(content)
        fd.close()

    with open("last_cpp_path", 'w', encoding='utf-8') as f:
        f.write(name)
    
    if 'linux' in platform.system().lower():
        print(os.system("emacsclient +52 " + name + " &"))

if __name__ == "__main__":
    mk_cpp()
    # print(mk_cpp.__doc__)
