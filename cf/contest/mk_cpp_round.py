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
    
    # code = input("plz input lvl & name  ").strip()
    
    # name = input("").strip()
    # diff = input("plz input diff   2ch  ").strip()
    
    # print(code + "---" + name)

    t2 = input("input >>>> A. Problem Title <<<< : ").strip()
    code = t2[0: t2.find('.')]
    name = t2[t2.find('.') + 2: ]

    round = input("round: ").strip()

    name = name.replace("'", "")
    name = name.replace(" ", "_")
    name = name.replace("(", "")
    name = name.replace(")", "")
    name = name.replace("?", "")
    # no = code[0:-1]
    # lv = code[-1:]
    
    lv = code

    # if (lv.isdigit()):
    #     no = code[0:-2]
    #     lv = code[-2:]
    
    f_name = "/CF_" + lv + "_" + time.strftime("%Y-%m-%d", time.localtime()) + "_" + name + ".cpp"

    dir_name = time.strftime("%Y-%m_Round", time.localtime()) + round
    # dir_name = "ge" + str(int(int(int(no)/100)*100))
    # if int(no) < 100:
    #     dir_name = "gt000"

    content = """

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// 
void fun1()
{
    
    
    
    
    
    
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    std::cin>>w;
        
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
        print(os.system("emacsclient +17 " + name + " &"))

if __name__ == "__main__":
    mk_cpp()
    # print(mk_cpp.__doc__)
