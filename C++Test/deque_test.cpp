#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;

int main() {
    deque<int> Q;
    map<int, int> mp;

    Q.push_back(1);
    Q.push_back(2);
    cout << Q.front() << endl;
    Q.pop_front();
    cout << Q.front() << endl;
    Q.pop_front();
}