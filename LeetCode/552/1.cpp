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
    LL mod = 1e9 + 7;
    int checkRecord(int n) {
        vector<vector<vector<LL>>> vec(2, vector<vector<LL>>(2, vector<LL>(3)));
        int now = 0;
        LL ret = 0;
        vec[now][0][0] = 1;
        vec[now][0][1] = 1;
        vec[now][0][2] = 0;
        vec[now][1][0] = 1;
        vec[now][1][1] = 0;
        vec[now][1][2] = 0;
        for(int i = 1; i < n; i++)
        {
            int next = now ^ 1;
            for(int j = 0; j < 2; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    vec[next][j][k] = 0;
                }
            }
            vec[next][0][0] = (vec[now][0][0] + vec[now][0][1] + vec[now][0][2]) % mod;
            vec[next][0][1] = vec[now][0][0] % mod;
            vec[next][0][2] = vec[now][0][1] % mod;
            vec[next][1][0] = (vec[now][1][0] + vec[now][1][1] + vec[now][1][2]
                            + vec[now][0][0] + vec[now][0][1] + vec[now][0][2]) % mod;
            vec[next][1][1] = vec[now][1][0] % mod;
            vec[next][1][2] = vec[now][1][1] % mod;
            now = next;
        }
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                ret += vec[now][i][j];
                ret %= mod;
            }
        }
        return (int)ret;
    }
};

int main() {
    
    return 0;
}