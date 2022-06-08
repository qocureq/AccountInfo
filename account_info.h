#ifndef ACCOUNTINFO_ACCOUNT_INFO_H
#define ACCOUNTINFO_ACCOUNT_INFO_H
#include <iostream>

class account_info
{
public:
    explicit account_info(size_t _id, std::string _name, float _balance);
    void print(std::ostream& os) const;
    float getBalance();
private:
    size_t id;
    std::string name;
    float balance;

};

std::ostream& operator<<(std::ostream& os, const account_info& o);

#endif //ACCOUNTINFO_ACCOUNT_INFO_H