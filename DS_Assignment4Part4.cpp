#include <iostream>
using namespace std;

char stack[100];
int top=-1;

void Push(char value)
{
    top++;
    stack[top] = value;
}

char Pop()
{
    char value = stack[top];
    top--;
    return value;
}

int Precedence(char op)
{
    if (op=='^')
    return 3;

    if (op=='*' || op=='/')
    return 2;

    if (op=='+' || op=='-')
    return 1;

    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int index = 0;

    cout<<"Enter infix expression: ";
    cin>>infix;  //not using getline() as we need one onnected string here
    
    for (int i=0 ; infix[i]!='\0' ; i++)
    {
        char ch = infix[i];
        if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
        {
            postfix[index] = ch;
            index++;
        }

        else if (ch=='(')
        {
            Push(ch);
        }

        else if (ch==')')
        {
            while (top!=-1 && stack[top]!='(')
            {
                postfix[index] = Pop();
                index++;
            }

            if (top!=-1)
            {
                Pop();
            }
        }

        else
        {
            while(top!=-1 && (Precedence(stack[top])>=Precedence(ch)))
            {
                postfix[index] = Pop();
                index++;
            }
            Push(ch);
        }
    }

    while(top!=-1)
    {
        postfix[index] = Pop();
        index++;
    }

    postfix[index] = '\0';  //terminating string
    cout<<"Postfix: "<<postfix<<endl;
    return 0;
}
// Run using:
// g++ DS_Assignment4Part4.cpp -o DS_Assignment4Part4
// ./DS_Assignment4Part4