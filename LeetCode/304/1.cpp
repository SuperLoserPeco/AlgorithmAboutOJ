#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> matrixs;
    NumMatrix(vector<vector<int>> matrix) {
        int sz = matrix.size();
        if(sz == 0)
        {
            return;
        }
        int szY = matrix[0].size();
        vector<int> blank;
        for(int i = 0; i < szY + 1; i++)
        {
            blank.push_back(0);
        }
        matrixs.push_back(blank);
        for(int i = 0; i < sz; i++)
        {
            vector<int> vec;
            vec.push_back(0);
            for(int j = 0; j < szY; j++)
            {
                vec.push_back(matrix[i][j]);
                vec[j + 1] += vec[j];
            }
            for(int j = 0; j < szY; j++)
            {
                vec[j + 1] += matrixs[i][j + 1];
            }
            matrixs.push_back(vec);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrixs[row2 + 1][col2 + 1] 
        - matrixs[row2 + 1][col1]
        - matrixs[row1][col2 + 1]
        + matrixs[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */