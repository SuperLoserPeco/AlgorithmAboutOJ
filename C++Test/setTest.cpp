#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <map>
#include <set>


#include <algorithm>
using namespace std;

int main() 
{
    set<string> st;
    while(true) {
        string temp;
        cin >> temp;
        st.insert(temp);
        for(set<string>::iterator iter =st.begin(); iter != st.end(); iter++)
        {
            cout << *iter << endl;
        }
    }
}