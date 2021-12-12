//
//  tabtenn0.hpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/12.
//

#ifndef tabtenn0_hpp
#define tabtenn0_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return  hasTable; }
    void ResetTable(bool v) {hasTable = v; }
};


//int uset0_main_0() {
//    using std::cout;
//    TableTennisPlayer player1("Chunk", "Blizzard", true);
//    TableTennisPlayer player2("Tara", "Boomdea", false);
//    player1.Name();
//    if(player1.HasTable()) {
//        cout << ": has a table.\n";
//    } else {
//        cout << ": hasn't a table.\n";
//    }
//    player2.Name();
//    if(player2.HasTable()) {
//        cout << ": has a table";
//    } else {
//        cout << ": hasn't a table.\n";
//    }
//    
//    return 0;
//}
#endif /* tabtenn0_hpp */
