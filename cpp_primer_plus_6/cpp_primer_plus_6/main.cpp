//
//  main.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/11.
//

#include <iostream>
#include "../Chapter_13/tabtenn0.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    using std::cout;
    TableTennisPlayer player1("Chunk", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if(player1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }
    player2.Name();
    if(player2.HasTable()) {
        cout << ": has a table";
    } else {
        cout << ": hasn't a table.\n";
    }
        return 0;
}
