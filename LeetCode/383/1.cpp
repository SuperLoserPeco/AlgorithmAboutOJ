#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<int, int> sn;
        map<int, int> tn;
        int szs = ransomNote.length();
        int szt = magazine.length();
        for(int i = 0; i < szs; i++)
            sn[ransomNote[i] - 'a']++;
        for(int i = 0; i < szt; i++)
            tn[magazine[i] - 'a']++;

        for(int i = 0; i < 26; i++) {
            if(sn[i] > tn[i]) return false;
        }
        return true;
    }
};