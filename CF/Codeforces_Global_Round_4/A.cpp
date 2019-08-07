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


int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += nums[i];
    }
    vector<int> ids;
    int currentSum = nums[0];

    bool flag = currentSum * 2 > sum;
    for(int i = 1; i < N; i++)
    {
        if(nums[i] * 2 <= nums[0])
        {
            currentSum += nums[i];
            ids.push_back(i + 1);

            if(currentSum * 2 > sum)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag)
    {
        cout << ids.size() + 1 << endl;
        cout << 1;
        for(int i = 0; i < ids.size(); i++)
        {
            cout << " " << ids[i];
        }
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}