class MinStack {
private:
    stack<long> s;
    long min;
public:
    MinStack() {}
    
    void push(int val) {
        if(s.empty()){
            min = val;
            s.push(0);
        }
        else{
            s.push(val-min);
            if (val<min) min = val;
        }
    }
    
    void pop() {
        if (s.empty()) return;
        long top = s.top();
        if (top < 0){
            min = min - top;
        }
        s.pop();
        return;
    }
    
    int top() {
        long top = s.top();
        return (top > 0) ? top + min : min;
    }
    
    int getMin() {
        return (int)min;
    }
};
