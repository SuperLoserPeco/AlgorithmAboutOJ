#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int sz = num.length();

        if(sz == 1 || sz == 2)
        {
            return false;
        }

        for(int _len1 = 1; _len1 < sz - 1; _len1 ++)
        {
            
            for(int _len2 = 1; _len2 < sz - _len1; _len2++)
            {
                int pos1 = 0;
                int pos2 = pos1 + _len1;
                int len1 = _len1;
                int len2 = _len2;
                cout << len1 << "--" << len2 << endl;
                while(pos2 + len2 < sz)
                {
                    string s1 = num.substr(pos1, len1);
                    string s2 = num.substr(pos2, len2);
                    if((s1[0] == '0' && s1.length() > 1) || 
                        (s2[0] == '0' && s2.length() > 1))
                    {
                        break;
                    }
                    cout << s1 << endl;
                    cout << s2 << endl;

                    reverse(s1.begin(), s1.end());
                    reverse(s2.begin(), s2.end());
                    string s3 = "";
                    int step = 0;
                    for(int i = 0; i < max(len1, len2); i++)
                    {
                        int num1 = i < len1 ? s1[i] - '0' : 0;
                        int num2 = i < len2 ? s2[i] - '0' : 0;
                        int current = (num1 + num2 + step) % 10;
                        step = (num1 + num2 + step) / 10;
                        s3 += to_string(current);
                    }
                    if(step != 0)
                    {
                        s3 += to_string(step);
                    }
                    reverse(s3.begin(), s3.end());
                    int s3Len = s3.length();
                    if(pos2 + len2 + s3Len > sz)
                    {
                        break;
                    }
                    if(s3 != num.substr(pos2 + len2, s3Len))
                    {
                        cout << "*****" <<endl;
                        cout << s3 << endl;
                        cout << num.substr(pos2, len2) << endl;
                        cout << "*****" <<endl;
                        break;
                    }

                    if(pos2 + len2 + s3Len == sz)
                    {
                        return true;
                    }

                    pos1 = pos2; len1 = len2;
                    pos2 = pos2 + len2; len2 = s3Len;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    s.isAdditiveNumber("12122436");
    return 0;
}