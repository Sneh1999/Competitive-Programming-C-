#include <iostream>
#include<stdlib.h>

using namespace std;


int main(const int agrc, const char*argv[])
{

float v ;
float d;
float a;
float t;

v = atof(argv[1]);

d = atof(argv[2]);

a= -((v*v)/(2*d));

t = -(v/a);

cout<<"Initial car velocity: "<<v<<"m/s"<<endl;
cout<<"Distance to obstacle: "<<d<<" m"<<endl;
cout<<"Minimum deceleration: "<<a<<"m/s/s"<<endl;
cout<<"Maximum stopping time: "<<t<<"s"<<endl;

return 0;

}