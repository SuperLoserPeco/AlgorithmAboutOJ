#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

int main() {
    vector<int> abc;
    abc.push_back(13);
    abc.push_back(33);
    abc.push_back(33);
    abc.push_back(33);
    abc.push_back(33);
    abc.push_back(23);
    abc.push_back(43);
    sort(abc.begin(), abc.end());
    // int len = unique(abc.begin(), abc.end()) - abc.begin();
    abc.erase(unique(abc.begin(), abc.end()), abc.end());
    int len = abc.size();
    for(int i = 0; i < len; i++) {
        printf("%d\n", abc[i]);
        int locate = find(abc.begin(), abc.end(), abc[i]) - abc.begin();
        printf("%d\n", locate + 1);
    }
    printf("%d\n", abc.size());
    printf("%d\n", len);
}