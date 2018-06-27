#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<int, int> sn;
        map<int, int> tn;
        int szs = s.length();
        int szt = t.length();
        for(int i = 0; i < szs; i++)
            sn[s[i] - 'a']++;
        for(int i = 0; i < szt; i++)
            tn[t[i] - 'a']++;

        for(int i = 0; i < 26; i++) {
            if(sn[i] != tn[i]) return i + 'a';
        }
    }
};