#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

//我感觉不行

int main() {
    LL n, m, k;

    bool isEven = false;

    cin >> n >> m >> k;

    if((2 * n * m) % k != 0) {
        cout << "NO";
        return 0;
    }
    if(k % 2 == 0) {
        k /= 2;
        isEven = true;
    }

    LL g = gcd(k, n);

    LL a, b, c;
    c = k / g;
    a = n / g;
    b = m / c;

    if(!isEven) {
        if(b < m) {
            b *= 2;
        }
        else {
            a *= 2;
        }
        // if(2 * a <= n) {
        //     a *= 2;
        // }
        // else {
        //     b *= 2;
        // }
    }

    cout << "YES" << endl;
    cout << "0 0" << endl;
    cout << a << " 0" << endl;
    cout << "0 " << b << endl;
    return 0;
}