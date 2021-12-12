//
//  brass.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/12.
//

#include "brass.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass methods
Brass::Brass(const string & s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if(amt < 0) {
        cout << "Negative deposit not allowed; " << "deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    if(amt < 0){
        cout << "Withdrawl amoit must be positve;" << "withdrawal cancelled.\n";
    } else if(amt <= balance) {
        balance -= amt;
    } else {
        cout << "Withdrawal amount of $" << amt
            << " execeeds your balance.\n"
        << "Withdrawal cancelled.\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const{
    return balance;
}

void Brass::ViewAcct() const
{
    cout << "Brass::ViewAcct()";
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number:" << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

void Brass::Name(){
    std::cout << "Brass : " << fullName << std::endl;
}


BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : Brass(s, an, bal){
    maxLoad = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : Brass(ba){
    maxLoad = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    cout << "BrassPlus::ViewAcct()";
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Maximum loan: $:" << maxLoad << endl;
    cout << "Owed to bank:$ " << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate:" << 100*rate<<"%\n";
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    double bal = Balance();
    if(amt <= bal) {
        Brass::Withdraw(amt);
    } else if(amt <= bal + maxLoad - owesBank) {
        double advance = amt - bal;
        owesBank += advance *(1.0 +rate);
        cout << "Bank advacnce: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}

void BrassPlus::Name(){
    std::cout << "BrassPlus : " << fullName << std::endl;
}

format setFormat(){
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}


