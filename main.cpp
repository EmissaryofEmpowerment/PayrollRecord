#include "payroll_record.h"
#include <iostream>


using namespace std;

int main()
{
    PayRollRecord currentPayRoll;
    currentPayRoll.set_name("Roger Pack");
    PayRollRecord futurePayRoll (32.3, 15.3, "RogerPack");
    double gross;
    gross = currentPayRoll.get_hours();

   // gross = PayRollRecord::ComputeGross();
   cout << gross << " gross" << endl;
   currentPayRoll.set_name(currentPayRoll.get_first_name() + currentPayRoll.get_last_name());
   cout << futurePayRoll.get_first_name()<< " or " << currentPayRoll.get_first_name() <<" is the first name" <<endl;
   cout << futurePayRoll.get_last_name() << " or " << currentPayRoll.get_last_name() <<" is the last name" << endl;
  return 0;
}
