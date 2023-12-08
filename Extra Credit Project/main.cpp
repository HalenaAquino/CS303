#include "functions.h"

int main() {
  // Variable declarations
  int choice;
  string expression;

  menu(choice);    // Calls the menu function

  // Loops through as long as the user does not enter 0
  while(choice != 0){

    // Prompts the user for an expression
    cout << "Enter an expression: ";
    cin >> expression;

    // If the user enters 1, determines if the expression is balanced. If it is, prints balanced, otherwise prints not balanced
    if(choice == 1){
      if(balanced(expression)){
        cout << "The expression is balanced\n\n";
      }
      else{
        cout << "The expression is not balanced\n\n";
      }
    }
    // if the user enters 2, if the expression is not balanced, coverts it to balanced and prints it to the user. Otherwise, prints that the expression is already balanced
    else if(choice == 2){
      if(!balanced(expression)){
        cout << "The balanced expression is: " << balance(expression) << endl << endl;
      }
      else{
        cout << "The expression is already balanced\n\n";
      }
    }
    // If the user enters 3, if the expression is balanced, converts it to postfix and prints it to the user. Otherwise, prints that the expression must be balanced
    else if(choice == 3){
      if(balanced(expression)){
        cout << "The postfix expression is: " << inf_to_postf(expression) << endl << endl;
      }
      else{
        cout << "The infix expression must be balanced\n\n";
      }
    }
    // If the user enters 4, converts the expression to infix and prints it to the user
    else if(choice == 4){
      cout << "The infix expression is: " << postf_to_inf(expression) << endl << endl;
    }

    menu(choice);    // Calls the menu function

    
  }

  cout << "Thank you. Goodbye\n";    // Prints exit message
  
}
