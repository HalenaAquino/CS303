#include "Single_Linked_List.h"

/* Sets the head, tail, and num_items variables to their base valeus
   pre: no parameters passed
   post: head and tail now equal nullptr and num_items now equals 0
*/
Single_Linked_List::Single_Linked_List(){
  // Sets all variables to their basic values
  head = nullptr;
  tail = nullptr;
  num_items = 0;
}

/* Adds the given element to the front of the list
   pre: a character is passed as a parameter
   post: the given character is now at index 0 of the list
*/
void Single_Linked_List::push_front(char d){
  // Makes a new node and sets it's data to the character parameter
  ListNode* newNode = new ListNode;
  newNode->data = d;
  // If the list is empty, sets the tail to the new node and sets the head to tail
  if (empty()){
    tail = newNode;
    head = tail;
  } 
  // Otherwise, sets the pointer for newnode to head, and sets head to the new node
  else{
    newNode->next = head;
    head = newNode;
  }
  num_items++;    // Increments the number of items
  
}

/* Removes the front index of the list
   pre: no parameters passed
   post: the element at index 0 is now removed and replaced with the element it pointed to
*/
void Single_Linked_List::pop_front(){
  // If the list is empty, prints that it is empty and leaves the function
  if(empty()){    
    cout << "List is empty\n";
    return;
  }

  // Sets a temporary node to the element after the head element, deletes the head element, and sets head to the temporary element
  ListNode* temp = head->next;
  delete head;
  head = temp;

  num_items--;    // Decrements the number of items
}

/* Adds the given element to the back of the list
   pre: a character parameter is passed
   post: the given character is at the last index in the list
*/
void Single_Linked_List::push_back(char d){
  // Creates a new node, sets tails pointer to it, sets its data to the parameter character, and sets tail to the new node
  ListNode* newNode = new ListNode;
  tail->next = newNode;
  newNode->data = d;
  tail = newNode;
  
  num_items++;    // Increments the number of items
  
}

/* Removes the last element of the list
   pre: no paramters passed
   post: The element at the last index of the list is removed
*/
void Single_Linked_List::pop_back(){
  // If the list is empty, leaves the function without doing anything
  if (empty()){
    return;
  }
  // Oherwise, if the head and tail are equal, deletes the head, sets the tail to nullptr, sets head to tail, sets the number of items to 0, and leaves the function
  else if (head == tail){
    delete head;
    tail = nullptr;
    head = tail;
    num_items = 0;
    return;
  }

  // Makes a temporary node and cycles through it until the next pointer is the tail node
  ListNode* temp = head;
  while (temp->next != tail){
    temp = temp->next;
  }

  // Deletes the tail node, sets tail to the temporary node and sets the tails pointer to a nullpur
  delete tail;
  tail = temp;
  tail->next = nullptr;
  
  num_items--;    // Decrements the number of items
  
}

/* Returns the front element of the list 
   pre: no parameters
   post: returned the element at index 0 in the list
*/
char Single_Linked_List::front(){
  return head->data;    // Returns the data of the head node
}

/* Returns the back element of the list
   pre: no parameters
   post: returned the element at the last index in the list
*/
char Single_Linked_List::back(){
  return tail->data;    // Returns the data of the tail node
}

/* Returns true of false if the list is currently empty
   pre: no parameters 
   post: returned true or false depending on if the number of items in the list is equal to 0
*/
bool Single_Linked_List::empty(){
  return num_items == 0;    // Returns T/F if there are no items in the list
}

/* Inserts a given element at a given index
   pre: An integer and character are passed as parameters
   post: The given element is now at the given index, with all other elements after it shifted to the right
*/
void Single_Linked_List::insert(int index, const char d){
  // If the user entered an index greater than the size of the list, just adds it to the end
  if(index >= num_items){
    push_back(d);
  }
  // If the user entered an index less than or equal to 0, just adds it to the front
  else if(index <= 0){
    push_front(d);
  }
  else{
    // Makes a temporary node and cycles through it until it's next pointer is equal to the node at the given index
    ListNode* temp = head;
    for(int i = 0; i < index - 1; i++){
      temp = temp->next;
    }

    // Makes a new node, sets its data to the character parameter, sets its next pointer to the temporary nodes next pointer, and sets the temporary nodes next pointer to the new node
    ListNode* newNode = new ListNode;
    newNode->data = d;
    newNode->next = temp->next;
    temp->next = newNode;
    
    num_items++;    // Increments the number of items
  }
  
}

/* Removes an element at the given index
   pre: An integer parameter is passed
   post: The element at the given element is deleted and all elements to the right of it are shifted to the left
*/
bool Single_Linked_List::remove(int index){
  // If the given index is less than or equal to 0, removes the front element are returns T
  if(index <= 0){
    pop_front();
    return true;
  }
  // If the given index is the last index, removes the last element and returns T
  else if(index == num_items - 1){
    pop_back();
    return true;
  }
  else{
    // Makes a temporary node and cycles through it until it's next pointer is equal to the node at the given index
    ListNode* temp = head;
    for(int i = 0; i < index - 1; i++){
      temp = temp->next;
    }

    // Makes a delete node and sets it to temporary node, sets the temporary nodes next pointer to the pointer of temporary nodes pointer, deletes the deletion node, and returns T
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return true;
    

    num_items--;    // Decrements the number of items
  }
  
}

/* Returns the size of the list
   pre: no parameters
   post: The number of items in the list is returned
*/
int Single_Linked_List::size(){
  return num_items;    // Returns the size of the list
}

/* Find the index of the given element
   pre: a character parameter is passed
   post: The index of the element is returned, OR the length of the list is returned if the element wasn't found
*/
int Single_Linked_List::find(char d){
  // Makes a search node and cycles through it until it reaches the end of the list
  ListNode* searchNode = head;
  for(int i = 0; i < num_items; i++){
    // If the current node is equal to the character parameter, returns the index
    if(searchNode->data == d){
      return i;
    }
    searchNode = searchNode->next;
  }

  return num_items;    // Otherwise, returns the length of the list
  
}

/* Prints the entire list
   pre: no parameters
   post: The list is printed to the screen
*/
void Single_Linked_List::print_list(){
  ListNode* temp = head;    // Creates a temporary node
  cout << "Current List: ";

  // If the list is empty, prints empty
  if(empty()){
    cout << "empty";
  }
  else{
    // Cycles through the temporary node until it reaches the end of the list
    while(temp != nullptr){
      cout << temp->data;    // Prints the temporary nodes data
      // If the temporary node is not the last element in the list, prints an arrow
      if(temp->next != nullptr){
        cout << " -> ";
      }
      temp = temp->next;
    }
  }

  cout << endl << endl;    // Prints newlines
}