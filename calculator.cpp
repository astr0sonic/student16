#include "calculator.h"

int Priority(char ch) {
	switch (ch) {
	case '(':
		return 5;
	case '^':
		return 4;
	case '_':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

bool checkBrackets(std::string s) {
	std::stack<char> brackets;
	bool flag = true;
	for (int i = 0; i < s.size() && flag; i++) {
		if (s[i] == '(') {
			brackets.push(s[i]);
		}
		else if (brackets.empty() && s[i] == ')') {
			flag = false;
		}
		else if (!brackets.empty() && s[i] == ')') {
			if (brackets.top() == '(' && s[i] == ')')
				brackets.pop();
			else flag = false;;
		}
	}
	if (!brackets.empty())
		flag = false;
	return flag;
}

bool check(std::string str) {
	bool flag = true;
	if (!checkBrackets(str)) {
		return false;
	}
	else {
		for (int i = 0; i < str.size() && flag; i++) {
			if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^' || str[i] == '.')) {
				return false;
			}
			if (i > 0 && str[i] == '-' && !((str[i - 1] >= '0' && str[i - 1] <= '9') || str[i - 1] == '(' || str[i - 1] == ')')) {
				return false;
			}
			if (i > 0 && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '/' || str[i - 1] == '*' || str[i - 1] == '^') && (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^')) {
				return false;
			}
			if (i > 0 && i + 1 < str.size() && str[i] == '.' && !((str[i - 1] >= '0' && str[i - 1] <= '9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))) {
				return false;
			}

		}
	}
	return flag;

}

double calculate(const std::string& expr) {
	std::stack<char> s_opt;
	std::stack<double> s_num;
	std::string opt = expr;
	int i = 0;
	std::string temp;
	opt.erase(remove_if(opt.begin(), opt.end(), ::isspace), opt.end());
	if (!check(opt))
		throw std::exception();
	else {
		while (i < opt.size() || s_opt.empty() != true) {
			if (((opt[i] >= '0' && opt[i] <= '9') || opt[i] == '.')) {
				temp += opt[i];
				i++;
				if (opt[i] == '+' || opt[i] == '-' || opt[i] == '*' || opt[i] == '/' || opt[i] == '^' || opt[i] == '(' || opt[i] == ')' || i == opt.size()) {
					s_num.push(stod(temp));
					temp.clear();
				}
			}
			else {
				if ((opt[i] == ')') && (s_opt.top() == '(')) {
					s_opt.pop();
					i++;
					continue;
				}
				if ((s_opt.empty()) == true || (Priority(opt[i]) > Priority(s_opt.top())) || (s_opt.top() == '(' && (opt[i] != ')'))) {
					if (i > 1 && opt[i - 1] == '(' && opt[i] == '-') {
						s_opt.push('_');
					}
					else s_opt.push(opt[i]);
					i++;
					continue;
				}
				if ((i < opt.size() && s_opt.empty() != true) || ((opt[i] == ')') && (s_opt.top() != '(')) || (Priority(opt[i]) <= Priority(s_opt.top()))) {
					char ch = s_opt.top();
					s_opt.pop();
					double num1, num2;
					switch (ch) {
					case'+':
						num1 = s_num.top();
						s_num.pop();
						num2 = s_num.top();
						s_num.pop();
						s_num.push(num1 + num2);
						break;
					case'-':
						num1 = s_num.top();
						s_num.pop();
						num2 = s_num.top();
						s_num.pop();
						s_num.push(num2 - num1);
						break;
					case '_':
						num1 = s_num.top();
						s_num.pop();
						s_num.push(num1 * (-1));
						break;
					case'*':
						num1 = s_num.top();
						s_num.pop();
						num2 = s_num.top();
						s_num.pop();
						s_num.push(num1 * num2);
						break;
					case'/':
						num1 = s_num.top();
						s_num.pop();
						num2 = s_num.top();
						s_num.pop();
						if (num1 == 0)
							throw std::exception();
						else s_num.push(num2 / num1);
						break;
					case '^':
						num1 = s_num.top();
						s_num.pop();
						num2 = s_num.top();
						s_num.pop();
						s_num.push(pow(num2, num1));
						break;
					}
				}
			}
		}
		return s_num.top();
	}
}
