#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H
#include "config.h"
class CreditAccount
{
public:
//constructor with default given parameters
    CreditAccount(long int number = 6037997236372558, int password = 2558, 
    double balance = 0, double profit_margin = PROFIT_PERCENTAGE);
//destructor gives a thank you message when going out of scope
    ~CreditAccount();
//getters
    void show_balance() const;
//member functions
//to check if given password matches password of object
    bool check_pass(int pass) const;
//card to card transfer, returns 0 if successful and 1 if not
    int transfer(CreditAccount& card, double money);
//general fuction for increasing balance inside a CreditAccount object
    void increase_balance(double money);
//bank's credit card profit system
    void profit(double time_elapsed);
private:
    long int m_number{};
    int m_password{};
    double m_balance{};
    double m_profit_margin{};
};
#endif