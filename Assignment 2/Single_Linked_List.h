#include <iostream>

using namespace std;

struct ListNode{
  char data;
  ListNode* next;
};

class Single_Linked_List{
  private:
    ListNode* head;
    ListNode* tail;
    int num_items;

  public:
    Single_Linked_List();
    void push_front(char d);
    void push_back(char d);
    void pop_front();
    void pop_back();
    char front();
    char back();
    bool empty();
    void insert(int index, const char d);
    bool remove(int index);
    int find(char d);
    void print_list();
    int size();

};