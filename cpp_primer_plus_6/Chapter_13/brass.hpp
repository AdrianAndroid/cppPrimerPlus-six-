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

class Brass
{
private:
    long acctNum;
    double balance;
    
protected:
    std::string fullName;
public:
    Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass(){}
    virtual void Name();
};

class BrassPlus : public Brass{
private:
    double maxLoad;
    double rate;
    double owesBank;
public: 
    BrassPlus(const std::string & s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) {maxLoad = m;}
    void ResetRate(double r) {rate = r;}
    virtual void Name();
};



#endif /* brass_hpp */
