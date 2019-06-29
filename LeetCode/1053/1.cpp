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
    vector<int> prevPermOpt1(vector<int>& A) {
        bool exist = false;

        int locateA;
        int sz = A.size();
        for(int i = sz - 2; i >= 0; i--)
        {
            if(A[i] > A[i + 1])
            {
                exist = true;
                locateA = i;
                break;
            }
        }

        if(!exist)
        {
            return A;
        }

        int locateB = locateA + 1;
        for(int i = locateB + 1; i < sz; i++)
        {
            if(A[i] > A[locateB] && A[i] < A[locateA])
            {
                locateB = i;
            }
        }

        int temp = A[locateA];
        A[locateA] = A[locateB];
        A[locateB] = temp;
        return A;
    }
};

int main() {
    
    return 0;
}