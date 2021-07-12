class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>pqfirst,pqsecond;
    MedianFinder() {
        while(pqfirst.size()) pqfirst.pop();
        while(pqsecond.size()) pqsecond.pop();
    }
    
    void addNum(int num) {
        pqfirst.push(num);
        pqsecond.push(-pqfirst.top());
        pqfirst.pop();
        if(pqfirst.size()<pqsecond.size())
        {
            pqfirst.push(-pqsecond.top());
            pqsecond.pop();
        }
    }
    
    double findMedian() {
        if(pqfirst.size()==pqsecond.size()) return (double)(pqfirst.top()-pqsecond.top())/(double)(2);
        else if(pqfirst.size()>pqsecond.size()) return pqfirst.top();
        else return -pqsecond.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */