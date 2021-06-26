#include "payroll_record.h"
#include <iostream>


using namespace std;

int main()
{
    PayRollRecord currentPayRoll;
    PayRollRecord futurePayRoll (32.3, 15.3, "Roger");
    double gross;
    gross = currentPayRoll.get_hours();
   // gross = PayRollRecord::ComputeGross();
   cout << gross << " gross" << endl;
  return 0;
}
