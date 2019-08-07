#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        int h = 0;
        for(int i = sz - 1; i >= 0; i--)
        {
            if(h + 1 <= citations[i])
            {
                h++;
            }
            else{
                break;
            }
        }
        return h;
    }
};

int main() {
    Solution s;
    vector<int> param = {0, 1, 3, 5, 6};
    cout << s.hIndex(param);
    return 0;
}