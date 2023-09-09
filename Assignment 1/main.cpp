#include "functions.h"


int main() {
  
  int numbers[150] = {0};  // Creates an array with 150 elements and sets all of them to 0
  int searchNum, searchNumIndex, modifyIndex, newEndInt, deleteIndex;

  fill_array(numbers, 150);  // Calls the fill_array function

  // Prints the original array
  cout << "Original array: " << endl;
  print_array(numbers, 150);
  cout << endl << endl;;

  // Continuously loops
  while(true){
    try{
      // Prompts the user for input
      cout << "Enter a number to search for: "; 
      cin >> searchNum;

      // If the user enters anything besides an integer, clears cin and throws an exception
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        throw runtime_error("Please enter an integer");
      }
      
      searchNumIndex = integer_index(numbers, 150, searchNum);  // Sets searchNumIndex to the return value of integer_index

      // If the number was found, prints it's index. Otherwise, prints "not found"
      if(searchNumIndex != -1){
        cout << searchNum << " found at index " << searchNumIndex << endl << endl;
      }
      else{
        cout << searchNum << " not found\n\n";
      }
  
      break;  // Breaks from the loop
    }
    catch(runtime_error e){
      cout << e.what() << endl << endl;    // Prints the reason the code was interrupted
    }
  }

  // Prints the array
  cout << "Current array: " << endl;
  print_array(numbers, 150);
  cout << endl << endl;

  // Continuously loops
  while(true){
    try{
      // Prompts the user for input
      cout << "Enter an index to change to -1: ";
      cin >> modifyIndex;
  
      // If the user enters anything besides an integer, clears cin and throws an exception
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        throw runtime_error("Please enter an integer");
      }
      // If the user enters an invalid index, throws an exception
      else if (modifyIndex > 149 || modifyIndex < 0){
        throw runtime_error("Please enter an index 0-149");
      }

      // Prints the index's previous and current value
      cout << "Index " << modifyIndex << " old value: " << numbers[modifyIndex] << endl;
      cout << "Index " << modifyIndex << " new value: " << modify_integer(numbers, 150, modifyIndex) << endl << endl;

      break;    // Breaks from the loop
      
    }
    catch(runtime_error e){
      cout << e.what() << endl << endl;  // Prints the reason the code was interrupted
    }
  }

  // Prints the array
  cout << "Current array: " << endl;
  print_array(numbers, 150);
  cout << endl << endl;
  
  // Continuously loops
  while(true){
    try{
      // Prompts the user for input
      cout << "Enter integer to add to the end: ";
      cin >> newEndInt;

      // If the user enters anything besides an integer, clears cin and throws an exception
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        throw runtime_error("Please enter an integer");
      }
      
      add_integer(numbers, 150, newEndInt);    // Calls the add_integer function
      cout << endl;
      break;    // Breaks from the loop
    }
    catch(runtime_error e){
      cout << e.what() << endl << endl;  // Prints the reason the code was interrupted
    }
  }

  // Prints the array
  cout << "Current array: " << endl;
  print_array(numbers, 150);
  cout << endl << endl;

  // Continuously loops
  while(true){
    try{
      // Prompts the user for input
      cout << "Enter an index to remove: ";
      cin >> deleteIndex;

      // If the user enters anything besides an integer, clears cin and throws an exception
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        throw runtime_error("Please enter an integer");
      }
      // If the user enters an invalid index, throws an exception
      else if (deleteIndex > 149 || deleteIndex < 0){
        throw runtime_error("Please enter an index 0-149");
      }
    
      remove_index(numbers, 150, deleteIndex);    // Calls the remove_index function
      cout << endl;
      break;    // Breaks from the loop
    }
    catch(runtime_error e){
      cout << e.what() << endl << endl;  // Prints the reason the code was interrupted
    }
  }
  
  // Prints the array
  cout << "Current array: " << endl;
  print_array(numbers, 150);
  
  
}
