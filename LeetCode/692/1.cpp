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

class Solution {
public:
    bool static cmp(pair<int, int> a, pair<int, int> b)
    {
        if(a.first != b.first)
        {
            return a.first > b.first;
        }
        else{
            return a.second < b.second;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        vector<string> ret;
            
        int currentCnt = 1;
        int sz = words.size();
        vector<pair<int, int>> result;
        for(int i = 0; i < sz; i++)
        {
            if(i)
            {
                if(isSame(words[i], words[i - 1]))
                {
                    currentCnt++;
                }
                else{
                    currentCnt = 1;
                }
            }
            if(i == sz - 1 || 
                !isSame(words[i], words[i + 1]))
                {
                    pair<int, int> pr = make_pair<int, int>((int)currentCnt, (int)i);
                    result.push_back(pr);
                }
        }
        sort(result.begin(), result.end(), cmp);
        for(int i = 0; i < k; i++)
        {
            ret.push_back(words[result[i].second]);
        }
        return ret;
    }

    bool isSame(string& a, string& b)
    {
        if(a.length() != b.length())
        {
            return false;
        }
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}