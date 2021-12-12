//
//  brass.hpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/12.
//

#ifndef brass_hpp
#define brass_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting{
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const {return fullName;}
    long AcctNum() const {return acctNum;}
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;
public:
    AcctABC(const std::string & s = "NullBody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;
    double Balance() const {return Balance();}
    virtual void ViewAcct() const = 0;
    virtual ~AcctABC(){}
};

class Brass : public AcctABC
{
private:
    long acctNum;
    double balance;
    
protected:
    std::string fullName;
public:
    Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass(){}
};



class BrassPlus : public AcctABC{
private:
    double maxLoad;
    double rate;
    double owesBank;
public: 
    BrassPlus(const std::string & s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) {maxLoad = m;}
    void ResetRate(double r) {rate = r;}
};



#endif /* brass_hpp */
