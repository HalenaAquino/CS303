#include "Queue.h"

/* A default constructor for a queue class 
   pre: No parameters
   post: Sets the head and tail to null pointers, sets the number of items to 0
*/
Queue::Queue(){
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

/* Determines if the queue is empty
   pre: No parameters
   post: Returns true if the number of items is 0, returns false otherwise
*/
bool Queue::empty(){
  return num_items == 0;
}

/* Removes the first item in the queue
   pre: No parameters
   post: Removes the first item in the queue, or returns without doing anything (if the queue is empty)
*/
void Queue::dequeue(){
  if (head == nullptr){
    return;
  }
  
  Node* temp = head;    // Creates a temporary node and sets it to head
  head = head->next;    // Sets head to the node it points to
  delete temp;          // Deletes the original head value
  num_items--;          // Decrements the number of items
  
  
}

/* Adds an element to the queue
   pre: A character parameter is passed
   post: The given character will be added to the end of the queue
*/
void Queue::enqueue(char c){
  // Creates a new node, sets its data to the given character, and sets its next pointer to null
  Node* new_node = new Node;
  new_node->data = c;
  new_node->next = nullptr;

  if(head == nullptr){ // If the queue is empty, sets the head and tail to the new node
    head = new_node;
    tail = new_node;
  } 
  else{    // Otherwise, sets tail's next pointer to the new node and sets tail to the new node
    tail->next = new_node;
    tail = new_node;
  }

  num_items++;    // Increments the number of items

  
}

/* Returns the size of the queue
   pre: No parameters
   post: The number of items will be returned 
*/
int Queue::size(){
  return num_items;
}

/* Returns the top/front item in the queue
   pre: No parameters
   post: The data of the head node will be returned
*/
char Queue::front(){
  return head->data;
}

/* Prints each element in the queue
   pre: No parameters
   post: Each element in the queue will be printed with an arrow
*/
void Queue::print_queue(){
  Node* temp = head;    // Creates a temporary node and sets it to the head node

  cout << "Current queue: ";

  if(empty()){    // If the queue is empty, prints that it is empty and leaves the function
    cout << "Queue empty\n";
    return;
  }

  // Loops through until the temporary pointer is at the end of the queue. Prints the temporary nodes data and prints an arrow after it if the temporary pointer is not currently the tail
  while(temp != nullptr){
    cout << temp->data;

    if(temp->next != nullptr){
      cout << " <- ";
    }

    temp = temp->next;    // Sets the temporary node to it's next pointer
  }

  cout << endl;
  

}