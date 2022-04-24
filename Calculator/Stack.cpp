char stack[100];
int top = 0;


void push(char c) 
{
	stack[top] = c;
	top++;
}

char pop()
{
	top--;
	return stack[top];
}

char top_element()
{
	if (top == 0)
		return '\0';
	return stack[top - 1];
}