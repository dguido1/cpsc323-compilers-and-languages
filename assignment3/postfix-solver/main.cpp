/*
      Name:               David Guido
      Course:             CPSC 323, Compilers and Languages
      Meeting Times:      T/TH 4:00pm - 5:15pm
      Date:               October 25, 2019
      Semester:           Fall 19'
   
      Assignment:         Assignment 3b (Programming)
   
      Files Included:     1.) main.cpp
****************************************************************
 
 Postfix Expression Evaluation (C++)
  Input must be the following format:
      Operands: Integers, include whitespace between two or more operands.
      Operators: '+'  ,  '-'  , '*' and '/'
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int EvalPostfix(string expression);
int HandleOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumericDigit(char C);

int main()
{
    string inputExpression;
    
    cout << "Enter Postfix Expression \n";
    getline(cin, inputExpression);
    int postfixResult = EvalPostfix(inputExpression);
    
    cout << "Output = " << postfixResult << "\n";
}

// Evaluates Postfix expression, return result.
int EvalPostfix (string expression)
{
    // Standard template C++ (Stack) Data Structure.
    stack<int> S;
    
    // Push dollar sign onto stack.
    S.push('$');

    for (int i = 0;i< expression.length();i++)
    {
        // Scan characters, one-by-one, from left.
        // If delimitter, move to next element.
        if (expression[i] == ' ' || expression[i] == ',') continue;

        // If operator, pop two elements, perform operation, push result back.
        else if (IsOperator(expression[i]))
        {
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            
            int result = HandleOperation(expression[i], operand1, operand2);

            S.push(result);
        }
        else if (IsNumericDigit(expression[i]))
        {
            // Get numbers from the string
            // Continue while you are getting a numeric digit.
            int operand = 0;
            while (i < expression.length() && IsNumericDigit(expression[i]))
            {
                // Case (> 1 Digit):
                // Multiply current total in operand by 10, add to new digit.
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            
            // Exit loop with i set to a non-numeric character, OR end of string
            // --> Decrement i, as its already incremented in the for loop.
            // i.e.) Would skip non-numeric character by incrementing i twice.
            i--;

            // Push operand onto stack.
            S.push(operand);
        }
    }
    // Stack has one element, the output.
    return S.top();
}

// Returns true if its a numeric digit.
bool IsNumericDigit (char C)
{
    if (C >= '0' && C <= '9')
        return true;
    
    return false;
}

// Returns true if its a operator symbol.
bool IsOperator (char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;

    return false;
}

// Perform operation, return output.
int HandleOperation (char operation, int operand1, int operand2)
{
    if (operation == '+')
        return operand1 +operand2;
    else if(operation == '-')
        return operand1 - operand2;
    else if(operation == '*')
        return operand1 * operand2;
    else if(operation == '/')
        return operand1 / operand2;

    else
        cout<<"Unexpected Error \n";
    
    return -1;
}
