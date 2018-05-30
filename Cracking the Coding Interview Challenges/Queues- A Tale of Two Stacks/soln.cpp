#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
    
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
       
           //First element -> can directly push to the stack_oldest_on_top to save 1 move op later.
            if(stack_newest_on_top.empty()&& stack_oldest_on_top.empty()) 
            {
                stack_oldest_on_top.push(x);
            }
            // All other cases we push to the stack_newest_on_top stack
            else{
                stack_newest_on_top.push(x);
            }
        }

        void pop() {
            
            if(!stack_oldest_on_top.empty())
            {
              // We need to remove the oldest element first. This is why keeping stack_oldest_on_top is useful.
              stack_oldest_on_top.pop();
            }
            // When the stack that stores the oldest one becomes empty, we need to move all the elements from the other 
            // At the end of this op, the order of the queue remains stable while maintaining the same property of the two stacks.
            if(stack_oldest_on_top.empty())
            {
                while(!stack_newest_on_top.empty())
                {
                    int x = stack_newest_on_top.top();
                    stack_newest_on_top.pop();
                    stack_oldest_on_top.push(x);
                }
            }
        }
        // simply read the top of the stack that stores the oldest element on top... 
        int front() {
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    return 0;
}
