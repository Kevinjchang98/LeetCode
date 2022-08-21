class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> n;
        
        for (auto e : tokens) {
            if (isalnum(e[0]) || (e[0] == '-' && e.size() > 1)) {
                n.push(stoi(e));
                
            } else {
                int num2 = n.top();
                n.pop();
                int num1 = n.top();
                n.pop();
                
                switch (e[0]) {
                    case '+':
                        n.push(num1 + num2);
                        break;
                    case '-':
                        n.push(num1 - num2);
                        break;
                    case '*':
                        n.push(num1 * num2);
                        break;
                    case '/':
                        n.push(num1 / num2);
                        break;
                }
            }
        }
        

        
        return n.top();
        
    }
};