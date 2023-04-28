#include <iostream>
#include "creditaccount.h"
//constructor definiton with given default parameters
CreditAccount::CreditAccount(long int number, int password, double balance, double profit_margin)
: m_number{number}, m_password{password}, m_balance{balance}, m_profit_margin{profit_margin}
{}
//destructor
CreditAccount::~CreditAccount()
{
    std::cout << "Thanks for using our banking services\n";
}
void CreditAccount::show_balance() const
{
    std::cout << "Balance: " << m_balance << "$\n";
}
//getters definitions
double CreditAccount::balance(){return m_balance;}
long int CreditAccount::number(){return m_number;}
//to check if given password matches password of object
bool CreditAccount::check_pass(int pass) const
{
    return m_password == pass;
}
//card to card transfer, returns 0 if successful and 1 if not
int CreditAccount::transfer(CreditAccount& card, double money)
{
    if(m_balance < money)
        return 1;   //1 for unsuccessful transaction
    else
    {
        card.increase_balance(money);
        m_balance -= money;
        return 0;   //0 for successful transaction
    }
}
//general fuction for increasing balance inside a CreditAccount object
void CreditAccount::increase_balance(double money)
{
    m_balance += money;
    std::cout << money << "$ has been added to balance\n";
}
//bank's credit card profit system
void CreditAccount::profit(double time_elapsed)
{
//after how much time in seconds passes should profit be added to account
    const int profit_time{60};
//count how many times profit_addition should be performed
    int profit_count{(int)(time_elapsed * 10000) / profit_time};
    if (profit_count == 0)
    {
        std::cerr << time_elapsed << '\n';
        std::cout << "You're not eligible for profits, " << m_profit_margin << 
        " percent profit will be added to account after each " << profit_time << " seconds passes\n";
    }
    else
    {
std::cerr << "profit count: " << profit_count << '\n';
        double profit{m_balance * (m_profit_margin / 100)};
        for(int count{0}; count < profit_count; ++count)
        {
            m_balance += profit;
        }
std::cerr << "profit count: " << profit_count << '\n';
        std::cout << profit * profit_count << "$ was added to account\n";
    }
}
double CreditAccount::withdraw(double money)
{
    if(m_balance < money)
        return -1;
    else
    {
        m_balance -= money;
        return money;
    }
}
