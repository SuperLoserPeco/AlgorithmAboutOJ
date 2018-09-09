#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int sz = s.length();
        int l = 0, r = sz - 1;
        while(l < r) {
            if(l >= r) break;
            while(!isYuanYin(s[l]) && l < r) l++;
            if(l >= r) break;
            while(!isYuanYin(s[r]) && l < r) r--;
            if(l >= r) break;
            swap(s[l], s[r]);
            l++; r--;
        }
        return s;
    }

    bool isYuanYin(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};