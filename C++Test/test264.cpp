#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    for(int i = 2; i < INT_MAX; i++)
    {
        int cur = i;
        while(cur % 2 == 0) cur /= 2;
        while(cur % 3 == 0) cur /= 3;
        while(cur % 5 == 0) cur /= 5;
        if(cur == 1)
        {
            cnt++;
        }
        if(cnt == 1690)
        {
            cout <<"num = " << i << endl;
            break;
        }
    }
    cout << "cnt = " << cnt << endl;
    return 0;
}