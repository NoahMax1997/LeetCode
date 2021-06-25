#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> m_stack,m_min_stack;
    MinStack() {

    }
    
    void push(int val) {
        m_stack.push(val);
        if (m_min_stack.empty()||m_min_stack.top()>=val)
        {
            m_min_stack.push(val);
        }
    }
    
    void pop() {
        int tmp = m_stack.top();
        m_stack.pop();
        if (m_min_stack.top() == tmp)
        {
            m_min_stack.pop();
        }
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_min_stack.top();
    }
};
int main (){
		
	return 0;
}
