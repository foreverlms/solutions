#include <stack>
#include <iostream>

using namespace std;

// class Solution
// {
// public:
        /**
         * 这种每次都得移空其中一个栈
         */
//     void push(int node) {
//         while (!stack2.empty())
//         {
//             stack1.push(stack2.top());
//             stack2.pop();
//         }
        

//         stack1.push(node);
//     }

//     int pop() {
//         while (!stack1.empty())
//         {
//             stack2.push(stack1.top());
//             stack1.pop();
//         }
        
//         int tmp = stack2.top();
//         stack2.pop();
//         return tmp;
//     }

// private:
//     //进栈
//     stack<int> stack1;
//     //出栈
//     stack<int> stack2;
// };

class Solution
{
public:
    /**
     * 这种就比较省时
     */
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size() <= 0){
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            
        }

        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};