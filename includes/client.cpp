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
long int national_id, double cash, int size) : m_firstname{firstname},
m_lastname{lastname}, m_national_id{national_id}, m_cash{cash}, m_size{size}
{
    m_accounts = new CreditAccount[m_size];
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