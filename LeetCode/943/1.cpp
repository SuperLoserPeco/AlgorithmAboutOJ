/////
// https://www.acwing.com/solution/leetcode/content/611/
/////
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
    int calc(const string& x, const string& y)
    {
        int n = x.length();
        int m = y.length();
        for(int k = 0; k < n; k++)
        {
            bool flag = true;
            for(int i = k, j = 0; i < n && j < m; i++, j++)
            {
                if(x[i] != y[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                return n-k;
            }
        }
        return 0;
    }

    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> f(1 << n, vector<int>(n, 1000));
        vector<vector<int>> p(1 << n, vector<int>(n, -1));
        vector<vector<int>> tr(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            tr[i][j] = calc(A[i], A[j]);
        }

        for(int i = 0; i < n; i++)
        {
            f[1 << i][i] = A[i].length();
        }

        for(int S = 0; S < (1 << n); S++)
        {
            for(int i = 0; i < n; i++)
            {
                if(S & (1 << i))
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(!(S & (1 << j)))
                        {
                            if(f[S | (1 << j)][j] > f[S][i] + A[j].length() - tr[i][j]) {
                                f[S | (1 << j)][j] = f[S][i] + A[j].length() - tr[i][j];
                                p[S | (1 << j)][j] = i;
                            }
                        }
                    }
                }
            }
        }

        int ansMx = 1000, k = -1;
        for(int i = 0; i < n; i++) {
            if(ansMx > f[(1 << n) - 1][i]) {
                ansMx = f[(1 << n) - 1][i];
                k = i;
            }
        }

        string str = string(ansMx, ' ');
        int S = (1 << n) - 1, pos = ansMx;
        while(1) {
            for(int i = pos - A[k].length(), j = 0; 
                        i < pos && j < A[k].length(); 
                        i++, j++) {
                str[i] = A[k][j];
            }
            if(p[S][k] == -1) {
                break;
            }
            pos = pos - A[k].length() + tr[p[S][k]][k];
            int newK = p[S][k];
            S = S - (1 << k);
            k = newK;
        }
        return str;
    }
};