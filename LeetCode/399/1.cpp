#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> unionset;

    struct Node {
        int j;
        double val;
    };
    vector<Node> vec[100000];
    map<string, int> mp;
    map<int, bool> vis;

    int find(int a) {
        return unionset[a] == a ? a : find(unionset[a]);
    }

    bool flag;
    double dfs(int cur, int st, int ed) {
        double ans = 1.0;
        if(cur == ed) {
            flag = true;
            return ans = 1.0;
        }
        int sz = vec[cur].size();
        for(int i = 0; i < sz; i++) {
            int v = vec[cur][i].j;
            if(!vis[v]) {
                vis[v] = true;
                double ans = vec[cur][i].val * dfs(v, st, ed);
                vis[v] = false;
                if(flag) return ans;
            }
            
        }
        return ans;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int sz = equations.size();
        unionset.push_back(0);

        for(int i = 1; i <= sz * 2; i++) unionset.push_back(i);

        int cnt = 0;
        for(int i = 0; i < sz; i++) {
            string s1 = equations[i].first;
            string s2 = equations[i].second;
            if(mp[s1] == 0) mp[s1] = ++cnt;
            if(mp[s2] == 0) mp[s2] = ++cnt;
            unionset[find(mp[s1])] = find(mp[s2]);
            Node v;
            v.j = mp[s2];
            v.val = values[i];
            vec[mp[s1]].push_back(v);
            v.j = mp[s1];
            v.val = 1.0 / values[i];
            vec[mp[s2]].push_back(v);
        }

        int qsz = queries.size();
        vector<double> ret;
        for(int i = 0; i < qsz; i++) {
            vis.clear(); flag = false;
            if(mp[queries[i].first] == 0 || mp[queries[i].second] == 0) {
                cout << " no " << endl;
                ret.push_back(-1);
            }
            else if(find(mp[queries[i].first]) != find(mp[queries[i].second])) {
                cout << " not together " << endl;
                ret.push_back(-1);
            }
            else {
                cout << " search " << endl;
                int u = mp[queries[i].first]; int v = mp[queries[i].second];
                
                vis[u] = true;
                double ans = dfs(u, u, v);
                if(flag) ret.push_back(ans);
                else ret.push_back(-1);
            }
        }
        return ret;
    }
};