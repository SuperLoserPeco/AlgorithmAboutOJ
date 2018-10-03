#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int sz = B.size();
        int** store = new int*[sz];
        for(int i = 0; i < sz; i++) {
            store[i] = new int[26];
            for(int j = 0; j < 26; j++)
            {
                store[i][j] = 0;
            }
        }

        int storeB[26];
        for(int i = 0; i < 26; i++) {
            storeB[i] = 0;
        }
        for(int i = 0; i < sz; i++)
        {
            int storeTemp[26];
            for(int j = 0; j < 26; j++) {
                storeTemp[j] = 0;
            }
            for(int j = 0; j < B[i].length(); j++) {
                storeTemp[B[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                storeB[j] = storeB[j] > storeTemp[j] ? storeB[j] : storeTemp[j];
            }
        }

        vector<string> res;

        int szA = A.size();
        for(int i = 0; i < szA; i++)
        {
            int storeA[26];
            for(int j = 0; j < 26; j++) {
                storeA[j] = 0;
            }
            for(int j = 0; j < A[i].length(); j++) {
                storeA[A[i][j] - 'a']++;
            }

            bool flag = true;
            for(int j = 0; j < 26; j++) {
                if(storeA[j] < storeB[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res.push_back(A[i]);
            }
        }

        return res;
    }
};