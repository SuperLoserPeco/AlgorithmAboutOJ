#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;

vector<string>  split(const string& str,const string& delim) { //将分割后的子字符串存储在vector中
    vector<string> res;
    if("" == str) return  res;
    
    string strs = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
    size_t pos;
    size_t size = strs.size();

    for (int i = 0; i < size; ++i) {
        pos = strs.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
        if( pos < size) { //如果查找到，如果没有查找到分隔符，pos为string::npos
            string s = strs.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
            res.push_back(s);//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
            i = pos + delim.size() - 1;
        }
        
    }
    return res;	
}

int main() {
    string test = "[1,2,3,null,null,4,5]";
    string output = (test.substr(1, test.length() - 2));
    cout << output << endl;
    vector<string> res = split(output, ",");

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
        if(res[i] == "null") {
            cout << i << endl;
        }
    }
}
