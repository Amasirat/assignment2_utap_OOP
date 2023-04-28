#include <iostream>
#include "usr_datatypes.h"
//menu for bank operations
void bank_menu()
{
    std::cout << "1.Card to Card transfer\t" << "2.Increase balance\n" 
    << "3.Show balance\t" << "4.check eligibility for profit\n";
}
//function to hash string answers of the user to determine operation
choices hash(const std::string& string)
{
    if (string == "1") return one;
    if (string == "2") return two;
    if (string == "3") return three;
    if (string == "4") return four;
    if (string == "END") return END;
}