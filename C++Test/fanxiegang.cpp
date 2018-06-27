#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main() {
    string a = "aaa\n";
    string b = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int sz2 = b.length();
    for(int i = 0; i < sz2; i++) {
        cout << i << "---" << b[i] << endl;
    }
    int sz = a.length();
    for(int i = 0; i < sz; i++) {
        cout << i << "---" << a[i] << endl;
    }
}