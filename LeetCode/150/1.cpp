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
#include <unordered_map>
using namespace std;

typedef long long LL;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        while(tokens.size() > 1)
        {
            int sz = tokens.size();
            int i;
            for(i = 0; i < sz; i++)
            {
                if(isAumetic(tokens[i]))
                {
                    if(i < 2)
                    {
                        return -1;
                    }
                    int a = atoi(tokens[i - 2].c_str());
                    int b = atoi(tokens[i - 1].c_str());

                    switch(tokens[i][0])
                    {
                        case '+':
                        {
                            tokens[i - 2] = to_string(a + b);
                            break;
                        }
                        case '-':
                        {
                            tokens[i - 2] = to_string(a - b);
                            break;
                        }
                        case '*':
                        {
                            tokens[i - 2] = to_string(a * b);
                            break;
                        }
                        case '/':
                        {
                            tokens[i - 2] = to_string(a / b);
                            break;
                        }
                        default:
                        {
                            return -1;
                        }
                    }
                    tokens.erase(tokens.begin() + i - 1, tokens.begin() + i + 1);

                    break;
                }
            }
        }
        return atoi(tokens[0].c_str());
    }

    bool isAumetic(string&  c)
    {
        return (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/') && (c.length() == 1);
    }
};

int main() {
    
    return 0;
}