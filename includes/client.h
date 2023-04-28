#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <vector>
#include "creditaccount.h"
class Client
{
public:
//default constructor
    Client();
//constructor with no default parameter
    Client(const std::string& firstname, const std::string& lastname, long int national_id, double cash);
//default destructor
    ~Client() = default;
//memebr functions
//returns overall funds of client, both in cash and credit accounts
    double funds() const;

private:
    std::string m_firstname;
    std::string m_lastname;
    long int national_id{};
    double m_cash{};
    std::vector<CreditAccount> m_accounts;
};
#endif