#include <iostream>
 using namespace std;

struct Node{
  char data;
  Node* next;
};

class Queue{
  private:
    Node* head;
    Node* tail;
    int num_items;


  public:
    Queue();
    bool empty();
    void dequeue();
    void enqueue(char c);
    int size();
    char front();
    void print_queue();

};