//DO NOT CHANGE THIS FILE

#ifndef TRANSACTION_STACK_H
#define TRANSACTION_STACK_H

#include <string>
#include <iostream>
using namespace std;

struct Transaction {
  string transaction_type;  //either deposit or withdraw
  double amount;  //the amount for the related deposit or withdraw
  Transaction* under;  //point to the object in the stack under the current one
};

class TransactionStack {
  private:
    Transaction* top_;
  public:
    TransactionStack();
    ~TransactionStack();

    Transaction* top() const;
    void push(const string&, double);
    void pop();

    friend ostream& operator<<(ostream&, const TransactionStack&);
};
#endif