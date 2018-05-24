#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:

    int monotoneIncreasingDigits(int N) {
        int num[20];
        int origin = N, cnt = 0;
        while(origin) {
            num[cnt++] = origin % 10;
            origin /= 10;
        }
        for(int i = 0; i < cnt / 2; i++)
            swap(num[i], num[cnt - i - 1]);
        for(int i = 0; i < cnt - 1; i++){
            if( num[i] >= num[i + 1]) {
                
            }
        }
    }
};