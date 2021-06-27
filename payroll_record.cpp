#include "payroll_record.h"
#include <string>

PayRollRecord::PayRollRecord() : first_name_("it is"), last_name_(" unknown "), pay_rate_(7.5), hours_(0){}
PayRollRecord::~PayRollRecord() {}
PayRollRecord::PayRollRecord(double hours, double pay_rate,std::string name)
{
    hours_=hours;
    pay_rate_ = pay_rate;
    if (name.find(",") < 0 || name.find(",") > name.size()) // comma not found
    {
        if (name.find(" ") < 0 || name.find(" ") > name.size()) // space not found, comma not found
        {
            first_name_ = name;
            last_name_ = " ";
        }
        else  //it has a space but no comma
        {
            first_name_ = name.substr(0,name.find(" "));
            last_name_ = name.substr(name.find(" "), name.size()); //include a " " before last_name_
        }
    }
    else// comma found
    {
        if (name.find(" ") < 0 || name.find(" ") > name.size())// comma but no space
        {
            first_name_ = name.substr(name.find(",")+1, name.size());
            last_name_ = " " + name.substr(0, name.find(","));
        }
        else // space and comma
        {
            last_name_ = name.substr(0, name.find(','));
            first_name_ = name.substr(name.find("," + 2), name.size());
        }
    }

}
 /*
const double PayRollRecord::kMinimumWage = 7.25;
const double PayRollRecord::kOvertimeRate = 1.5;
const double PayRollRecord::kRegularHours = 40;
 */
double PayRollRecord::get_hours() {
    return hours_;

}

double PayRollRecord::get_pay_rate()
{
    return pay_rate_;
}


std::string PayRollRecord::get_first_name()
{
    return first_name_;
}
 std::string PayRollRecord::get_last_name()
{
    return last_name_;
}

void PayRollRecord::set_hours(double hours)
{
    if (hours < .0001 || hours > 159.9999)
    {
        hours = 0;
        hours_ = hours;
    }
    hours_ = hours;
}
void PayRollRecord::set_pay_rate(double pay_rate)
{
    if (pay_rate <  7.5)//PayRollRecord::kMinimumWage)
    {
        pay_rate_ = 7; //PayRollRecord::kMinimumWage;
    }
    else
    {
        pay_rate_ = pay_rate;
    }

}
void PayRollRecord::set_name(std::string name)
{
    if (name.find(",") < 0 || name.find(",") > name.size()) // comma not found
    {
        if (name.find(" ") < 0 || name.find(" ") > name.size()) // space not found, comma not found
        {
            first_name_ = name;
            last_name_ = " ";
        }
        else  //it has a space but no comma
        {
            first_name_ = name.substr(0,name.find(" "));
            last_name_ = name.substr(name.find(" "), name.size()); //include a " " before last_name_
        }
    }
    else// comma found
    {
        if (name.find(" ") < 0 || name.find(" ") > name.size())// comma but no space
        {
            first_name_ = name.substr(name.find(",")+1, name.size());
            last_name_ = name.substr(0, name.find(","));
        }
        else // space and comma
        {
            last_name_ = name.substr(0, name.find(','));
            first_name_ = name.substr(name.find("," + 2), name.size());
        }
    }

}

 double ComputeGross()
 {
    return 0.0;
 }