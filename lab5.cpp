#include "lab5.h"

using namespace std;

HugeInt::HugeInt(int b)
{
    
    value = int2str(b);
    
    len = value.length();
    for(int i=0;i<50;i++)
	iarr[i] = 0;
    for(int i=0;i<len;i++)
	iarr[i+50-len] = value.at(i)-'0';

    
}

/*HugeInt::HugeInt(const HugeInt & b)
{
    for(int i=0;i<100;i++)
    {
        a[i]=0;
    }
    size=b.size;
    for(int i=0;i<b.size;i++)
    {
        a[i]=b.a[i];
    }
}*/

HugeInt::HugeInt(const string s)
{

    value = s;
    
    len = value.length();

    for(int i=0;i<50;i++)
        iarr[i] = 0;
    for(int i=0;i<len;i++)
        iarr[i+50-len] = value.at(i)-'0';


}

istream & operator>>(istream & in,HugeInt & h)
{
    h.len = 0;
    in >> h.value;
    h.len = h.value.length();
    for(int i=0;i<50;i++)
        h.iarr[i] = 0;
    for(int i=0;i<h.len;i++)
        h.iarr[i+50-h.len] = h.value.at(i)-'0';
    return in;
}

ostream & operator<<(ostream & out,const HugeInt & h)
{
    
    out << h.value;


    return out;
}

const HugeInt & HugeInt::operator=(const HugeInt & h)
{
    if(&h != this)
    {
	this->value = h.value;
	this->len = h.len;
        for(int i=0;i<50;i++)
            iarr[i] = 0;
        for(int i=0;i<h.len;i++)
            iarr[i+50-len] = value.at(i)-'0';

    }

    return *this;
}
const HugeInt HugeInt::operator+(const HugeInt &h)
{
    int c[50],i;
    HugeInt temp;
    for(i=0;i<50;i++)
	c[i] = iarr[i]+h.iarr[i];
    for(i=49;i>0;i--)
    {
	if(c[i]>=10)
	{
	    c[i-1]+=c[i]/10;
	    c[i] = c[i]%10;
	}
    }
    for(i=0;i<50;i++)
	temp.iarr[i] = c[i];    
    for(i=0;i<50;i++)
	if(c[i]!=0) break;
    temp.value = int2str(c[i]) ;
    i++;
    for(;i<50;i++)
    {
	temp.value = temp.value + int2str(c[i]) ;
    }
    temp.len = temp.value.length();
    return temp;
}
const HugeInt  HugeInt::operator-(const HugeInt &h)
{
    int c[50],i;
    HugeInt temp;

    for(i=0;i<50;i++)
        c[i] = iarr[i]-h.iarr[i];
    for(i=49;i>0;i--)
    {
        if(c[i]<0)
        {
            c[i-1] = c[i-1] - 1;
            c[i] = c[i] + 10;
        }
    }
    for(i=0;i<50;i++)
        temp.iarr[i] = c[i];
    for(i=0;i<50;i++)
        if(c[i]!=0) break;
    temp.value = int2str(c[i]) ;
    i++;
    for(;i<50;i++)
    {
        temp.value = temp.value + int2str(c[i]) ;
    }
    temp.len = temp.value.length();
    return temp;



}

string HugeInt::int2str(int &i)
{
    string s;
    stringstream ss(s);
    ss<<i;
    return ss.str();
}

int HugeInt::str2int(string &s)
{
    int i ;
    stringstream ss(s);
    ss>>i;
    return i;

}






