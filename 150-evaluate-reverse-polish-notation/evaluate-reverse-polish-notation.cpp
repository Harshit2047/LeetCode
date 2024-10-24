class Solution {
public:
   
    int calculate(int num1, int num2, const string& op) {
        if (op == "+") return num1 + num2;
        else if (op == "-") return num1 - num2;
        else if (op == "*") return num1 * num2;
        else if (op == "/") return num1 / num2;
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack; 
        
        for (int i = 0; i < tokens.size(); ++i) {
            string token = tokens[i];
            
           
            if (token == "+" || token == "-" || token == "*" || token == "/") {
               
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();
                
               
                numStack.push(calculate(num1, num2, token));
            } 
        
            else {
               
                numStack.push(stoi(token));
            }
        }
        
        
        return numStack.top();
    }
};
