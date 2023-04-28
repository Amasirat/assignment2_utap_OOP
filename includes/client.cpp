#include "client.h"
#include "database.h"
#include <vector>

Client::Client() : m_firstname{"John"}, m_lastname{"Doe"}, m_cash{15.5}, 
m_national_id{2730308253}, m_size{1}
{
    m_accounts = new CreditAccount[m_size];
    CreditAccount default_acc{};
    m_accounts[0] = default_acc;
}
Client::Client(const std::string& firstname, const std::string& lastname, 
long int national_id, double cash, int size, CreditAccount* acc) : m_firstname{firstname},
m_lastname{lastname}, m_national_id{national_id}, m_cash{cash}, m_size{size}
{
    m_accounts = new CreditAccount[m_size];
    for (int i{0}; i < m_size; ++i)
    {
        m_accounts[i] = acc[i];
    }
}
double Client::funds() const
{
    double sum{0};
    for(int i{0}; i < m_size; ++i)
    {
        sum += m_accounts[i].balance();
    }
    return sum += m_cash;
}
double Client::withdraw(int account_id, double money)
{
    double withdrawn{};
    withdrawn = m_accounts[account_id].withdraw(money);
    if(withdrawn > 0)//meaning if it's not -1 which is the fail state of the withdrawn method
    {
        m_cash += withdrawn;
        return withdrawn;
    }
    else
    {
        std::cout << "There's not enough balance in your account\n";
        return -1;
    }  
}
int Client::deposit(int account_id, double money)
{
    if(m_cash < money)
    {
        std::cout << "You don't have enough cash\n";
        return -1;
    }
    else
    {
        m_cash -= money;
        m_accounts[account_id].increase_balance(money);
        return 0;
    }
}
void Client::add_account(const CreditAccount& acc)
{
    ++m_size;
    m_accounts[m_size - 1] = acc;
}