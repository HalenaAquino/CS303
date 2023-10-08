#include <iostream>

using namespace std;

class Employee {
public:

    virtual double weekly_salary() const = 0;
    virtual double healthcare_contribution() const = 0;
    virtual int vacation_days() const = 0;

};

class Professional : public Employee {
public:
    Professional(double ms, int vd);
    double weekly_salary() const override;
    double healthcare_contribution() const override;
    int vacation_days() const override;

private:
    double monthly_salary;
    int num_vacation_days;
};

class Nonprofessional : public Employee {
public:
    Nonprofessional(double hr, int hw);
    virtual double weekly_salary() const override;
    virtual double healthcare_contribution() const override;
    virtual int vacation_days() const override;

private:
    double hourly_rate;
    int hours_worked;
};
