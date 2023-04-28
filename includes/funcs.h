#ifndef FUNCS_H
#define FUNCS_H
#include "usr_datatypes.h"
#include <iostream>
//menu for bank operations
void bank_menu();
//function to hash string answers of the user to determine operation
choices hash(const std::string& string);
#endif