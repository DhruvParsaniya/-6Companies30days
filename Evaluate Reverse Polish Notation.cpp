class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0;i < tokens.size();i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();

                int op;
                if (tokens[i] == "+") op = op1 + op2;
                else if (tokens[i] == "-") op = op1 - op2;
                else if (tokens[i] == "*") op = op1 * op2;
                else op = op1 / op2;

                s.push(op);
            } else {
                int tmp = stoi(tokens[i]);
                s.push(tmp);
            }
        }

        int ans = s.top();
        return ans;
    }
};
