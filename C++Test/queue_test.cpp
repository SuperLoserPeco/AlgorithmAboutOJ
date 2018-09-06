#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;

int main() {
    cout << "wocao" << endl;
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    cout << "wocao" << endl;
    cout << Q.front() << endl; //1
    Q.pop();
    cout << Q.front() << endl; //2
    Q.pop();
    cout << Q.front() << endl; //3
    Q.pop();
    while(1);
}