/*
Title:
    232. Implement Queue using Stacks
    232. 用栈实现队列
Address:
    https://leetcode-cn.com/problems/implement-queue-using-stacks/
*/

#include <iostream>
#include <stack>
using namespace std;

// 方法二：使用一个栈
class MyQueue_2 {
private:
    stack<int> S;
public:
    /** Initialize your data structure here. */
    MyQueue_2() {  }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp_S;
        while ( !S.empty() ) {
            temp_S.push( S.top() );
            S.pop();
        }
        temp_S.push( x );
        while ( !temp_S.empty() ) {
            S.push( temp_S.top() );
            temp_S.pop();    
        }        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = S.top();
        S.pop();

        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return S.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return S.empty();
    }
};

// 方法一：使用两个栈交替工作
class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {  }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push( x );
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = peek();
        stack2.pop();

        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if ( stack2.empty() ) {
            while ( !stack1.empty() ) {
                stack2.push( stack1.top() );
                stack1.pop();
            }
        }
        
        return stack2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if ( stack1.empty() && stack2.empty() )
            return true;
        
        return false;
    }
};


int main()
{
    

    return 0;
}