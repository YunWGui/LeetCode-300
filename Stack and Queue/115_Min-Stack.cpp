/*
    155. Min Stack
*/

#include <iostream>
#include <stack>
using namespace std;

// 方法三：使用「链表」
struct Node {
    int val;
    int min;
    Node* next;
    Node( int x = 0, int y = 0 ) : val( x ), next( NULL ), min( y ) { }
};

struct Head {
    Node* first;
    Head(): first( NULL ) { }
};

class MinStack_3 {
public:
    Head* head = new Head();

    MinStack_3() {    }
    
    void push(int x) {
        Node* temp = new Node( x, x );
        if ( head->first && head->first->min < x )
            temp->min = head->first->min;
        
        temp->next = head->first;
        head->first = temp;
    }
    
    void pop() {
        Node* temp = head->first;
        head->first = temp->next;
        temp->next = NULL;
    }
    
    int top() {
        return head->first->val;
    }
    
    int getMin() {
        return head->first->min;
    }
};

// 方法一：使用「栈」
class MinStack {
private:
    stack<int> stackValue;
    stack<int> stackMin;
public:
    /** initialize your data structure here. */
    MinStack() {    }
    
    void push(int x) {
        if ( stackMin.empty() || stackMin.top() >= x )
            stackMin.push( x );
        
        stackValue.push( x );
    }
    
    void pop() {
        if ( stackMin.top() == stackValue.top() )
            stackMin.pop();
        
        stackValue.pop();
    }
    
    int top() {
        return stackValue.top();
    }
    
    int getMin() {
        return stackMin.top();
    }
};

// 方法二：使用「栈」
class MinStack_2 {
private:
    stack<int> stackValue;
    stack<int> stackMin;
public:
    /** initialize your data structure here. */
    MinStack_2() {

    }
    
    void push(int x) {
        stackValue.push( x );
        if ( stackMin.empty() )
            stackMin.push( x );
        else {
            int temp = stackMin.top();
            stackMin.push( temp > x ? x : temp );
        }
    }
    
    void pop() {
        stackValue.pop();
        stackMin.pop();
    }
    
    int top() {
        return stackValue.top();
    }
    
    int getMin() {
        return stackMin.top();
    }
};



int main()
{
    

    return 0;
}