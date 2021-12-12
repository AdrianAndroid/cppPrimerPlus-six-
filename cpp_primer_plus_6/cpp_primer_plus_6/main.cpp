//
//  main.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/11.
//

#include <iostream>
#include <string>
#include "../Chapter_13/brass.hpp"

void fr(Brass & rb);
void fp(Brass * pb);
void fv(Brass b);

int main(int argc, const char * argv[]) {
    Brass b("Billy bee", 123432, 1000.0);
    BrassPlus bp("Betty Beep", 23222, 1234.4);
    fr(b);
    fr(bp);
    
    fp(&b);
    fp(&bp);
    
    fv(b);
    fv(bp);
    
    return 0;
}
