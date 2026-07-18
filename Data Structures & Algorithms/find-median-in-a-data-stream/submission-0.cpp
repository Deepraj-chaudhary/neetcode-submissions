class MedianFinder {
private:
    priority_queue <int> left;
    priority_queue <int,vector<int>,greater<int>> right;
    
public:
    MedianFinder() {
        }
    
    void addNum(int num) {
        if (left.size() == right.size()){
            double m = 0;
            if (left.size()!=0) m = (left.top()+right.top())/2.0;
            if (num < m) left.push(num);
            else right.push(num); 
        }
        else if (left.size() < right.size()){
            int m = right.top();
            if (num <= m) left.push(num);
            else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }
        else{
            int m = left.top();
            if (num >= m) right.push(num);
            else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()){
            if (left.size() == 0) return 0.0;
            return (left.top()+right.top())/2.0; 
        }
        else if (left.size() < right.size()){
            return right.top();
        }
        else{
            return left.top();
        }
    }
};
