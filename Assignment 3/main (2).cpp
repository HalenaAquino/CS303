#include "Queue.h"
#include "functions.h"

int main() {
  
  //-----------------------------Balanced & Infix/Postfix------------------------------

  cout << "\n\n================Balanced & Infix/Postfix=================\n\n";    // Prints a header
  // Prompts the user for an expression
  cout << "Enter an expression (enter X to leave): ";
  string e;

  // Loops through taking the users input each time as long as it is not X or x
  while(getline(cin, e) && (e != "X" && e != "x")){
    cout << e;

    if(balanced(e)){    // Determines if the given expression is balanced
      cout << " is valid (balanced)\n";

      // Converts the current expression to postfix and prints it to the user
      string postfix = inf_to_postf(e);
      cout << "Converted to postfix: " << postfix << endl << endl;
    }
    else{    // If the expression is not balanced, prints to the user that it's not balanced
      cout << " is invalid (not balanced)\n\n";
    }
    cout << "Enter an expression (enter X to leave): ";    // Prompts the user for input again
  }

  
  //------------------------------------------Queue Class----------------------------------

  cout << "\n\n=======================Queue Class=======================\n\n";    // Prints a header
  
  Queue q;    // Creates a queue object

  // Determines if the queue is empty. Prints the appropriate message if it is/isn't
  if(q.empty()){
    cout << "The queue is empty\n";
  }
  else{
    cout << "The queue is not empty\n";
  }

  q.print_queue();

  cout << "Number of items in queue: " << q.size() << endl;    // Prints the number of items in the queue

  // Adds A to the queue, prints it, and prints the number of items in it
  cout << "\nAdded 'A' to the queue\n";
  q.enqueue('A');
  q.print_queue();
  cout << "Number of items in queue: " << q.size() << endl;

  // Adds B to the queue, prints it, and prints the number of items in it
  cout << "\nAdded 'B' to the queue\n";
  q.enqueue('B');
  q.print_queue();
  cout << "Number of items in queue: " << q.size() << endl;

  // Removes an element, prints the queue, and prints the number of items in it
  cout << "\nRemoved element from the queue\n";
  q.dequeue();
  q.print_queue();
  cout << "Number of items in queue: " << q.size() << endl;

  // Adds C to the queue, prints it, and prints the number of items in it
  cout << "\nAdded 'C' to the queue\n";
  q.enqueue('C');
  q.print_queue();
  cout << "Number of items in queue: " << q.size() << endl;

  cout << "\nFront item in queue: " << q.front() << endl;    // Prints the front item in the queue

  // Adds D to the queue, prints it, and prints the number of items in it
  cout << "\nAdded 'D' to the queue\n";
  q.enqueue('D');
  q.print_queue();
  cout << "Number of items in queue: " << q.size() << endl;

  // Removes an element, prints the queue, and prints the number of items in it
  cout << "\nRemoved element from the queue\n";
  q.dequeue();
  q.print_queue();
  cout << "Number of items in queue: " << q.size() << endl;

  cout << "\nFront item in queue: " << q.front() << endl << endl;    // Prints the front item in the queue

  // Determines if the queue is empty. Prints the appropriate message if it is/isn't
  if(q.empty()){
    cout << "The queue is empty\n";
  }
  else{
    cout << "The queue is not empty\n";
  }
  

  
}