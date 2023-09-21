#include "pch.h"
#include <iostream>
#include <string>
#include <stack>


using namespace std;
using namespace winrt;
using namespace Windows::Foundation;


int solvePostFixExp(string postFixExp) {

    stack<int> stack;

    for (int i = 0; i <= postFixExp.size(); ++i) { //loop that checks each char in string
        if (isalpha(postFixExp[i])) { // if it is a letter 

            switch (postFixExp[i]) { //checks which letter it is
            case 'a':
                stack.push(5);
                break;              // break out of switch expression 
            case 'b':
                stack.push(7);
                break;
            case 'c':
                stack.push(2);
                break;
            case 'd':
                stack.push(4);
                break;

            }

           // cout << stack.top() << "\n"; this was to check that everything was pushed on the stack correctly

        }
        else {

            int val1 = stack.top();     // records value of first val in stack
            stack.pop();                // pops off value in stack
            int val2 = stack.top();
            stack.pop();

            switch (postFixExp[i]) {
            case '+':
                stack.push(val2 + val1);
                break;
            case '-':
                stack.push(val2 - val1);
                break;
            case '*':
                stack.push(val2 * val1);
                break;
            case '/':
                stack.push(val2 / val1);
                break;
            case '$':
               //int finalValue = stack.top();
                //stack.pop();
               // stack.pop();
              // stack.push(finalValue);
              // cout << " \n" << stack.top();
                //return stack.top();
                break;
            }
           
          int finalValue = stack.top();
           //stack.pop();
           //stack.pop();
           cout << " \n" << finalValue;
        }

       //int finalValue = stack.top();
       //cout << " \n" << finalValue;
       

    }

    //int finalValue = stack.top();
   // cout << " \n " << finalValue;
    return 0;
}

    int main()
    {
        cout << "please input a postfix expression with $ at the end: \n";
        string postFixExp;
        char   yesOrNo;
        cin >> postFixExp;
        cout << "value: " << solvePostFixExp(postFixExp);


        cout << "Would you like to continue? y/n?";
        cin >> yesOrNo;
        while (yesOrNo == 'y') {
            cout << "please input a postfix expression with $ at the end: \n";
            cin >> postFixExp;
            cout << "value: " << solvePostFixExp(postFixExp);
            cout << "Would you like to continue? y/n?";
            cin >> yesOrNo;
            }

        if (yesOrNo == 'n') {
            cout << "All Done!";
        }

        return 0;
    }