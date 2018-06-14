
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//手撸 KMP

class Solution {
public:
    int next[100000];
    int strStr(string haystack, string needle) {
        int szh = haystack.size();
        int szn = needle.size();

        next[0] = -1;
        for(int i = 1; i < szn; i++) {
            int j = next[i - 1];
            while(j != -1 && needle[i] != needle[j + 1]) j = next[j];
            next[i] = j + 1;
        }

        int k = 0;
        for(int i = 0; i < szh; i++) {
            if(haystack[i] == needle[k]) k++;
            else {
                while(k > 0 && needle[k] != haystack[i])
                    k = next[k - 1] + 1;
                if(needle[k] == haystack[i]) k++;
            }
            if(k == szn) return i - szn + 1;
        }

        return -1;
    }
};