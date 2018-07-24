#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    vector<int> num_vec;
    num_vec.push_back(1);
    num_vec.push_back(3);
    num_vec.push_back(5);
    num_vec.push_back(5);
    num_vec.push_back(6);
    num_vec.push_back(5);
    num_vec.push_back(5);
    num_vec.push_back(5);
    num_vec.push_back(5);
    num_vec.push_back(9);


    cout << num_vec.size() << endl;
    for (int i=0; i<num_vec.size(); i++)
    {
        cout << "---" << i << endl;
        if (num_vec[i] == 5)
        {
            num_vec.erase(num_vec.begin()+i);
        }
    }
}