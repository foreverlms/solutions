#include <stack>

using namespace std;

class MinStack
{
public:
    MinStack() {}
    void push(int x)
    {
        dataStack.push(x);
        if (minStack.empty())
        {
            minStack.push(x);
            return;
        }
        
        int min = minStack.top();
        //保证minStack栈顶的值始终不仅是当前最小还是没有压入x之前的值
        if (min < x)
        {
            minStack.push(min);
        }else{
            minStack.push(x);
        }
        
    }

    void pop()
    {
        
        dataStack.pop();
        minStack.pop();
    }

    int top()
    {
        return dataStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }

protected:
  //两个栈，一个栈用来存储数据，一个用来存最小值
  stack<int> dataStack;
  stack<int> minStack;
};
