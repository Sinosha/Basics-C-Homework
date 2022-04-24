#include <cstring>
#include <cstdlib>
#include "Stack.h"
#include <cctype>
#include <iostream>
using std::cout;

enum class Operation { PLUS, MINUS, MULTIPLY, DIVIDE, NONE = -1};
enum class Priority {PLUS = 1,MINUS = 1,MULTIPLY = 2,DIVIDE = 2};

Operation getOperation(char c) {
	if (c == '+')
		return Operation::PLUS;
	else if (c == '-')
		return Operation::MINUS;
	else if (c == '*')
		return Operation::MULTIPLY;
	else if (c == '/')
		return Operation::DIVIDE;
	return Operation::NONE;
}

Priority getPriority(char c)
{
	if (c == '+')
		return Priority::PLUS;
	else if (c == '-')
		return Priority::MINUS;
	else if (c == '*')
		return Priority::MULTIPLY;
	else if (c == '/')
		return Priority::DIVIDE;
}

bool parse(const char* expression, double& a, double& b, Operation& c) {
	const char* oper = strpbrk(expression, "+-*/");
	if (oper == nullptr)
		return false;

	a = atof(expression);
	c = getOperation(*oper);

	oper++;
	b = atof(oper);
	return true;
}

double plus(double a, double b) {
	return a + b;
}

double minus(double a, double b) {
	return a - b;
}

double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	return a / b;
}

void infix_to_postfix(const char* infix, char* postfix)
{
	int j = 0;
	for (int i = 0; infix[i] != '\0'; i++) {
		if (isdigit(infix[i]) || isspace(infix[i])) {
			postfix[j++] = infix[i];
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			char top = top_element();
			if (getPriority(top) >= getPriority(infix[i])) {
				postfix[j++] = top;
				pop();
				push(infix[i]);
			}
		}
	}
	while (!is_empty()) {
		char top = pop();
		postfix[j++] = top;
	}
	postfix[j] = '\0';
}

double calculate(const char* expression) {
	double (*action[])(double, double) = {
		plus, minus, multiply, divide
	};

	char* postfix = new char[strlen(expression) + 1];

	infix_to_postfix(expression, postfix);

	delete[] postfix;
}

bool is_empty()
{
	return top == 0;
}