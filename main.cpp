#include "includes/database.h"

#include "includes/config.h"

#include "includes/creditaccount.h"

#include "includes/usr_datatypes.h"

#include "includes/funcs.h"

#include <iostream>       


int main()
{
    //to count time during the program
    double start_time{double(clock())};
    start_time /= CLOCKS_PER_SEC;

    int db_count{0};    //id of account in database, using vector indexes
    bool program_end = false;

    std::cout << "Welcome!\n";
    std::cout << "Please, enter an account of your choosing by entering your card number:\n";

    while(true)
    {
        long int number{get_num()};
        bool acc_found = false;
        while(db_count < DB_accounts.size())
        {
            if (number == DB_accounts[db_count].number)
            {
                acc_found = true;
                break;
            } 
            else  
                ++db_count;
        }

        if(acc_found)
        {
            std::cout << "Please enter your password:\n";
            int password{};
                while(std::cin >> password && (!(DB_accounts[db_count].password == password)))
                {
                    std::cin.ignore();
                    std::cin.clear();
                    std::cout << "Your password is incorrect\n";
                }
            break;
        }
        else
        {
            std::cout << "account was not found, please enter a correct number. "
            "If you're sure the number was correct, "
            "contact your bank for help with this situation\n";
        }
    }

    CreditAccount usr_acc
    {
        DB_accounts[db_count].number, 
        DB_accounts[db_count].password, 
        DB_accounts[db_count].balance,
        PROFIT_MARGIN
    };

    clrscreen();    //clear screen before entering main interface

    while(!program_end)
    {
    //bank's main interface
        std::cout << "What can we do for you today?\n";
        bank_menu();
        std::string usr_op; //operation determiner of the program
        std::getline(std::cin >> std::ws, usr_op);
        switch(hash(usr_op))
        {
            case one:
            {
                std::cout << "Please enter desired account number:\n";
                long int number{get_num()};
                break;
            }
            case two:
            {
                double money{get_money()};
                usr_acc.increase_balance(money);
                break;
            }
            case three:
            {
                usr_acc.show_balance();
                break;
            }
            case four:
            {
                break;
            }
            case END:
            {
                program_end = true;
                break;
            }
            default:
                std::cin.clear();
                std::cin.ignore();
                std::cout << "input is invalid\n";
        }
    }
    return 0; 
}