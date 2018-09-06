#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;

class MedianFinder {
public:
    int totalNum;
    int smallNum;
    int largeNum;
    int* small;
    /** initialize your data structure here. */
    MedianFinder() {
        totalNum = smallNum = largeNum = 0;
        small = new int[101];
        for(int i = 0; i <= 100; i++) {
            small[i] = 0;
        }
    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        
    }
};