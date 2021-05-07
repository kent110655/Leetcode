class MinStack {
private:
    stack<int> DataS;
    stack<int> MinS;
    int minVal;
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        DataS.push(val);
        minVal = min(minVal, val);
        MinS.push(minVal);
    }
    
    void pop() {
        DataS.pop();
        MinS.pop();
        minVal = (MinS.empty()) ? INT_MAX : MinS.top();
    }
    
    int top() {
        return DataS.top();
    }
    
    int getMin() {
        return MinS.top();
    }
};
/*
Comment:
利用兩個Stack來做實作MinStack
DataStack: 存放正常的data
MinStack: 存放每階段的最小值
push時，MinStack同時push入此時的最小值。
pop時，MinStack同時pop掉之前的最小值，且更新minVal成上一個最小值(空時為INT_MAX)
getMin回傳MinStack的top即可。
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
