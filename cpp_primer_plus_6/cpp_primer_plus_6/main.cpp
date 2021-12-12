//
//  main.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/11.
//

#include <iostream>
#include "../Chapter_13/tabtenn0.hpp"
#include "../Chapter_13/tabtenn1.hpp"
#include "../Chapter_13/brass.hpp"



int main(int argc, const char * argv[]) {
    Brass dom("Dominic Banker", 11224, 4183.45);
    BrassPlus dot("Dorothy Banker", 12118, 2528.01);
    Brass & b1_ref = dom;
    Brass & b2_ret = dot;
    b1_ref.ViewAcct();
    b2_ret.ViewAcct();
    return 0;
}
