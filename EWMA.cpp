#include <iostream>
#include <stdlib.h>
#include <float.h>

using namespace std;

int main(const int argc, const char*const argv[]){
if (argc<4){
cerr << "Error: Unable to compute statistics over data set because you did not enter insuficient arguments" <<endl;
return -1;
}
cout<<"Sample\t"<<"Value\t"<<"Minimum\t"<<"EWMA\t"<<"Maximum\t"<<endl;
int num=1;
float sum=0;
float emw=atof(argv[3]);
float min= FLT_MAX;
float max= -FLT_MAX;
int i=3;
float limit=atof(argv[2]);
float maxc=1;
float minc=1;
float oldmin=0;
float oldmax=0;
if (limit<1){
cerr<<"Error: Age Limit cannot be less than 1"<<endl;
return -1;}
if ((atof(argv[1])<0)|| (atof(argv[1])>1)){
cerr<<"Error: Weight cannot be less zero or greater than 1"<<endl;
return -1;
}
while (num<=argc-3){
float x; 
x=atof(argv[i]);
emw=((atof(argv[1])*x)+((1-(atof(argv[1])))*emw));
if (minc>=limit){
minc=1;
min= FLT_MAX;
oldmin=0;
}
if (minc<limit){
if (x<min)
min=x;
if (min==oldmin)
minc+=1;
}
if (maxc>=limit){
maxc=1;
max= -FLT_MAX;
oldmax=0;
}
if (maxc<=limit){
if (x>max)
max=x;
if (max==oldmax)
maxc+=1;
}
cout<<num<<" "<<x<<" "<<min<<" "<<emw<<" "<<max<<endl;
oldmax=max;
oldmin=min;
num++;
i++;
}
return 0;
}