#include <stack>
#include <string>
#include <iostream>

using namespace std;

// Function declarations 
bool open(char c);
bool closed(char c);
bool balanced(const string& str);
string balance(const string& str);


int get_order(char op);
string inf_to_postf(string inf);
bool isOperator(char c);
string postf_to_inf(const string& postf);

void menu(int &choice);

