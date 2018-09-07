#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;

//不行啊
//"2*3-4*5"
class Solution {
public:
int* val;
int* symbol;
bool* vis;
int* rightLocate;
int cnt;
    vector<int> diffWaysToCompute(string input) {
        int sz = input.length();
        val = new int[sz];
        symbol = new int[sz];
        vis = new bool[sz];
        rightLocate = new int[sz];

        int now = 0;
        cnt = 0;
        while(now < sz) {
            int curVal = 0;
            while(now < sz && 
                (input[now] >= '0' && input[now] <= '9')) {
                curVal *= 10;
                curVal += (input[now] - '0');
                now++;
            }
            val[cnt] = curVal;
            cout << "curVal = " << curVal << endl;
            if(now < sz) {
                switch(input[now]) {
                    case '+':
                    symbol[cnt] = 1;
                    break;
                    case '-':
                    symbol[cnt] = 2;
                    break;
                    case '*':
                    symbol[cnt] = 3;
                    break;
                    default:
                    cout << "error not exist at all" << endl;
                    break;
                }
                now++;
                cout << "symbol = " << symbol[cnt] << endl;
            }
            else {
                break;
            }
            cnt++;
        }
        for(int i = 0; i < cnt - 1; i++) vis[i] = false;
        for(int i = 0; i < cnt; i++) rightLocate[i] = i;
        dfs(1);

        vector<int> test;
        return test;
    }

    void dfs(int dep) {
        for(int i = 0; i < cnt - 1; i++) {
            if(vis[i]) continue;
            vis[i] = true;

            int left = val[i];
            int right = val[i + 1];
            int result;
            switch(symbol[i]) {
                case 1:
                result = left + right;
                break;
                case 2:
                result = left - right;
                break;
                case 3:
                result = left * right;
                break;
                default:
                    cout << "wo cao zenmehuizheyang" << endl;
                break;
            }

            if(dep >= cnt - 1) {
                cout << "result = " << val[i] << endl;
            }
            else {
                dfs(dep + 1);
            }

            val[i] = left;
            val[i + 1] = right;

            vis[i] = false;
        }
    }
};