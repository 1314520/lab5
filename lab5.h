#ifndef LAB5_H
#define LAB5_H


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class HugeInt
{
        friend ostream & operator<<(ostream &,const HugeInt &);
        friend istream & operator>>(istream &,HugeInt &);
    public :
        HugeInt(int=0);
//      HugeInt(const HugeInt &);
        HugeInt(const string );
    
	int str2int(string &);
        string int2str(int &);
	const HugeInt & operator=(const HugeInt &);
        const HugeInt  operator+(const HugeInt &);
        const HugeInt  operator-(const HugeInt &);
    
        string value;
        int len,iarr[50];
};

#endif

