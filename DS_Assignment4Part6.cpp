#include <iostream>
using namespace std;

int stack[100];
int top = -1;

void Push(int value)
{
    top++;
    stack[top] = value;
}

int Pop()
{
    int value = stack[top];
    top--;
    return value;
}

int main()
{
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // If operand
        if (ch >= '0' && ch <= '9')
        {
            int value = ch - '0';
            Push(value);
        }

        // If operator
        else
        {
            int operand2 = Pop();
            int operand1 = Pop();

            int result;

            if (ch == '+')
                result = operand1 + operand2;

            else if (ch == '-')
                result = operand1 - operand2;

            else if (ch == '*')
                result = operand1 * operand2;

            else if (ch == '/')
                result = operand1 / operand2;

            else if (ch == '%')
                result = operand1 % operand2;

            else if (ch == '^')
            {
                result = 1;

                for (int j = 0; j < operand2; j++)
                    result = result * operand1;
            }

            Push(result);
        }
    }

    cout << "Result: " << stack[top] << endl;

    return 0;
}

// Run using:
// g++ DS_Assignment4Part6.cpp -o DS_Assignment4Part6
// ./DS_Assignment4Part6