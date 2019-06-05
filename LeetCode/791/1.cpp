#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    map<char, int> mpChar;
    string customSortString(string S, string T) {
        int szT = T.length();
        string a; string b;
        for(int i = 0; i < szT; i++)
        {
            if(S.find_first_of(T[i], 0) == -1)
            {
                b += T[i];
            }
            else{
                mpChar[T[i]]++;
            }
        }
        int szS = S.length();
        for(int i = 0; i < szS; i++)
        {
            int count = mpChar[S[i]];
            if(count > 0)
            {
                for(int j = 0; j < count; j++)
                {
                    a += S[i];
                }
            }
        }
        return a + b;
    }
};

int main() {
    
    return 0;
}