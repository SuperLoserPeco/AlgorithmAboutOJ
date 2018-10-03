#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>
#include <iostream>  
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        ManacherInit(s.c_str());

        int sz = s.length();
        cout << sz << endl;
        int mx = -1;
        string ans = "";
        for(int i = sz / 2; i >= 0; i--) {

            int notOddLen = LengthOfGivenLocationPart(i, false);
            if(notOddLen == i + 1) {
                int cur = notOddLen * 2;
                if(cur <= sz) {
                    string add = s.substr(cur, (sz - cur));
                    reverse(add.begin(), add.end());
                    ans = add + s;
                    return ans;
                }
            }

            int oddLen = LengthOfGivenLocationPart(i, true);
            if(oddLen == i + 1) {
                int cur = oddLen * 2 - 1;
                if(cur <= sz) {
                    string add = s.substr(cur, (sz - cur));
                    reverse(add.begin(), add.end());
                    ans = add + s;
                    return ans;
                }
            }

        }
        return ans;
    }

    private:
    int* p;
    char* str;

    int strLen;
    int manacherLen;
public: 

    int ManacherInitTest(char* s) {
        std::cout << strlen(s) << std::endl;
        int sz = strlen(s);
        str = new char[sz];
        strncpy(str, s, sz);
        std::cout << strlen(str) << std::endl;

        return 0;
    }

    int ManacherInit(const char* s) {
        strLen = strlen(s);
        cout << strLen << endl;
        manacherLen = (strLen + 1) * 2 + 1;

        str = new char[manacherLen];
        p = new int[manacherLen];

        for(int i = 0; i < manacherLen; i++) p[i] = 0;

        for(int i = 1; i <= strLen; i++) {
            str[i * 2] = s[i - 1];
            str[i * 2 + 1] = '#';
        }

        str[0] = '?'; str[1] = '#'; str[manacherLen - 1] = '\0';

        int res = 0, k = 0, maxk = 0;
        for(int i = 2; i < manacherLen; i++) {
            p[i] = i < maxk ? std::min(maxk - i, p[2 * k - i]) : 1;
            while((i - p[i] >= 0) && (i + p[i] < manacherLen)
                    && str[i - p[i]] == str[i + p[i]]) p[i]++;
            if(p[i] + i > maxk) {
                k = i;
                maxk = p[i] + i;
            }
            res = std::max(res, p[i]);
        }
        return res - 1;
    }

    int LengthOfGivenLocation(int locate, bool isOdd) {
        int manacherLocate = (locate + 1) * 2;
        if(isOdd) {
            return ((p[manacherLocate] / 2) * 2 - 1);
        }
        else {
            return ((p[manacherLocate + 1] / 2) * 2);
        }
    }

    int LengthOfGivenLocationPart(int locate, bool isOdd) {
        int manacherLocate = (locate + 1) * 2;
        if(isOdd) {
            return (p[manacherLocate] / 2);
        }
        else {
            return (p[manacherLocate + 1] / 2);
        }
    }

    void Print() {
        for(int i = 0; i < strLen; i++) {
            std::cout << "odd " << i << " = " << LengthOfGivenLocation(i, true) << std::endl;
            std::cout << "not odd " << i << " = " << LengthOfGivenLocation(i, false) << std::endl;
        }
    }
};