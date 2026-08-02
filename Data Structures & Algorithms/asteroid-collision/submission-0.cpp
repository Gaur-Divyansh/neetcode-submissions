class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for(int a : asteroids){
            bool destroyed  = false;
            while(!stack.empty() && a < 0 && stack.back() > 0){
                if(-1*a > stack.back()) stack.pop_back();
                else if(-1*a < stack.back()){
                    destroyed = true;
                    break;
                }
                else{
                    stack.pop_back();
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) stack.push_back(a);
        }
        return stack;
    }
};