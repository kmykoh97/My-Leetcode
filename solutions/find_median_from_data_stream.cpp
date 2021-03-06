// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

// For example,
// [2,3,4], the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:

// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
 

// Example:

// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
 

// Follow up:

// If all integer numbers from the stream are between 0 and 100, how would you optimize it?
// If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

// solution: heap

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int maxHeapSize = 0, minHeapSize = 0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeapSize == 0 || maxHeap.top() >= num) {
            maxHeap.push(num);
            ++maxHeapSize;

            if (maxHeapSize>minHeapSize+1) {
                int topItem = maxHeap.top();
                maxHeap.pop();
                minHeap.push(topItem);
                --maxHeapSize;
                ++minHeapSize;
            }
        } else {
            minHeap.push(num);
            ++minHeapSize;

            if (minHeapSize>maxHeapSize) {
                int topItem = minHeap.top();
                minHeap.pop();
                maxHeap.push(topItem);
                ++maxHeapSize;
                --minHeapSize;
            }
        }
    }
    
    double findMedian() {
        if (maxHeapSize == minHeapSize) return (1.0*(maxHeap.top() + minHeap.top()))/2;
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */