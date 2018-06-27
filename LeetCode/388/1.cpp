#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int llex(string& input, int& locate, bool& isFile) {
        int sz = input.length();
        if(locate < sz) {
            if(input[locate] == '\n') {
                locate++;
                return -1;
            }
            else if(input[locate] == '\t') {
                locate++;
                return -2;
            }
            else {
                int dotnum = 0;
                while(locate < sz && isFileDigit(input[locate])){
                    if(input[locate] == '.') dotnum++;
                    locate++;
                }
                if(dotnum >= 1) isFile = true;
                return locate;
            }
        }
    }

    int lengthLongestPath(string input) {
        int locate = 0;
        int sz = input.length();

        map<int, int> len;

        int max_val = 0;
        while(locate < sz) {
            int last = locate;
            bool isFile = false;
            int flag = llex(input, locate, isFile);
            int blank = 0;
            if(flag == -1) {
                last = locate;
                while((flag = llex(input, locate, isFile)) == -2) {
                    blank++;
                    last = locate;
                }
                
                len[blank] = locate - last;
                if(blank > 0) len[blank] = len[blank - 1] + len[blank] + 1;
            }
            else {
                len[blank] = locate - last;
            }
            if(isFile) {
                max_val = max(max_val, len[blank]);
            }
        }
        return max_val;
    }

    bool isFileDigit(char c) {
        return (c >= '0' && c <= '9') ||
                (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c == '.') || (c == ' ');
    }
};