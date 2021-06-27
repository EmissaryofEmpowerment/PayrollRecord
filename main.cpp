#include "payroll_record.h"
#include <iostream>


using namespace std;

int main()
{
    cout << "Please enter the name of the file where you wish to write the data" << endl;
    string userInput = " ";
    cin >> userInput;
    char dot = (userInput.size()-4);
    if (userInput[(userInput.size()-4)] != '.' )
    {
        userInput += ".txt";
    }
    else if (userInput.substr((userInput.size() -4), userInput.size()) != ".txt"
    && userInput.substr((userInput.size() -4), userInput.size()) != ".doc"
    && userInput.substr((userInput.size() -4), userInput.size()) != ".pdf")

    ofstream out(userInput);
    PayRollRecord currentPayRoll;
    currentPayRoll.set_hours(53.2);
    currentPayRoll.set_name("Armstrong, Ryan");
    PayRollRecord futurePayRoll (32.3, 15.3, "Doe, John");
    cout<< endl;
    currentPayRoll.WriteData(out);
    cout<<endl;
    currentPayRoll.WriteReport(out);
    cout<<endl;
    futurePayRoll.WriteData(out);
    cout << endl;
    futurePayRoll.WriteReport(out);

   /* cout << currentPayRoll.get_first_name() + currentPayRoll.get_last_name() <<":" << endl;
    cout << "regular pay: $ " << currentPayRoll.get_pay_rate() << " per hour" << endl;
    if (currentPayRoll.get_hours() <= 40)
    {
        cout << "regular hours: " << currentPayRoll.get_hours() << endl;
    }
    else if (currentPayRoll.get_hours() > 40)
    {
        cout << "regular hours: 40.00" << endl;
        cout << "overtime pay rate: " << (currentPayRoll.get_pay_rate() * 1.5) << endl;
        cout << "overtime hours: " << (currentPayRoll.get_hours() - 40.00) <<endl;
    }
    cout << "gross pay: " << currentPayRoll.ComputeGross() << endl;*/
  return 0;
}
