#include "payroll_record.h"
#include <string>
#include <iomanip>
#include <iostream>

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
            last_name_ = name.substr(name.find(" ")+1, name.size());
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
            first_name_ = name.substr((name.find(",") + 2), name.size());
            if (first_name_[0] == ' ')
            {
                first_name_ = first_name_.substr(1, first_name_.size());
            }
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
        pay_rate_ = 7.5; //PayRollRecord::kMinimumWage;
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
            last_name_ = name.substr(name.find(" ") + 3, name.size());

            last_name_.replace(name.find(" "), 1, "");
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
            first_name_ = name.substr((name.find(",")+2), name.size());
        }
    }

}
 double PayRollRecord::ComputeGross ()
 {
    double gross;
    if (hours_ < 0.00)
    {
         hours_ = 0.00;
         gross = 0.00;
        return gross;
    }
    else if (hours_ < 40.00)//kRegularHours
     {
        gross = hours_ * pay_rate_;
        return gross;
     }
    else if (hours_ > 40.0)//kRegularHours) //overtime
    {
        gross = pay_rate_ * 40.00;//kRegularHours
        gross += (hours_-40.00)/*kRegularHours)*/ * (pay_rate_ * 1.5/*kOvertime rate */);
        return gross;
    }
    return 0.0;
 }
 void PayRollRecord::WriteData (std::ostream& out)
 {
     out << std::left << std::fixed << std::setprecision(2) <<hours_ << " " << pay_rate_ << " " << ComputeGross() << std::endl
         << last_name_ << ", " << first_name_ << std::endl;
     std::cout << std::left << std::fixed << std::setprecision(2) <<hours_ << " " << pay_rate_ << " " << ComputeGross() << std::endl
                              << last_name_ << ", " << first_name_ << std::endl;
 }
 void PayRollRecord::WriteReport(std::ostream &out)
 {
    out <<  first_name_ << " "<< last_name_ <<std::endl
    << "  " << "Hours Worked: " << std::left << std::fixed << std::setprecision(2) << std::endl
    << "  " << "Pay Rate: $" << pay_rate_ << std::fixed << std::setprecision(2) << std::endl
    << "  " << "Gross Pay: $" << ComputeGross() << std::endl;
    std::cout<<  first_name_ << " "<< last_name_ <<std::endl
             << "  " << "Hours Worked: " << std::left << std::fixed << std::setprecision(2) << hours_ << std::endl
             << "  " << "Pay Rate: $" << pay_rate_ << std::fixed << std::setprecision(2) << std::endl
             << "  " << "Gross Pay: $" << ComputeGross() << std::endl;
 }