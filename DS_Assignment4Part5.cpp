#include <iostream>
#include <string>
using namespace std;

string stack[100];
int top = -1;

void Push(string value)
{
    top++;
    stack[top] = value;
}

string Pop()
{
    string value = stack[top];
    top--;
    return value;
}

int main()
{
    string postfix, infix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // If operand
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            string operand = "";
            operand += ch;
            Push(operand);
        }

        // If operator
        else
        {
            string operand2 = Pop();
            string operand1 = Pop();

            string expression = "(" + operand1 + ch + operand2;
            expression += ")";

            Push(expression);
        }
    }

    infix = Pop();

    cout << "Infix expression: " << infix << endl;

    return 0;
}

// Run using:
// g++ DS_Assignment4Part5.cpp -o DS_Assignment4Part5
// ./DS_Assignment4Part5