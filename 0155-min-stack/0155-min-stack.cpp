class MinStack {
public:
    stack<long long>s;
    long long mini=INT_MAX;
    //decode and store min values , within 1 stack
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            mini = val;
            s.push(val);
            return;
        }

        long long topVal = s.top();
        if(val < mini){
            //val < mini 
            //val - mini < 0 
            //(add val on both sides) 
            //2*val - mini < val 
            //(push modified val ==> 2*val - mini in stack
            long long modifiedVal = 2*(val*1LL) - mini;
            s.push(modifiedVal);
            mini = val;//update latest minimum
        }
        else{//val>=mini no need to update
            s.push(val);
        }
    }
    
    void pop() {
        if(s.empty())return; 
        long long topVal = s.top();
        s.pop();
        if(topVal<mini){
            //topVal < mini (means we stored modified value)
            // we stored modified value (2*val - Oldmini) in stack
            //topVal = 2*val - mini 
            //mini = 2*val - topVal (here val is our mini , as we updated mini = val , during push )
            mini = 2*mini - topVal;  
        }
    }
    
    int top() {
        if(s.empty())return -1;
        long long topVal = s.top();
        if(topVal<mini){//here we stored modified value
            return mini;
        }
        return topVal;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */