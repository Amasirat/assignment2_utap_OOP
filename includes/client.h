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
    Client(const std::string& firstname, const std::string& lastname, 
    long int national_id, double cash, int size, CreditAccount* acc);
//default destructor
    ~Client()
    {
        delete[] m_accounts;
    }
//memeber functions
//returns overall funds of client, both in cash and credit accounts
    double funds() const;
//withdraw from account
    double withdraw(int account_id, double money);
//depsit money into account
    int deposit(int account_id, double money);
//to add accounts
    void add_account(const CreditAccount& acc);
private:
    std::string m_firstname;
    std::string m_lastname;
    long int m_national_id{};
    double m_cash{};
    CreditAccount* m_accounts;
    int m_size{};
};
#endif