#include "Single_Linked_List.h"
#include "Employee.h"


int main() {
  //=========================== Linked List Class ========================
  Single_Linked_List s;

  cout << "=========================== Linked List Class =======================\n\n";
  s.print_list();

  // Pushes 'A' to the front and prints the list
  cout << "Pushed 'A' to the front\n";
  s.push_front('A');
  s.print_list();

  // Pushes 'B' to the front and prints the list
  cout << "Pushed 'B' to the front\n";
  s.push_front('B');
  s.print_list();

  // Pushes 'C' to the back and prints the list
  cout << "Pushed 'C' to the back\n";
  s.push_back('C');
  s.print_list();

  // Pushes 'D' to the back and prints the list
  cout << "Pushed 'D' to the back\n";
  s.push_back('D');
  s.print_list();

  // Removes the front element and prints the list
  cout << "Popped the front element\n";
  s.pop_front();
  s.print_list();

  // Removes the back element and prints the list
  cout << "Popped the back element\n";
  s.pop_back();
  s.print_list();

  // Prints the first and last elements
  cout << "First element: " << s.front() << endl << endl;
  cout << "Last element: " << s.back() << endl << endl;

  // Determines if the list is empty and prints if it is to the user
  if(s.empty()){
    cout << "The list is empty\n\n";
  }
  else{
    cout << "The list is not empty\n\n";
  }

  // Removes the front element and prints the list
  cout << "Popped the front element\n";
  s.pop_front();
  s.print_list();

  // Removes the back element and prints the list
  cout << "Popped the back element\n";
  s.pop_back();
  s.print_list();

  // Determines if the list is empty and prints if it is to the user
  if(s.empty()){
    cout << "The list is empty\n\n";
  }
  else{
    cout << "The list is not empty\n\n";
  }

  // Pushes 'E' to the front and prints the list
  cout << "Pushed 'E' to the front\n";
  s.push_front('E');
  s.print_list();

  // Pushes 'F' to the back and prints the list
  cout << "Pushed 'F' to the back\n";
  s.push_back('F');
  s.print_list();

  // Inserts 'G' into index 1 and prints the list
  cout << "Inserted 'G' into index 1\n";
  s.insert(1, 'G');
  s.print_list();

  // Inserts 'H' into index 2 and prints the list
  cout << "Inserted 'H' into index 2\n";
  s.insert(2, 'H');
  s.print_list();

  // Removes the element at index 1 and prints the list
  cout << "Removed element at index 1\n";
  s.remove(0);
  s.print_list();

  // Declares a search character variable and sets it to 'F'
  char searchChar;
  searchChar = 'F';

  // If the return values of the find() function is equal to the size of the list, prints that the element wasn't found
  if(s.find(searchChar) == s.size()){
    cout << "Element '" << searchChar << "' not found\n\n";
  }
  // Otherwise, prints the elements index
  else{
    cout << "Element '" << searchChar << "' found at index " << s.find(searchChar) << endl << endl;
  }

  searchChar = 'J';    // Sets the search character variable to 'J'

  // If the return values of the find() function is equal to the size of the list, prints that the element wasn't found
  if(s.find(searchChar) == s.size()){
    cout << "Element '" << searchChar << "' not found\n\n";
  }
  // Otherwise, prints the elements index
  else{
    cout << "Element '" << searchChar << "' found at index: " << s.find(searchChar) << endl << endl;
  }

  //============================ Employee Class =========================

  cout << "============================ Employee Class =========================\n\n";


  Professional PE(4500.00, 2);    // Creates a Professional instance with a monthly salary of $4500 and 2 vacation days
  cout << "Employee 1:\n";
  // Prints the employees type, weekly salary, vacation days, and healthcare contribution
  cout << "Employee type: Professional\n";
  cout << "Weekly salary: " << PE.weekly_salary() << endl;
  cout << "Vacation days: " << PE.vacation_days() << endl;
  cout << "Healthcare contribution: " << PE.healthcare_contribution() << endl << endl << endl;


  Nonprofessional NPE(30.50, 40);    // Creates a Nonrofessional instance with a $30.50 hourly rate and 40 hours worked
  cout << "Employee 2:\n";
  // Prints the employees type, weekly salary, vacation days, and healthcare contribution
  cout << "Employee type: Nonprofessional\n";
  cout << "Weekly salary: " << NPE.weekly_salary() << endl;
  cout << "Vacation days: " << NPE.vacation_days() << endl;
  cout << "Healthcare contribution: " << NPE.healthcare_contribution() << endl;
 
}