//
// Created by Mahone on 2021/8/20.
//
#include <stack>

using namespace std;
class Solution
        {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }
    int peek(){
        int res=this->pop();
        stack2.push(res);
        return res;
    }

    bool empty(){
        return stack1.empty() && stack2.empty();
    }

private:
    stack<int> stack1; //in
    stack<int> stack2; //out
};