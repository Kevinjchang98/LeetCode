class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> n;
        
        for (auto e : tokens) {
            if (isalnum(e[0]) || (e[0] == '-' && e.size() > 1)) {
                n.push(stoi(e));
            } else {
                long b = n.top();
                n.pop();
                long a = n.top();
                n.pop();
                
                switch(e[0]) {
                    case '+':
                        n.push(b + a);
                        break;
                    case '-':
                        n.push(a - b);
                        break;
                    case '*':
                        n.push(a * b);
                        break;
                    case '/':
                        n.push(a / b);
                        break;
                }
            }
        }
        
        return n.top();
    }
};