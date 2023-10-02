#include "Account.h"
#include "TransactionStack.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {

  /* //Testing Transaction Stack

TransactionStack test1;

   test1.push("deposit", 1000.0);
   test1.push("withdraw", 500.0);
   test1.push("deposit", 200.0);

   cout<<test1<<endl;
   cout<<"The address of the current top of the stack is:
"<<test1.top()<<endl;

 cout<<"\n\nTesting the pop function:"<<endl;
 test1.pop();
 cout<<"after popping first element "<<test1<<endl;
 test1.pop();
 cout<<"after popping one more element "<<test1<<endl;
 test1.pop();
 cout<<"after popping the last element " <<test1<<endl;
 test1.pop();
 cout<<test1<<endl;
*/

  // create account
  Account account("SpongBob SquarePants");
  // create two TransactionStack objects, one for undo and the other for redo.
  TransactionStack undo;
  TransactionStack redo;

  // read from the transaction file and process one line at a time
  ifstream fin;
  fin.open("test1.dat");
  if (fin.is_open()) {
    cout << "File opened successfully!" << endl;
  } else {
    cout << "\nERROR, file not opened successfully!" << endl;
  }

  string command;
  double amount;

  cout << "\nBefore processing the input data file: " << account << endl;
  cout << fixed << showpoint << setprecision(2);
  while (!fin.eof()) { // while its not the end of the file we keep reading
    fin >> command;
    if (command == "deposit") { // if the command is deposit we add the money to
                                // our account
      fin >> amount;
      if (account.valid_deposit(
              amount)) { // but we first need to check that its not a negative
                         // or invalid number
        account += amount;
        undo.push("deposit", amount);
        while (redo.top() != nullptr) { // then after every deposite we empty
                                        // the entire redo stack
          redo.pop();
        }
        cout << "\nAfter processing " << command << " " << amount << ": "
             << account << endl;
        // empty the redo stack.
      } else { // if its an invalid respone
        cout << "\nInvalid deopsit is not to be undone/redone!" << endl;
      }

    } else if (command == "withdraw") { // if the command is withdraw we take
                                        // that money out of the account
      fin >> amount;
      if (account.valid_withdraw(amount)) { // but we first need to check if the
                                            // ammount is valid then we do that
        account -= amount;
        undo.push("withdraw", amount);
        while (redo.top() != nullptr) { // then after every withdraw we empty
                                        // the redo stack again
          redo.pop();
        }
      } else { // if its an invalid respone
        cout << "\nInvalid withdraw is not to be undone/redone!" << endl;
      }
      cout << "\nAfter processing " << command << " " << amount << ": "
           << account << endl;
    } else if (command == "undo") { // if the command is to undo
      if (undo.top() ==
          nullptr) { // we check that there is nothing in the undo stack first
                     // so we can see if we can undo it
        cout << "\nThe undo is empty there is no action to be taken!" << endl;
      } else { // if its not empty then we procceed with undoing
        if (undo.top()->transaction_type ==
            "withdraw") { // if the first in the stack is withdraw we add that
                          // money back in
          // reverse the top transaction
          account += undo.top()->amount;
          redo.push("withdraw", undo.top()->amount); // we push into the redo if
                                                     // we need to redo it
          undo.pop(); // then we pop from the undo
        } else {      // if it is deposite then we take that money out
          account -= undo.top()->amount;
          redo.push("deposit", undo.top()->amount); // we push into the redo if
                                                    // we need to redo it
          undo.pop();                               // then we pop from the undo
        }
      }
      cout << "\nAfter processing " << command << ": " << account << endl;
      cout << "\nThe undo stack:\n" << undo << endl;
      cout << "\nThe redo stack:\nHere are the transactions in the stack from "
              "top to bottom"
           << redo << endl;
    } else {                       // if its not undo its redo
      if (redo.top() == nullptr) { // so we check if the stack is empty or not
                                   // so we know if we can redo or not
        cout << "\nThe redo is empty there is no action to be taken!" << endl;
      } else { // if its not empty
        if (redo.top()->transaction_type ==
            "withdraw") { // we check if the first is to withdraw and we take
                          // the money out
          // we are to do apply the top again
          account -= redo.top()->amount;
          undo.push("withdraw",
                    redo.top()->amount); // we add it to the undo as the first
                                         // since its our newest action
          redo.pop(); // then we pop the the first in te redo cuz we just did it
        } else { // if its not withdraw its deposite so we add the money back in
          account += redo.top()->amount;
          undo.push("deposite", redo.top()->amount);
          redo.pop(); // then we pop the the first in te redo cuz we just did it
        }
      }
      cout << "\nAfter processing " << command << ": " << account << endl;
      cout << "\nThe undo stack:\n" << undo << endl;
      cout << "\nThe redo stack:\nHere are the transactions in the stack from "
              "top to bottom:\n"
           << redo << endl;
    }
  }

  // cout<<account<<endl;
}