#include "account_info.h"
#include <iomanip>

account_info::account_info(size_t _id, std::string _name, float _balance) {
    id = _id;
    name = std::move(_name);
    balance = _balance;
}

void account_info::print(std::ostream& os) const {
    os << std::right << std::setw(5) << id
       << std::right << std::setw(15 ) << name
       << std::right << std::setw(10) << std::fixed << std::setprecision(2) << balance << "\n";
}

float account_info::getBalance() {
    return balance;
}


std::ostream& operator<<(std::ostream& os, const account_info& o) {
    o.print(os);
    return os;
}
