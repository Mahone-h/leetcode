//
// Created by Mahone on 2021/8/20.
//
#include <stack>

using namespace std;
class Solution{
public:
    /**
     * 输入栈和输出栈
     *
     * 在push数据的时候，只要数据放进输入栈就好，
     * 但在pop的时候，操作就复杂一些，输出栈如果为空，就把进栈数据全部导入进来（注意是全部导入），
     * 再从出栈弹出数据，
     * 如果输出栈不为空，则直接从出栈弹出数据就可以了。
     * 最后如何判断队列为空呢？如果进栈和出栈都为空的话，说明模拟的队列为空了。
     * @param node
     */
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