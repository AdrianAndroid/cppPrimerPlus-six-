//
//  tabtenn0.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/12.
//

#include "tabtenn0.hpp"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string& fn, const string & ln, bool ht): firstname(fn), lastname(ln), hasTable(ht){}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}
