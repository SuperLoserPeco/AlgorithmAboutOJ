#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int state = 3;
    cout << ~state << endl;

    int hehe = ~state;
    int cnt = 0;
    while(hehe) {
        cout << cnt << " locate =  " << ((hehe & 1) ? "one" : "zero") << endl;
        hehe >>= 1;
        cout << hehe << endl;
        cnt++;
        if(cnt > 10) break;
    }

    cout << -state << endl;
}