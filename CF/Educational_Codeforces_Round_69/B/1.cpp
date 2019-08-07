#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> num(N);
    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int mxLocate = 0;
    int mxValue = num[0];
    for(int i = 1; i < N; i++)
    {
        if(num[i] > mxValue)
        {
            mxValue = num[i];
            mxLocate = i;
        }
    }
    int l = mxLocate - 1;
    int r = mxLocate + 1;
    int lastMaxValue = mxValue;
    while(l >= 0 || r < N)
    {
        if(l >= 0 && r < N)
        {
            if(num[l] > num[r])
            {
                if(num[l] > lastMaxValue)
                {
                    cout << "NO";
                    return 0;
                }
                else{
                    lastMaxValue = num[l];
                    l--;
                }
            }
            else{
                if(num[r] > lastMaxValue)
                {
                    cout << "NO";
                    return 0;
                }
                else{
                    lastMaxValue = num[r];
                    r++;
                }
            }
        }
        else if(l >= 0)
        {
            if(num[l] > lastMaxValue)
            {
                cout << "NO";
                return 0;
            }
            else{
                lastMaxValue = num[l];
                l--;
            }
        }
        else if(r < N)
        {
            if(num[r] > lastMaxValue)
            {
                cout << "NO";
                return 0;
            }
            else{
                lastMaxValue = num[r];
                r++;
            }
        }
    }
    cout << "YES";
    return 0;
}   