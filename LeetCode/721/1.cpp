#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int sz = accounts.size();
        int next[sz + 1];
        bool vis[sz + 1];
        for(int i = 0; i <= sz; i++){
            next[i] = -1;
            vis[i] = false;
        }
        map<int, string> mapName;
        map<string, int> mapAccount;
        for(int i = 0; i < sz; i++) {
            int szStr = accounts[i].size();
            mapName[i + 1] = accounts[i][0];
            for(int j = 1; j < szStr; j++) {
                if (mapAccount[accounts[i][j]] != 0) {
                    int last = mapAccount[accounts[i][j]];
                    if(last != i + 1) {
                        int fiLast = last;
                        while(next[fiLast] != -1 && next[fiLast] < i + 1) 
                            fiLast = next[fiLast];

                        next[fiLast] = i + 1;                        
                    }
                }
                mapAccount[accounts[i][j]] = i + 1;
            }
        }

        vector<vector<string>> ret;
        map<string, int> visName;
        for(int i = 0; i < sz; i++) {
            if(vis[i + 1]) continue;
            visName.clear();
            vector<string> cur;

            int sz = accounts[i].size();
            cur.push_back(accounts[i][0]);
            for(int j = 1; j < sz; j++) {
                if(visName[accounts[i][j]] == 0) {
                    visName[accounts[i][j]] = 1;
                    cur.push_back(accounts[i][j]);
                }
            }

            int now = i + 1;
            while((now = next[now]) != -1){
                vis[now] = true;
                int sz = accounts[now - 1].size();
                for(int j = 1; j < sz; j++) {
                    if(visName[accounts[now - 1][j]] == 0) {
                        visName[accounts[now - 1][j]] = 1;
                        cur.push_back(accounts[now - 1][j]);
                    }
                }
            }
            sort(cur.begin() + 1, cur.end());
            ret.push_back(cur);
        }
        return ret;
    }
};