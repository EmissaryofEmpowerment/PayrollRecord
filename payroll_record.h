#ifndef PayRoll_H
#define PayRoll_H
#include <string>
class PayRoll
{
private:
    double hours_;
    double pay_rate_;
    std::string first_name;
    std::string last_name;
public:
    static const double kMinimumWage;
    static const double kRegularHours;
    static const double kOvertimeRate;


};
#endif