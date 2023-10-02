//DO NOT CHANGE THIS FILE

#include "Account.h"
#include <iomanip>
using namespace std;

//This constrcutor creates an Account object using the provided name.
//The initial balance for a new account is set to $0.
Account::Account(const string& name) {
  this->name_ = name;
  this->balance_ = 0;
}

//This function returns true if an amount is appropriate for a deposit request.
bool Account::valid_deposit(double amount) const {
  return amount > 0;
}

//This function returns true if an amount is apporiate for a withdraw request.
bool Account::valid_withdraw(double amount) const {
  return amount > 0 && amount <= this->balance_;
}

//This function makes a deposit to the invoking Account object.
//It assumes that the deposit_amount is valid.
Account& Account::operator+=(double deposit_amount) {
  this->balance_ += deposit_amount;
  return *this;
}

//This function makes a withdrawal from the invoking Account object.
//It assumes that the withdrawal_amount is valid.
Account& Account::operator-=(double withdrawal_amount) {
  this->balance_ -= withdrawal_amount;
  return *this;
}

//This function displays the name and balance of an account.
ostream& operator<<(ostream& output, const Account& a) {
  output << fixed << showpoint << setprecision(2);
  output << a.name_ << ", your balance is $" << a.balance_ << ".";
  return output;
}