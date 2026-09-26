class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string stack;
        backtrack(stack,n,0,0);
        return res;
    }
    void backtrack(string& stack,int n, int open,int close){
        if(open == n && close == n){
            res.push_back(stack);
            return;
        }
        if(open < n){
            stack+='(';
            backtrack(stack,n,open+1,close);
            stack.pop_back();
        }
        if(close < open){
            stack+=')';
            backtrack(stack,n,open,close+1);
            stack.pop_back();
        }
    }
};
