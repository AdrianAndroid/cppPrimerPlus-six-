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
using std::cin;
using std::count;
using std::endl;


int main(int argc, const char * argv[]) {
    using std::cout;
    using std::endl;
    cout << "Hello" << endl;
    
    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    
    for(int i = 0; i < CLIENTS; i++) {
        cout << "ENter client's nams: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass account or " << " 2 for BrassPlus Account: ";
        while(cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if(kind == '1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double tmax, trate;
            cout << "Enter the overdraft rate " << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while(cin.get() != '\n')
              continue;

    }
    cout << endl;
    for(int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for(int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout << "Done.\n";
    
    return 0;
}
