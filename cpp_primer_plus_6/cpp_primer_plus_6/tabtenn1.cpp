//
//  tabtenn1.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/12.
//

#include "tabtenn1.hpp"

RatePlayer::RatePlayer(unsigned int r, const string & fn, const string & ln, bool ht):TableTennisPlayer(fn, ln, ht){
    rating = r;
}

RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer&tp) : TableTennisPlayer(tp), rating(r) {
    
}
