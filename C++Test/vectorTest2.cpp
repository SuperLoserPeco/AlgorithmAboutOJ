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

typedef long long LL;

void funcTest(vector<int, int> vec);

int main() {
    vector<pair<int, int>> pairs;
    pairs.push_back(make_pair<int, int>(5, 4));
    set<pair<int, int>> pairsSet;
    pairsSet.insert(make_pair<int, int>(5, 4));
    if(pairsSet.find(make_pair<int, int>(5, 4)) != pairsSet.end())
    {
        pairsSet.insert(make_pair<int, int>(5, 5));
    }
    
    if(find(pairs.begin(), pairs.end(), make_pair<int, int>(5, 4)) != pairs.end())
    {
        pairs.push_back(make_pair<int, int>(4, 7));
    }
    // funcTest({make_pair<int, int>(1, 2)});
    return 0;
}

void funcTest(vector<pair<int, int>> vec)
{

}