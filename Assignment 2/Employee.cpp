#include "Employee.h"

/* Constructor for Professional class
   pre: a double and integer parameter are passed
   post: the monthly salary and vacation days variables in the Professional class are set
*/
Professional::Professional(double ms, int vd){
  monthly_salary = ms;
  num_vacation_days = vd;
}

/* Calculates and returns the weekly salary for the Professional employee
   pre: no parameters
   post: returned the weekly salary for the employee
*/
double Professional::weekly_salary() const{
  return monthly_salary / 4.0;    // Divides monthly salary by 4 (assumes there are 4 weeks in the month)
}

/* Calculates and returns how much the Professional employee contributes to healthcare
   pre: no parameters
   post: returned 5% of the Professional employees monthly salary 
*/
double Professional::healthcare_contribution() const{
  return monthly_salary * 0.05;    // Calculates and returns 5% if the employees monthly salary 
}

/* Returns the previously given number of vacation days for a Professional employee
   pre: no parameters
   post: returned the pre-set number of vacation days for a Professional employee
*/
int Professional::vacation_days() const{
  return num_vacation_days;    // returns the number of vacation days 
}

/* Constructor for Nonprofessional class
   pre: a double and integer parameter are passed
   post: sets the hourly rate and hours worked variables
*/
Nonprofessional::Nonprofessional(double hr, int hw){
  hourly_rate = hr;
  hours_worked = hw;
}

/* Calculates and returns the weekly salary for a Nonprofessional employee
   pre: no parameters
   post: returned Nonprofessionals calculated weekly salary
*/
double Nonprofessional::weekly_salary() const{
  return hourly_rate * hours_worked;    // returns product of the employees hourly rate and hours worked
}

/* Calculates and returns the Nonprofessionals healthcare contribution
   pre: no parameters
   post: returned 10% of the Nonprofessionals weekly salary
*/
double Nonprofessional::healthcare_contribution() const{
  return weekly_salary() * 0.1;    // Calls the weekly salary function and calculates 10% of it
}

/* Calculates and returns the Nonprofessional employees vacation days
   pre: no parameters
   post: returned the calculates vacation days
*/
int Nonprofessional::vacation_days() const{
  return hours_worked / 40; // assuming that 1 hour of vacation is given per 1 week (40 hours) of work
}
