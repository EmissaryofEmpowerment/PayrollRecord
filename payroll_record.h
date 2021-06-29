#ifndef payroll_record_H
#define payroll_record_H
#include <string>
#include <fstream>

class PayrollRecord
{
public:
    PayrollRecord();
    PayrollRecord(double hours, double pay_rate,std::string name);
    ~PayrollRecord();
    static const double kMinimumWage;
    static const double kRegularHours;
    static const double kOvertimeRate;
    double get_hours() const {return hours_;}
    double get_pay_rate() const {return pay_rate_;}
    std::string get_first_name() const {return first_name_;};
    std::string get_last_name() const {return last_name_;};
    void set_hours(double hours);
    void set_pay_rate(double pay_rate);
    void set_name(std::string name);
    double ComputeGross() const;
    void WriteData(std::ostream& out) const;
    void WriteReport(std::ostream& outReport) const;
private:
    double hours_;
    double pay_rate_;
    std::string first_name_;
    std::string last_name_;
};
#endif