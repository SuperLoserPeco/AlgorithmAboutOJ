#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;

int main() {
    deque<int> Q;
    for(int i = 0; i < 10; i++)
        Q.push_back(i);
    for(int i = 0; i < 10; i++) {
        if(i == 5) {
            Q.erase(Q.begin() + i);
        }
    }
    for(int i = 0; i < Q.size(); i++) {
        cout << Q[i] << endl;
    }
    // Q.push_back(2);
}