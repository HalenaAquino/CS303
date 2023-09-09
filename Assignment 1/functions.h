#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

void fill_array(int nums[], int arr_size);

int integer_index(int nums[], int arr_size, int searchNum);
int modify_integer(int nums[], int arr_size, int modifyIndex);
void add_integer(int nums[], int arr_size, int newInt);
void remove_index(int nums[], int arr_size, int delIndex);
void print_array(int nums[], int arr_size);