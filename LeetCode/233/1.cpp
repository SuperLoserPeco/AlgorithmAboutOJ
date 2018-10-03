#include <vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) {
            return 0;
        }
        int temp = n;
        vector<int> vec;
        while(temp > 0) {
            vec.push_back(temp % 10);
            temp /= 10;
        }
        reverse(vec.begin(), vec.end());

        int sz = vec.size() + 2;

        int* num = new int[sz];
        int* num2 = new int[sz];

        num[0] = 10;
        for(int i = 1; i < sz; i++) {
            num[i] = num[i - 1] * 10;
        }
        num2[0] = 1;
        for(int i = 1; i < sz; i++) {
            num2[i] = 0;
            num2[i] += (num[i - 1]);
            num2[i] += (num2[i - 1] * 10);
        }

        int nsz = vec.size();
        int ans = 0;
        for(int i = 0; i < nsz - 1; i++) {
            int cur = nsz - i - 1 - 1;
            ans += (vec[i] * num2[cur]);
            cout << cur << endl;
            cout << vec[i] << endl;
            cout << num2[cur] << endl;
            if(vec[i] == 1) {
                int rest = 0;
                for(int j = i + 1; j < nsz; j++) {
                    rest *= 10;
                    rest += vec[j];
                }
                ans += (rest + 1);
                cout << "rest " << rest << endl;
            }
            else if(vec[i] > 1) {
                ans += (num[cur]);
                cout << "ans += (num[cur]); " << cur << "---" << num[cur] << endl;
            }
        }
        if(vec[nsz - 1] >= 1) {
            ans++;
        }
        return ans;
    }
};