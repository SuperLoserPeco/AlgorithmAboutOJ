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

int main() {
    priority_queue<int, vector<int>, greater<int>> test1;
    priority_queue<int, vector<int>, less<int>> test2;
    test1.push(1);
    test1.push(2);
    test1.push(3);
    cout << test1.top() << endl;
    return 0;
}