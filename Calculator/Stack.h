#pragma once


template<typename T, int size>
struct stack {
	T buffer[size] = {};
	int top = 0;
};

template <typename T, int size>
void push(stack<T,size>& stack, T c) {
		stack.buffer[stack.top] = c;
		stack.top++;
	}

template <typename T, int size>
T pop(stack<T,size>& stack)
{
	stack.top--;
	return stack.buffer[stack.top];
}

template <typename T, int size>
bool is_empty(const stack<T,size>& stack)
{
	return stack.top == 0;
}

template <typename T, int size>
T top_element(const stack<T,size>& stack)
{
	if (is_empty(stack))
		return {};
	return stack.buffer[stack.top - 1];
}
