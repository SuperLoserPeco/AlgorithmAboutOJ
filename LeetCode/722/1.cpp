#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> ret;
    vector<string> removeComments(vector<string>& source) {
        int sz = source.size();
        int last = 0;
        int lastnum = 0;

        string newline = "";
        ret.push_back(newline);
        lastnum++;

        for(int i = 0; i < sz; i++) {
            int szLen = source[i].length();

            if(last == 0 && lastnum > 0) {
                if(ret[lastnum - 1].length() > 0) {
                    string newline = "";
                    ret.push_back(newline);
                    lastnum++;
                }
            }
            for(int j = 0; j < szLen; j++) {
                if(last == -1) {
                    if(j + 1 < szLen) {
                        if(source[i][j] == '*' && source[i][j + 1] == '/') {
                            last = 0;
                            j++;
                        }
                    }
                }
                else{
                    if(j + 1 < szLen) {
                        if(source[i][j] == '/' && source[i][j + 1] == '*'){
                            last = -1;
                            continue;
                        }
                        else if(source[i][j] == '/' && source[i][j + 1] == '/')
                            break;
                    }
                    ret[lastnum - 1] = ret[lastnum - 1] + source[i][j];
                }
            }
        }
        return ret;
    }
};