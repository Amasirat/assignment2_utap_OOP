#include <iostream>
#include "usr_datatypes.h"
//clear the terminal or command shell screen in windows
void clrscreen()
{
    #ifdef WINDOWS
        system("cls");
    #else 
        system("clear");
    #endif
}
//menu for bank operations
void bank_menu()
{
    std::cout << "1.Card to Card transfer\n" << "2.Increase balance\n" 
    << "3.Show balance\n" << "4.check eligibility for profit\n" << "clear screen\n";
}
//function to hash string answers of the user to determine operation
choices hash(const std::string& string)
{
    if (string == "1") return one;
    else if (string == "2") return two;
    else if (string == "3") return three;
    else if (string == "4") return four;
    else if (string == "END") return END;
    else    return empty;
}
//general number getter
long int get_num()
{
    long int num{};
    while(std::cin >> num && (num < 0 || std::cin.fail()))
    {
        std::cin.ignore();
        std::cin.clear();
        std::cout << "input is invalid\n";
    }
    return num;
}
//get money
double get_money()
{
    std::cout << "Please enter the amount of money:\n";
    int num{};
    while(std::cin >> num && num < 0 || std::cin.fail())
    {
        std::cin.ignore();
        std::cin.clear();
        std::cout << "money inputted is invalid\n";
    }
    return num;
}