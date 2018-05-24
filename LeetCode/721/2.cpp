#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> tree[1200];
    map<int, bool> mapVis;
    map<string ,bool> stringVis;
    vector<vector<string>> ret;

    void dfs(int u, vector<vector<string>>& accounts, vector<string>& ans) {
        if(mapVis[u]) return;
        mapVis[u] = true;

        int szStr = accounts[u - 1].size();
        for(int i = 1; i < szStr; i++) {
            if(!stringVis[accounts[u - 1][i]]){
                ans.push_back(accounts[u - 1][i]);
                stringVis[accounts[u - 1][i]] = true;
            }
        }

        int sz = tree[u].size();
        for(int i = 0; i < sz; i++) {
            int v = tree[u][i];
            dfs(v, accounts, ans);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int sz = accounts.size();
        int next[sz + 1];
        bool vis[sz + 1];
        mapVis.clear();

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
                        tree[i + 1].push_back(last);
                        tree[last].push_back(i + 1);            
                    }
                }
                mapAccount[accounts[i][j]] = i + 1;
            }
        }
        for(int i = 1; i <= sz; i++) {
            if(!mapVis[i]) {
                stringVis.clear();
                vector<string> cur;
                cur.push_back(accounts[i - 1][0]);
                dfs(i, accounts, cur);
                sort(cur.begin() + 1, cur.end());
                ret.push_back(cur);
            }
        }
        return ret;
    }
};