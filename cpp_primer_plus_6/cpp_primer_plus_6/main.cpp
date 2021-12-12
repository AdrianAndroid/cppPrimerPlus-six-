//
//  main.cpp
//  cpp_primer_plus_6
//
//  Created by 赵健 on 2021/12/11.
//

#include <iostream>
#include <string>

using std::cin;
using std::count;
using std::endl;



class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream &os, const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses impllicit assignment operator
class lackDMA: public baseDMA {
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lackDMA(const char * c = "blank", const char *l = "null", int r = 0);
    lackDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lackDMA & rs);
};

class hasDMA : public baseDMA {
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};


// baseDMA methods
baseDMA::baseDMA(const char *l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std:strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs) {
    if (this == &rs) {
        return  *this;
    }
    delete [] label;
    label = new char[std::strlen(rs.label)+1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs){
    os << "Label :" << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

// lacksDMA methods
lackDMA::lackDMA(const char *c, const char *l, int r) : baseDMA(l, r){
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lackDMA::lackDMA(const char * c, const baseDMA & rs) : baseDMA(rs) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lackDMA & ls) {
    os << (const baseDMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char *l, int r) : baseDMA(l, r) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA & rs) : baseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs) {
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs) {
    if(this == &hs)
        return *this;
    baseDMA::operator=(hs);
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs) {
    os << (const hasDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}


int main(int argc, const char * argv[]) {
    using std::cout;
    using std::endl;
    cout << "Hello" << endl;
    
    baseDMA shirt("Portablelly", 8);
    lackDMA ballon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object: \n";
    cout << shirt << endl;
    cout << "Displaying lackDMA object:\n";
    cout << ballon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    lackDMA ballon2(ballon);
    cout << "Result of lackDMA copy:\n";
    cout << ballon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    return 0;
}
