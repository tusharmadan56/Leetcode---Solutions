class MedianFinder {
public:
    priority_queue<int> pq1,pq2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq1.push(num);
        pq2.push(-pq1.top());
        pq1.pop();
        int a = pq1.size();
        int b = pq2.size();



        if(b>a){
            int f = pq2.top();
            pq2.pop();
            cout<<f<<endl;
            pq1.push(-f);
        }

        
    }
    
    double findMedian() {
        int sz = pq1.size()+pq2.size();

        if(sz%2){
            return 1.0*pq1.top();
        }
        return (1.0*pq1.top()-1.0*pq2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */