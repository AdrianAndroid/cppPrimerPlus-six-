//
//  main.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/11.
//

#include <iostream>
#include <string>
#include "../Chapter_13/brass.hpp"

const int CLIENTS = 4;

int main(int argc, const char * argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    
    Brass *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name:";
        getline(cin, temp);
        cout << "Enter client's account number:";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";
        while(cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2:";
        if(kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
            << "as a decimal fraction:";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n') {
            continue;
        }
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++) {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++) {
        delete p_clients[i]; // free memory
    }
    cout << "Done.\n";
    
    return 0;
}
/*
 Enter client's name:Harry Fishsong
 Enter client's account number:112233
 Enter opening balance: $1500
 Enter 1 for Brass Account or 2 for BrassPlus Account: 1
 Enter client's name:Dinah Otternoe
 Enter client's account number:121213
 Enter opening balance: $1800
 Enter 1 for Brass Account or 2 for BrassPlus Account: 2
 Enter the overdraft limit: $350
 Enter the interest rate as a decimal fraction:0.12
 Enter client's name:Brenda Birdherd
 Enter client's account number:212118
 Enter opening balance: $5200
 Enter 1 for Brass Account or 2 for BrassPlus Account: 2
 Enter the overdraft limit: $800
 Enter the interest rate as a decimal fraction:0.10
 Enter client's name:Tim Turtletop
 Enter client's account number:233255
 Enter opening balance: $600
 Enter 1 for Brass Account or 2 for BrassPlus Account: 1

 Brass::ViewAcct()Client: Harry Fishsong
 Account Number:112233
 Balance: $1500.00

 BrassPlus::ViewAcct()Maximum loan: $:350.00
 Owed to bank:$ 0.00
 Loan Rate:12.000%

 BrassPlus::ViewAcct()Maximum loan: $:800.00
 Owed to bank:$ 0.00
 Loan Rate:10.000%

 Brass::ViewAcct()Client: Tim Turtletop
 Account Number:233255
 Balance: $600.00

 Done.
 */
