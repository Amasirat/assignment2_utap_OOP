#include <vector>


#include "includes/config.h"

#include "includes/creditaccount.h"

#include "includes/usr_datatypes.h"

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
//finding account in database
int find_account(long int number);

std::vector<Account> DB_accounts{{6037997237360558, 3265, 5}, {6037645215487945, 6452, 7}};

int main()
{
    //to count time during the program
    double start_time{CLOCK_REALTIME};

    int db_id{0};    //id of account in database, using vector indexes
    bool program_end = false;

    std::cout << "Welcome!\n";
    std::cout << "Please, enter an account of your choosing by entering your card number:\n";

    while(true)
    {
        long int number{get_num()};
        bool acc_found = false;
        while(db_id < DB_accounts.size())
        {
            if (number == DB_accounts[db_id].number)
            {
                acc_found = true;
                break;
            } 
            else  
                ++db_id;
        }

        if(acc_found)
        {
            std::cout << "Please enter your password:\n";
            int password{};
                while(std::cin >> password && (!(DB_accounts[db_id].password == password)))
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
        DB_accounts[db_id].number, 
        DB_accounts[db_id].password, 
        DB_accounts[db_id].balance,
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
                int db_index{};
                std::cout << "Please enter desired account number:\n";
                long int number{get_num()};
                int card_id{find_account(number)};

                if(card_id == -1)
                {
                    std::cout << "Number was incorrect, contact bank support for further information\n";
                }
                else if (card_id == db_id)
                {
                    std::cout << "transfer to the same account is not allowed\n";
                }
                else
                {
                    CreditAccount card
                    {
                        DB_accounts[card_id].number,
                        DB_accounts[card_id].password,
                        DB_accounts[card_id].balance,
                        PROFIT_MARGIN
                    };
                    double money{get_money()};
                    //transfer is taken place and its state is stored inside a variable
                    int transfer_state {usr_acc.transfer(card, money)}; 
                    if(transfer_state == 0)
                    {
                        std::cout << "transaction was successful\n";
                    }
                    else
                    {
                        std::cout << "transaction was unsuccessful\n";
                    }
                }
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
                double time_elapsed {((double)clock()) / CLOCKS_PER_SEC - start_time};
                usr_acc.profit(time_elapsed);
                time_elapsed = 0;
                break;
            }
            case five:
            {
                clrscreen();
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
    << "3.Show balance\n" << "4.check eligibility for profit\n" << "5.clear screen\n" << 
    "END. Terminate Program'\n";
}
//function to hash string answers of the user to determine operation
choices hash(const std::string& string)
{
    if (string == "1") return one;
    else if (string == "2") return two;
    else if (string == "3") return three;
    else if (string == "4") return four;
    else if (string == "5") return five;
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
//finding account in database
int find_account(long int number)
{
    for(int i{0}; i < DB_accounts.size(); ++i)
    {
        if(DB_accounts[i].number == number)
            return i;
    }
    return -1;
}