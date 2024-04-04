#include "bracket.h"

bool checkBrackets(std::string s) {
	std::stack<char> brackets;
	bool flag = true;
	for (int i = 0; i < s.size() && flag; i++) {
		if (s[i] == '[' || s[i] == '(' || s[i] == '<' || s[i] == '{') {
			brackets.push(s[i]);
		}
		else if (brackets.empty() && (s[i] == ']' || s[i] == ')' || s[i] == '>' || s[i] == '}')) {
			flag = false;
		}
		else if (!brackets.empty() && (s[i] == ']' || s[i] == ')' || s[i] == '>' || s[i] == '}')) {
			if (brackets.top() == '[' && s[i] == ']' || brackets.top() == '(' && s[i] == ')' || brackets.top() == '{' && s[i] == '}' || brackets.top() == '<' && s[i] == '>')
				brackets.pop();
			else flag = false;;
		}
	}
	if (!brackets.empty())
		flag = false;
	return flag;
}
