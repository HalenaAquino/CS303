#include "functions.h"

// Sets OPEN and CLOSE to the appropriate opening/closing characters
const string OPEN = "({[";
const string CLOSE = ")}]";

/* Determines if a character is one of the valid opening types: ({[
   pre: Takes a character as a parameter
   post: Returns true if the given character is within the OPEN string, false otherwise
*/
bool open(char c){
  return OPEN.find(c) != string::npos;  // Determines if the OPEN string contains the given character
}

/* Determines if a character is one of the valid closing types: )}]
   pre: Takes a character as a parameter
   post: Returns true if the given character is within the CLOSE string, false otherwise
*/
bool closed(char c){
  return CLOSE.find(c) != string::npos;  // Determines if the CLOSE string contains the given character
}

/* Determines if the given expression has balanced parenthesis
   pre: takes a string as a parameter
   post: Returns true if the given expression is balanced, false otherwise
*/
bool balanced(const string& str){
  // Creates a stack, a boolean balance variable set to false, and a string iterator set to the beginning of the given expression
  stack<char> s;
  bool bal = true;
  string::const_iterator i = str.begin();

  // Loops through while the balance variable if set to true and the iterator is not at the end of the given expression
  while(bal && (i != str.end())){
    char next_char = *i;

    // Determines if the next character is an opening type
    if(open(next_char)){
      s.push(next_char);
    }
    else if(closed(next_char)){  // Else, determines if the next character is a closing type
      // If the stack is empty, sets the balance expression to false
      if(s.empty()){
        bal = false;
      }
      else{
        char top_char = s.top();    // Documents the top character of the stack
        s.pop();                    // Deletes the top character
        bal = OPEN.find(top_char) == CLOSE.find(next_char);      // Determines if the top character and next character are a matching type
      }
    }
    i++;    // Increments the iterator
}
  return bal && s.empty();    // Returns true if the stack is empty and the balance variable is true, false otherwise 
}

/* Determines the given operations order/priority
   pre: takes a character as a parameter
   post: Returns a number for the priority of the given operator (the higher the number, the higher the priority). Returns -1 if the operator is not recognized 
*/
int get_order(char o){
  if (o == '*' || o == '/' || o == '%'){
    return 2;
  }
  else if (o == '+' || o == '-'){
    return 1;
  }
  else{
    return -1;
  }
}

/* Converts the given infix expression into a postfix expression
   pre: takes a string as a parameter
   post: returns the given string converted into postfix
*/
string inf_to_postf(string inf){
  // Creates a stack and postfix string
  stack<char> s;
  string postf;

  for (int i = 0; i < inf.length(); i++){    // loops through from 0 to the size of the given string
    char c = inf[i];

    if (isalnum(c)){    // If the current character of the string is a numeber or letter, adds it to the postfix string
      postf += c;
    } 
    else if (c == '(' || c == '{' || c == '['){  // If the current character is a opening type, pushes it onto the stack
      s.push(c);
    } 
    else if (c == ')' || c == '}' || c == ']'){  // Determines if the curenr character is a closing type
      // Loops through while stack is not empty and the top of the stack is not a opening type
      while (!s.empty() && (s.top() != '(' && s.top() != '{' && s.top() != '[')){
        // Adds the top element to the postfix strong and removes it from the stack
        postf += s.top();
        s.pop();
      }
      
      s.pop();    // Removes the top element
    } 
    else {
      // Loops through while the stack is not empty and the current character's priority is <= the top character of the stacks priority
      while (!s.empty() && get_order(c) <= get_order(s.top())){
        // Adds the top element to the postfix strong and removes it from the stack
        postf += s.top();
        s.pop();
      }
      
      s.push(c);    // Adds the current character to the stack
    }
  }

  // While the stack is not empty, adds the top character of the stack to the postfix string and removes it from the stack
  while (!s.empty()){
    postf += s.top();
    s.pop();
  }

  return postf;    // Returns the postfix string 
}

