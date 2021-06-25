#ifndef PayRoll_H
#define PayRoll_H
#include <string>
class PayRoll
{
public:
    PayRoll();
    PayRoll(double hours, double pay_rate,std::string name);
    ~PayRoll();
    static const double kMinimumWage_;
    static const double kRegularHours_;
    static const double kOvertimeRate_;
    double get_hours() const;
    double get_pay_rate() const;
    std::string get_first_name() const;
    std::string get_last_name() const;
    void set_hours(double hours);
    void set_pay_rate(double pay_rate);
    void set_name(std::string name);
private:
    double hours_;
    double pay_rate_;
    std::string first_name_;
    std::string last_name_;


};
#endif