#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

int a[20];

int main() {
    for(int i = 1; i < 20; i++)
        a[i] = i * 2;
    int c = find(a, a + 20, 5) - a;
    printf("%d", c);
}