#include "payroll_record.h"
#include <iostream>
#include <array>


using namespace std;

int main()
{
    string userInput = "";
    //Perhaps lines 12-32 would be better if contained in a method in payroll_record.cpp
    cout << "Please enter the name of the file where the data is stored\r" << endl;
    cin >> userInput;
    if (userInput.find(".") < userInput.size() -4)
    {
        userInput = userInput.substr(0, userInput.find("."));
    }
    if (userInput[(userInput.size()-4)] != '.' )
    {
        userInput += ".txt";
    }
    else if (userInput.substr((userInput.size() -4), userInput.size()) != ".txt"
    && userInput.substr((userInput.size() -4), userInput.size()) != ".doc")
    {
        userInput.replace(userInput.find("."), 4, ".txt");
    }
   userInput.insert(0, "../../");
    ifstream  in(userInput);
    if (in.fail())
    {
        cout << userInput << " is not a valid file." << endl;
    }

    //Perhaps lines 35-52 would be better contained in payroll_record.cpp
    array<PayrollRecord, 32> payrolls;
    int counter = 0;
    ofstream out("../../payroll_data.txt");
    ofstream outReport("../../payroll_report.txt");
    while (in.good() == true)
    {
        double input = 0.00;
        string strInput = "";
        in >> input;
        payrolls[counter].set_hours(input);
        in >> input;
        payrolls[counter].set_pay_rate(input);
        getline(in, strInput);
        getline(in, strInput); //get past the \r hurdle
        payrolls[counter].set_name(strInput);
        payrolls[counter].WriteData(out);
        payrolls[counter].WriteReport(outReport);
        counter++;
        if (counter > payrolls.size())
        {
            std::cout << "Number of entries: " << counter << std::endl;
            break;
        }
    }
  return 0;
}
