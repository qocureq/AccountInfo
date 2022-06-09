#include <iostream>
#include <iomanip>
#include <random>
#include "account_info.h"

#define LEN 10

account_info ** generateAccounts(account_info ** accounts)
{
    std::random_device rd;
    std::mt19937 randomBalance(rd());
    std::uniform_real_distribution<float> range(-1000, 3000);

    size_t id = 1000;
    float balance;

    const char* names[LEN]
            = { "Nowak", "Kowalski", "Wisniewski", "Wojcik", "Kowalczyk", "Kaminski", "Lewandowski", "Zielinski", "Szymanski","Wozniak" };

    for (int i = 0; i < LEN; ++i) {
        balance = range(randomBalance);
        accounts[i] = new account_info(id++, names[i], balance);
    }
    return accounts;
}

void printAccountInfo(account_info ** accounts)
{
    for (int i = 0; i < LEN; ++i) {
        std::cout << *accounts[i];
    }
}

void catchNegativeBalanceException(account_info ** accounts)
{
    std::string exception;
    for (int i = 0; i < LEN; ++i) {
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
    auto **accounts = new account_info*[LEN];

    std::cout << std::right << std::setw(5) << "ID"
              << std::right << std::setw(15 ) << "NAME"
              << std::right << std::setw(10) << "BALANCE" << "\n";

    generateAccounts(accounts);
    printAccountInfo(accounts);
    catchNegativeBalanceException(accounts);

    delete[] accounts;

    return 0;
}