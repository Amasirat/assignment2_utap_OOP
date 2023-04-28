#ifndef FUNCS_H
#define FUNCS_H
#include "usr_datatypes.h"
#include <iostream>
//clear the terminal or command shell screen in windows
void clrscreen();
//menu for bank operations
void bank_menu();
//function to hash string answers of the user to determine operation
choices hash(const std::string& string);
//generic number getter
long int get_num();
//money getter
double get_money();
#endif