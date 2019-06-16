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
using namespace std;

typedef long long LL;

int main() {
    //升序队列
    priority_queue <int,vector<int>,greater<int> > q1;
    
    q1.push(5);
    q1.push(4);
    q1.push(6);
    find(q1.begin(), q1.end(), 6);
    cout << q1.top() << endl;
    q1.pop();
//降序队列
    priority_queue <int,vector<int>,less<int> >q2;
    return 0;
}