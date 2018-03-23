//cur state

#include <iostream>
#include <cstring>
using namespace std;

const int node_num = 10;
const int tree_size = (2 << node_num) + 1;
char seq[node_num];
int treeA[tree_size];
int treeB[tree_size];

void generateTree(char* seq, int* tree) {
    memset(tree, -1, sizeof(tree));

    for(int i = 0; seq[i]; i++) {
        int num = seq[i] - '0';
        int j = 1;
        while(tree[j] != -1) {
            if(num <= tree[j]) {
                j = j * 2;
            }
            else {
                j = j * 2 + 1;
            }
        }
        tree[j] = num;
    }
}

int main() {
    int n;
    while( cin >> n ) {
        if(n == 0) break;
        cin >> seq;
        generateTree(seq, treeA);
        while(n--) {
            cin >> seq;
            generateTree(seq, treeB);
            
            int i;
            for(i = 0; i < tree_size && treeA[i] == treeB[i]; i++);
            cout << ((i >= tree_size) ? "YES" : "NO") << endl;
        }
    }
}