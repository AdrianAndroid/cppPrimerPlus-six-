//
//  tabtenn1.hpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/12.
//

#ifndef tabtenn1_hpp
#define tabtenn1_hpp

#include <stdio.h>
#include <iostream>
#include "tabtenn0.hpp"

class RatePlayer: public TableTennisPlayer {
private:
    unsigned int rating;
public:
    RatePlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool  ht = false);
    RatePlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() const {return rating;}
    void ResetRating(unsigned int r) { rating = r;}
};

#endif /* tabtenn1_hpp */
