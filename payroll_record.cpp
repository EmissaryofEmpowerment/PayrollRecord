#include "payroll_record.h"
#include <string>

PayRollRecord::PayRollRecord() : first_name_("it is"), last_name_(" unknown "), pay_rate_(7.5), hours_(0){}
PayRollRecord::~PayRollRecord() {}
PayRollRecord::PayRollRecord(double hours, double pay_rate,std::string name)
{
    hours_=hours;
    pay_rate_ = pay_rate;

}
 /*
const double PayRollRecord::kMinimumWage = 7.25;
const double PayRollRecord::kOvertimeRate = 1.5;
const double PayRollRecord::kRegularHours = 40;
 
double get_hours()
{
    return PayRollRecord::

}

double get_pay_rate()
{
    return 0.00;
}


std::string get_first_name()
{
    return "I really don't get the point of this method. \r"
    "Why is there no argument fed to this method for it to return?\r"
    "I can't modify a private data member, I can only call the get_first_name method.\r"
    "That would give me the string I need in order to give the string that this method promises.\r"
    "void set_name has a reason to justify its existence, const std::string get_first_name() does not ";
}
const std::string get_last_name()
{
    return "I really don't get the point of this method. \r"
           "Why is there no argument fed to this method for it to return?\r"
           "I can't modify a private data member, I can only call the get_last_name method.\r"
           "That would give me the string I need in order to give the string that this method promises.\r"
           "void set_name has a reason to justify its existence, const std::string get_last_name() does not ";
}
void set_hours(double hours)
{
    if (hours < .0001 || hours > 159.9999)
    {
        hours = 0;
    }
}
void set_pay_rate(double pay_rate)
{
    if (pay_rate < PayRollRecord::kMinimumWage)
    {
        pay_rate = PayRollRecord::kMinimumWage;
    }
}
void set_name(std::string name)
{
    std:: string placeHolder = " ";
    if (name.find(',') < name.size())
    {
        placeHolder = " " + name.substr(0, (name.find(',')-1)); //The last name
        name.replace((name.find(',')+2), placeHolder.size(), placeHolder); //Starting with the first letter of the first name, then space, then last name
    }
}*/

 double ComputeGross()
 {
    return 0.0;
 }