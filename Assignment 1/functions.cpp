#include "functions.h"

/* Reads the data.txt file and fills an array with it's contents
   pre: an integer array and positive integer are passed as parameters
   post: array is filled with all numbers in data.txt
*/
void fill_array(int nums[], int arr_size){
  // opens file
  ifstream inFile;
  inFile.open("data.txt");

  int number, numIndex = 0;

  // Loops through until the file ends or the array is full
  while(!inFile.eof() && numIndex < arr_size){
    // Pulls the number from the file and adds it to the array at the current index
    inFile >> number;
    nums[numIndex] = number;
    numIndex++;    // Updates the index
    
  }

  inFile.close();    // Closes the file
}

/* Searches for a given number in the array
   pre: an integer array, a positive integer, and an integer are passed as parameters
   post: returns the position of the given number, or -1 if not found
*/
int integer_index(int nums[], int arr_size, int searchNum){
  // Loops through the entire array
  for(int i = 0; i < arr_size; i++){
    if(nums[i] == searchNum){  // If the current number = seaechNum, returns the current index
      return i;
    }
  }

  return -1;    // Otherwise, returns -1
}

/* Changes the element at a given index to -1
   pre: an integer array, a positive integer, and an integer 0-149 are passed as parameters
   post: The element at the given index is -1
*/
int modify_integer(int nums[], int arr_size, int modifyIndex){
  nums[modifyIndex] = -1;    // changes the given index to -1
  return nums[modifyIndex];  // Returns element at the given index
}

/* Adds a given integer to the end of the array
   pre: an integer array, a positive integer, and an integer are passed as parameters
   post: the given integer is at the last index in the array
*/
void add_integer(int nums[], int arr_size, int newInt){
  // Loops through the entire array
  for(int i = 1; i < arr_size; i++){
    // If the previous or next element aren't 0, sets the current index to the given value and breaks from the loop
    if(nums[i-1] != 0 && nums[i+1] == 0){
      nums[i+1] = newInt;
      break;
    }
  }
}

/* Removes the element at the given index
   pre: an integer array, a positive integer, and an integer 0-149 are passed as parameters
   post: the element at the given index is removed and all other elements are shifted
*/
void remove_index(int nums[], int arr_size, int delIndex){
  // Loops through the entire array
  for(int i = delIndex; i < arr_size; i++){
    nums[i] = nums[i + 1];  // Sets each element to the element to it's right
  }
  nums[arr_size-1] = 0;  // Sets the last element to 0
}

/* Prints all of the elements in the array 
   pre: an integer array and positive integer are passed as parameters
   post: all elements in the array are printed to the user
*/
void print_array(int nums[], int arr_size){
  // Loops through the entire array and prints each element
  for(int i = 0; i < arr_size; i++){
    cout << nums[i] << ", ";
  }
}

