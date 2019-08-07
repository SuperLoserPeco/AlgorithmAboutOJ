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
    int N, K;
    cin >> N >> K;
    vector<long long> num(N);
    long long sum = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sum = num[N - 1];
    vector<long long> chaSet;
    for(int i = 1; i < N; i++)
    {
        chaSet.push_back(num[i] - num[i - 1]);
    }
    sort(chaSet.begin(), chaSet.end());
    long long cha = 0;
    
    if(chaSet.size() != 0)
    {
        for(int i = N - 2; i >= N - K; i--)
        {
            cha += chaSet[i];
        }
    }
    cout << sum - cha - num[0];
    return 0;
}