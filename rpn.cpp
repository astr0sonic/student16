#include "rpn.h"

double calculateRPN(const std::string& expression) {
    std::stack<double> operands;
    std::queue<std::string> syms;
    std::string expr = expression;
    int pos = 0;
    while ((pos = expr.find(' ')) != std::string::npos) {
        syms.push(expr.substr(0, pos));
        expr.erase(0, pos + 1);
    }
    syms.push(expr);
    while (!syms.empty()) {
        std::string sym = syms.front();
        syms.pop();
        if (isdigit(sym[0])) {
            operands.push(stod(sym));
        }
        else {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();
            if (sym == "+")
                operands.push(operand1 + operand2);
            else if (sym == "-")
                operands.push(operand1 - operand2);
            else if (sym == "*")
                operands.push(operand1 * operand2);
            else if (sym == "/")
                operands.push(operand1 / operand2);
        }
    }
    return operands.top();
}
