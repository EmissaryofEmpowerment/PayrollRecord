#include "payroll_record.h"
#include <string>
#include <iomanip>
#include <iostream>

PayrollRecord::PayrollRecord() : first_name_("it is"), last_name_(" unknown "), pay_rate_(7.5), hours_(0){}
PayrollRecord::~PayrollRecord() {}
PayrollRecord::PayrollRecord(double hours, double pay_rate,std::string name)
{
    PayrollRecord::set_hours(hours);
    PayrollRecord::set_pay_rate(pay_rate);
    PayrollRecord::set_name(name);
}

const double PayrollRecord::kMinimumWage = 7.25;
const double PayrollRecord::kOvertimeRate = 1.5;
const double PayrollRecord::kRegularHours = 40;

void PayrollRecord::set_hours(double hours)
{
    if (hours < .0001 || hours > 159.9999)
    {
        hours = 0;
        hours_ = hours;
    }
    hours_ = hours;
}
void PayrollRecord::set_pay_rate(double pay_rate)
{
    if (pay_rate <  PayrollRecord::kMinimumWage)
    {
        pay_rate_ = PayrollRecord::kMinimumWage;
    }
    else
    {
        pay_rate_ = pay_rate;
    }

}
void PayrollRecord::set_name(std::string name)
{
    if (name.find(",") < 0 || name.find(",") > name.size()) // comma not found
    {
        if (name.find(" ") < 0 || name.find(" ") > name.size()) // space not found, comma not found
        {
            if (name.find(".") != std::string::npos) // period but no space nor comma
            {
                first_name_ = name.substr(0,name.find("."));
                while (first_name_.find("\r") != std::string::npos)
                {
                    first_name_.erase(first_name_.find("\r"));
                }
                while (first_name_.find("\n") != std::string::npos)
                {
                    first_name_.erase(first_name_.find("\n"));
                }
                last_name_ = name.substr(name.find(".") + 1, name.size());
                while (last_name_.find("\r")!= std::string::npos)
                {
                    last_name_.erase(last_name_.find("\r"));
                }
                while (last_name_.find("\n") !=std::string::npos)
                {
                    last_name_.erase(last_name_.find("\n"));
                }

            }
            first_name_ = name;
            while (first_name_.find(" ") != std::string::npos)
            {
                first_name_.erase(first_name_.find(" "));
            }
            while (first_name_.find("\r") != std::string::npos)
            {
                first_name_.erase(first_name_.find("\r"));
            }
            while (first_name_.find("\n") != std::string::npos)
            {
                first_name_.erase(first_name_.find("\n"));
            }
            last_name_ = " ";
        }
        else  //it has a space but no comma
        {
            if (name.find(".") != std::string::npos) // space, period, but no comma
            {
                first_name_ = name.substr(0,name.find("."));
                while (first_name_.find("\r")!= std::string::npos)
                {
                    first_name_.erase(first_name_.find("\r"));
                }
                while (first_name_.find("\n") != std::string::npos)
                {
                    first_name_.erase(first_name_.find("\n"));
                }
                last_name_ = name.substr(name.find(".") + 2, name.size());
                while (last_name_.find(" ") !=std::string::npos)
                {
                    last_name_.erase(last_name_.find(" "));
                }
                while (last_name_.find("\r")!= std::string::npos)
                {
                    last_name_.erase(last_name_.find("\r"));
                }
                while (last_name_.find("\n") !=std::string::npos)
                {
                    last_name_.erase(last_name_.find("\n"));
                }
            }
            else if (name.find(".") == std::string::npos)//space, no period, no comma
            {
                first_name_ = name.substr(0, name.find_last_of(" "));
                while (first_name_.find("\r") != std::string::npos) {
                    first_name_.erase(first_name_.find("\r"));
                }
                while (first_name_.find("\n") != std::string::npos) {
                    first_name_.erase(first_name_.find("\n"));
                }
                last_name_ = name.substr(name.find_last_of(" ") + 1, name.size());
                while (last_name_.find(" ") != std::string::npos) {
                    last_name_.erase(last_name_.find(" "));
                }
                while (last_name_.find("\r") != std::string::npos) {
                    last_name_.erase(last_name_.find("\r"));
                }
                while (last_name_.find("\n") != std::string::npos) {
                    last_name_.erase(last_name_.find("\n"));
                }
            }
        }
    }
    else// comma found
    {
        if (name.find(" ") < 0 || name.find(" ") > name.size())// comma but no space
        {
            if (name.find(".") != std::string::npos)// comma, period, but no space
            {
                first_name_ = name.substr(name.find(",")+ 1, name.size() );
                last_name_ = name.substr(0,name.find(","));
            }
            else if (name.find(".") == std::string::npos) // comma but no period nor space
            {
                first_name_ = name.substr(name.find(",") + 1, name.size());
                while (first_name_.find("\r") != std::string::npos) {
                    first_name_.erase(first_name_.find("\r"));
                }
                while (first_name_.find("\n") != std::string::npos) {
                    first_name_.erase(first_name_.find("\n"));
                }
                last_name_ = name.substr(0, name.find(","));
                while (last_name_.find(" ") != std::string::npos) {
                    last_name_.erase(last_name_.find(" "));
                }
                while (last_name_.find("\r") != std::string::npos) {
                    last_name_.erase(last_name_.find("\r"));
                }
                while (last_name_.find("\n") != std::string::npos) {
                    last_name_.erase(last_name_.find("\n"));
                }
            }
        }
        else // space and comma
        {
            last_name_ = name.substr(0, name.find(','));
            while (last_name_.find(" ") != std::string::npos)
            {
                last_name_.erase(last_name_.find(" "));
            }
            while (last_name_.find("\r") != std::string::npos)
            {
                last_name_.erase(last_name_.find("\r"));
            }
            while (last_name_.find("\n") != std::string::npos)
            {
                last_name_.erase(last_name_.find("\n"));
            }
            first_name_ = name.substr((name.find(",")+2), name.size());
            while (first_name_.find("\r") != std::string::npos)
            {
                first_name_.erase(first_name_.find("\r"));
            }
            while (first_name_.find("\n") != std::string::npos)
            {
                first_name_.erase(first_name_.find("\n"));
            }
        }
    }

}
 double PayrollRecord::ComputeGross() const
 {
    double gross = 0.00;
    if (hours_ <= PayrollRecord::kRegularHours)
     {
        gross = hours_ * pay_rate_;
        return gross;
     }
    else //if (hours_ > PayrollRecord::kRegularHours)
    {
        gross = pay_rate_ * PayrollRecord::kRegularHours;
        gross +=  (hours_-PayrollRecord::kRegularHours) * (pay_rate_ * PayrollRecord::kOvertimeRate);
        return gross;
    }
 }
 void PayrollRecord::WriteData (std::ostream& out) const
 {
     out << std::left << std::fixed << std::setprecision(2) << hours_ << " " << pay_rate_ << " " << ComputeGross() << std::endl
         << last_name_ << ", " << first_name_ << std::endl;
 }
 void PayrollRecord::WriteReport(std::ostream &outReport) const
 {
    outReport <<  first_name_ << " "<< last_name_ <<std::endl
    << "  " << "Hours Worked: " << std::left << std::fixed << std::setprecision(2) << hours_ << std::endl
    << "  " << "Pay Rate: $" << pay_rate_ << std::fixed << std::setprecision(2) << std::endl
    << "  " << "Gross Pay: $" << ComputeGross() << std::endl;
 }