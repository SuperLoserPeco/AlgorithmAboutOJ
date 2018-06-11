#include <vector>
#include <string>
#include <iostream>
using namespace std;

//妈的 真麻烦

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> serial;
        int num = 0;
        int strLen = 0;
        int sz = words.size();
        for(int i = 0; i < sz; i++) {
            int nextWidth = (num == 0) ? words[i].length() : 
                                strLen + words[i].length() + 1;
            if(nextWidth > maxWidth) {
                serial.push_back(i);
                num = 1;
                strLen = words[i].length();
                if(i + 1 >= sz) {
                    serial.push_back(i + 1);
                }
            }
            else{
                strLen = nextWidth;
                num++;
                if(i + 1 >= sz) {
                    serial.push_back(i + 1);
                }
            }
        }
        int szSerial = serial.size();
        int last = 0;
        vector<string> ans;
        for(int i = 0; i < szSerial; i++) {
            string cur = "";
            int l = last, r = serial[i];
            int strNum = r - l, strDigitNum = 0;
            for(int j = last; j < r; j++) {
                strDigitNum += (int)words[j].length();
            }
            int strSpaceNum = maxWidth - strDigitNum;
            if(strNum == 1) {
                cur = words[last] + spaceNum(maxWidth - words[last].length());
                ans.push_back(cur);
            }
            else if(i == szSerial - 1) {
                for(int j = last; j < r; j++) {
                    cur = cur + ((j == r - 1) ? words[j] : (words[j] + " "));
                }
                cur = cur + spaceNum(maxWidth - cur.length());
                ans.push_back(cur);
            }
            else{
                cout << "spaceNum = " << strSpaceNum << endl;
                for(int j = last; j < r; j++) {
                    cout << "j = " << j << endl;
                    if(j == last)
                        cur = cur + words[j];
                    else {
                        if(j == r - 1) {
                            cur = cur + spaceNum(strSpaceNum) + words[j];
                        }
                        else {
                            cout << "r - j " << r - j << endl;
                            int curSpaceNum = strSpaceNum / (r - j) + 
                                              (strSpaceNum % (r - j) ? 1 : 0);
                            cur = cur + spaceNum(curSpaceNum) + words[j];
                            strSpaceNum -= curSpaceNum;
                        }
                    }
                }
                ans.push_back(cur);
            }
            last = serial[i];
        }
        return ans;
    }

    string spaceNum(int N) {
        string ret = "";
        for(int i = 0; i < N; i++)
            ret = ret + " ";
        return ret;
    }
};