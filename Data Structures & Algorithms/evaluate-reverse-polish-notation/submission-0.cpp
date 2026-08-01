class Solution {
public:
    int evalRPN(vector<string>& tokens) {
          stack<int> stack;
        
        for(string t : tokens){
            if(t == "/"){
                int rhs = stack.top();
                stack.pop();
                int lhs = stack.top();
                stack.pop();
                stack.push(lhs/rhs);
            }
            else if(t == "+"){
                int rhs = stack.top();
                stack.pop();
                int lhs = stack.top();
                stack.pop();
                stack.push(lhs+rhs);
            }
             else if(t == "*"){
                int rhs = stack.top();
                stack.pop();
                int lhs = stack.top();
                stack.pop();
                stack.push(lhs*rhs);
            }
                
            
             else if(t == "-"){
                int rhs = stack.top();
                stack.pop();
                int lhs = stack.top();
                stack.pop();
                stack.push(lhs-rhs);
            }
            else{
                stack.push(stoi(t));
            }
        }
        return stack.top();
  
    }
};
