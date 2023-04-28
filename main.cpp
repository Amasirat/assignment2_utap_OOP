#include <iostream>
#include "includes/creditaccount.h"
#include "includes/usr_datatypes.h"
#include "includes/funcs.h"
int main()
{
    //to count time during the program
    double start_time{double(clock())};
    start_time /= CLOCKS_PER_SEC;

    std::cout << "Welcome!\n";
    std::cout << "Please, enter \n";
    std::cout << "What can we do for you today?\n";

    return 0; 
}