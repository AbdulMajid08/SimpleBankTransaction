//DO NOT CHANGE THIS FILE
#ifndef ACCCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
  private:
    string name_;
    double balance_;
  public:
    Account(const string&);
    bool valid_deposit(double) const;
    bool valid_withdraw(double) const;
    Account& operator+=(double);
    Account& operator-=(double);
    friend ostream& operator<<(ostream&, const Account&);
};

#endif