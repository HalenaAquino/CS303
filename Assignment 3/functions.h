#include <stack>
#include <string>

using namespace std;

bool open(char c);
bool closed(char c);
bool balanced(const string& str);


int get_order(char op);
string inf_to_postf(string inf);
