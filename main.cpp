#include <iostream>
#include <iomanip>
#include <random>
#include "account_info.h"

account_info ** generateAccounts(account_info ** accounts)
{
    std::random_device rd;
    std::mt19937 randomBalance(rd());
    std::uniform_real_distribution<float> distr(-1000, 3000);

    size_t id = 1000;
    float balance;

    const char* names[]
            = { "Nowak", "Kowalski", "Wisniewski", "Wojcik", "Kowalczyk", "Kaminski", "Lewandowski", "Zielinski", "Szymanski","Wozniak" };

    for (int i = 0; i < std::size(names); ++i) {
        balance = distr(randomBalance);
        accounts[i] = new account_info(id++, names[i], balance);
    }
    return accounts;
}

void printAccountInfo(account_info ** accounts)
{
    for (int i = 0; i < sizeof accounts; ++i) {
        std::cout << *accounts[i];
    }
}

void catchNegativeBalanceException(account_info ** accounts)
{
    std::string exception;
    for (int i = 0; i < sizeof accounts; ++i) {
        try{
            if((accounts[i]->getBalance() < 0))
                throw std::out_of_range(exception);
        }
        catch (std::out_of_range &exc){
            if(exc.what() == exception)
                std::cout << "\033[0;31mNegative Balance: " << accounts[i]->getBalance() << "\n";
        }

    }
}
int main()
{
    size_t n = 10;
    auto **accounts = new account_info*[n];

    std::cout << std::right << std::setw(5) << "ID"
              << std::right << std::setw(15 ) << "NAME"
              << std::right << std::setw(10) << "BALANCE" << "\n";

    generateAccounts(accounts);
    printAccountInfo(accounts);
    catchNegativeBalanceException(accounts);

    return 0;
}