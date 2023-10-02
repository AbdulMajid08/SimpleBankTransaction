#include "TransactionStack.h"
#include <iomanip>
#include <string>
using namespace std;

TransactionStack::TransactionStack() {
  this->top_ = nullptr;
  // this->top_->under =nullptr;
}

TransactionStack::~TransactionStack() {
  // cout<<"\nReleasing from stack"<<endl;

  while (this->top_ != nullptr) {
    // Transaction* temp = this->top_;
    cout << "\nReleasing from stack: Transaction Type: "
         << this->top_->transaction_type << "\tAmmount: " << this->top_->amount
         << endl;
    ;
    // this->top_ = this->top_->under;
    // delete temp;
    pop();
  }
  // I hope I am right ask
}

void TransactionStack::push(const string &type, double amount) {

  Transaction *new_transaction = new Transaction{
      type, amount}; // new node that is holding whats being pushed in

  if (this->top_ == nullptr) {        // if we have an empty list
    this->top_ = new_transaction;     // we reset the top to our new node
    new_transaction->under = nullptr; // the under stays null
  } else {                            // if we dont have an empty list
    // Transaction *temp = this->top_; // creat a new temp to hold the top
    new_transaction->under = top_;
    top_ = new_transaction;
  }

  // I think I am right but not sure ask
}

ostream &operator<<(ostream &lhs, const TransactionStack &ts) {
  Transaction *ptr = ts.top_;
  if (ptr == nullptr) { // when the stack is empty
    lhs << "\nThe Stack is empty!" << endl;
  } else { // when its not empty
    while (ptr != nullptr) {
      lhs << "\nTransaction Type: " << ptr->transaction_type
          << "\tAmmount: " << ptr->amount << endl;
      ptr = ptr->under;
    }
  }
  return lhs;
}

Transaction *TransactionStack::top() const {
  return this->top_;
  // I dont know if I am right askt
}

void TransactionStack::pop() {

  // when its the only thing inside
  // when there is nothing inside
  // when its not the only thing inside
  Transaction *temp = this->top_;
  if (this->top_ == nullptr) {
    cout << "\nEmpty Stack nothing can be popped!" << endl;
  } // else if(this->top_ == temp->under){ // When its the only thing in the
    // list
    //  this->top_ = temp->under = nullptr;
  //}
  else { // When its not the only thing in the stack
    this->top_ = top_->under;
    delete temp;
  }

  // I think this works but ask also LETS GO did the first part good job
}