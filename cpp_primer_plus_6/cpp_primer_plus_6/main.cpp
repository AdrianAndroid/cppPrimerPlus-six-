//
//  main.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/11.
//

#include <iostream>
#include "../Chapter_13/tabtenn0.hpp"
#include "../Chapter_13/tabtenn1.hpp"


int main(int argc, const char * argv[]) {
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatePlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();
    if(rplayer1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }
    player1.Name();
    if(player1.HasTable()){
        cout << ": has a table";
    } else {
        cout << ": hasn't a table";
    }
    cout << "Name: ";
    cout << "; Rating: " << rplayer1.Rating() << endl;
    RatePlayer rplayer2(1212, player1);
    cout << "Name: " ;
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;
    return 0;
}
