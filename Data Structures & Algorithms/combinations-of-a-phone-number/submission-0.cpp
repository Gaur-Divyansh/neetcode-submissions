class Solution {
    vector<string> res;
    vector<string> digitToChar = {"","","abc","def","ghi","jkl",
    "mno","qprs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        backtrack(0,"",digits);
        return res;
    }
    void backtrack(int i,string currStr,string& digits){
        if(currStr.size() == digits.size()){
            res.push_back(currStr);
            return;
        }
        string chars = digitToChar[digits[i]-'0'];
        for(char c : chars){
            backtrack(i+1,currStr+c,digits);
        }
    }
};
