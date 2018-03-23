#include <iostream>
#include <cstring>
using namespace std;

const int node_num = 10;
const int tree_size = (2 << node_num) + 1;
char seq[node_num];
int treeA[tree_size];
int treeB[tree_size];

int main() {
    int n;
    while( cin >> n ) {
        if(n == 0) break;
        cin >> seq;
        memset(treeA, -1, sizeof(treeA));
        for(int i = 0; seq[i]; i++) {
            int num = seq[i] - '0';
            int j = 1;
            while(treeA[j] != -1) {
                if(num <= treeA[j]) {
                    j = j * 2;
                }
                else {
                    j = j * 2 + 1;
                }
            }
            treeA[j] = num;
        }
        while(n--) {
            cin >> seq;
            memset(treeB, -1, sizeof(treeB));
            for(int i = 0; seq[i]; i++) {
                int num = seq[i] - '0';
                int j = 1;
                while(treeB[j] != -1) {
                    if(num <= treeB[j]) {
                        j = j * 2;
                    }
                    else {
                        j = j * 2 + 1;
                    }
                }
                treeB[j] = num;
            }
            
            int i;
            for(i = 0; i < tree_size && treeA[i] == treeB[i]; i++);
            cout << ((i >= tree_size) ? "YES" : "NO") << endl;
        }
    }
}