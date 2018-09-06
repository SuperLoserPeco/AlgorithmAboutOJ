#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>

#include <sstream>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int pool[10];
        for(int i = 0; i < 10; i++)
            pool[i] = 0;
        string ret = "";
        string ret2 = "";
        for(int i = 0; i < secret.length(); i++) {
            pool[secret[i] - '0']++;
        }
        int A = 0, B = 0;
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                cout << "---" << i << endl;
                cout << "---" << A << endl;
                A++;
                cout << "---" << i << endl;
                cout << "---" << A << endl;
                pool[secret[i] - '0']--;
            }
        }
        cout << A << endl;

        for(int i = 0; i < guess.length(); i++) {
            if(secret[i] != guess[i]) {
                
            if(pool[guess[i] - '0'] > 0) {
                pool[guess[i] - '0'] -= 1;
                B++;
            }
            }
        }
        
        stringstream ss, ss2;
        ss << A;
        ss >> ret;//或者 res = ss.str();
        ret = ret + "A";
        cout << A << endl;
        cout << ret << endl;
        ss2 << B;
        ss2 >> ret2;
        ret2 = ret2 + "B";
        cout << ret2 << endl;
        return ret + ret2;  
    }
};