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
using std::ios_base;

AcctABC::AcctABC(const string & s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt) {
    if(amt < 0)
        cout << "Negative deposit not allowed;" << "deposit is cancelled.\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt) {
    balance -= amt;
}

// protected methods for formatting
AcctABC::Formatting AcctABC::SetFormat() const {
    // set up ###.## format
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

void Brass::Withdraw(double amt) {
    if (amt  < 0) {
        cout << "Withdrawal amount must  be positive;" << "withdrawal canceled.\n";
    } else if(amt <= Balance()) {
        AcctABC::Withdraw(amt);
    } else {
        cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawl canceld.\n";
    }
}

void Brass::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "Brass Client:" << FullName() << endl;
    cout << "Account Number:"<< AcctNum() << endl;
    cout << "Balance: $:"<<Balance()<<endl;
    Restore(f);
}


// BrasePlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r):AcctABC(s, an, bal)
{
    maxLoad = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    
    cout << "BrassPlus Client; " << FullName() << endl;
    cout << "Account Number:" << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum load: $" << owesBank << endl;
    cout.precision(3);
    cout << "Load Rate:" << 100*rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if ( amt <= bal + maxLoad - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    Restore(f);
}
