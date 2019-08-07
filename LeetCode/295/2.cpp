#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> bigHeap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        topAdd(num);
        topSwap();
    }
    
    double findMedian() {
        if(bigHeap.size() > smallHeap.size())
        {
            return bigHeap.top();
        }
        else{
            return ((double)bigHeap.top() + (double)smallHeap.top()) / 2;
        }
    }

private:
    void topSwap()
    {
        if(smallHeap.size() <= 0 || bigHeap.size() <= 0)
        {
            return;
        }
        if(smallHeap.top() > bigHeap.top())
        {
            smallHeap.push(bigHeap.top());
            bigHeap.push(smallHeap.top());
            smallHeap.pop();
            bigHeap.pop();
        }
    }

    void topAdd(int num)
    {
        if(smallHeap.size() != bigHeap.size())
        {
            smallHeap.push(bigHeap.top());
            bigHeap.pop();
        }
        bigHeap.push(num);
    }
};

int main()
{

}