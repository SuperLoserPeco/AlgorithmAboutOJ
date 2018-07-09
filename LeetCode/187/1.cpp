#include <vector>
using namespace std;

class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        int sz = s.length();
        int* next = new int[sz + 1];
        bool* vis = new bool[sz + 1];
        next[0] = -1;
        for(int i = 1; i < sz; i++) {
            int cur = i - 1;
            while(cur != -1 && s[next[cur] + 1] != s[i]) cur = next[cur];
            if(cur != -1) cur = next[cur] + 1;
            next[i] = cur;
        }
        for(int i = 0; i < sz; i++) {

        }
    }
};00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000