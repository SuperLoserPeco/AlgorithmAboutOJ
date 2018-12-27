#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> hash;
        for(int i = 0; i < row.size(); i++) {
            hash[row[i]] = i;
        }

        int count = 0;
        for(int i = 0; i < row.size(); i+=2) {
            // for(int j = 0; j < row.size(); j++) {
            //     cout << " " << row[j];
            // }
            // cout << endl;
            // for(int j = 0; j < row.size(); j++) {
            //     cout << " " << hash[j];
            // }
            // cout << endl;
            int locateA = hash[i];
            int locateB = locateA ^ 1;
            // cout << locateA <<  "  " << locateB << endl;
            int locateOther = hash[i + 1];
            int valOther = row[locateB];
            if(locateB == locateOther) {
                continue;
            }
            else{
                count++;
                swap(row[locateB], row[locateOther]);
                int temp = hash[i+1];
                hash[i + 1] = hash[valOther];
                hash[valOther] = temp;
            }
        }
        return count;
    }
};