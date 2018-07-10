#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc , const char*argv[])
{
if(argc<3)
{
cerr<<"Error: Unable to compute GCD and/or LCM because of insufficient arguments";
return -1;
}
if(argc>3)
{
cerr<<"Warning: Expecting three command-line arguments; received "<< argc-1 <<"; ignoring extraneous arguments." <<endl;
}
int a = atoi(argv[1]);
int b = atoi(argv[2]);
if(a<=0||b<=0)
{
cerr<<"Error: Unable to compute GCD and/or LCM because of invalid input."<<endl;
return -1;
}
int i ;
int GCD;
int LCM;
for(i=1;(i<=a)&&(i<=b);i++)
{
if((a%i==0)&&(b%i==0))
{
GCD=i;
}
}
LCM = (a/GCD)*b;
cout<<"GCD("<<a<<","<<b<<") "<<"= "<<GCD<<endl;
cout<<"LCM("<<a<<","<<b<<") "<<"= "<<LCM<<endl;
return -1;
}
