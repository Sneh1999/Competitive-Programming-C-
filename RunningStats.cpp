#include <iostream>
#include <stdlib.h>
#include <float.h>

using namespace std;

int main(const int argc, const char*const argv[]){
if (argc==1){
cerr << "Unable to compute statistics over data set because you did not enter any numerical argument" << endl;
return -1;
}
cout<<"Sample  "<<"Value   "<<"Minimum  "<<"Average   "<<"Maximum   "<<endl;
int num=1;
float sum=0;
float avg=0;
float min= FLT_MAX;
float max= -FLT_MAX;
while (num<=argc-1){
float x;
x=atof(argv[num]);
sum+=x;
avg=(sum/num);

if (x<min){
min=x;	
}
if (x>max){
max=x;
}
cout<<num<<" "<<x<<" "<<min<<" "<<avg<<" "<<max<<endl;
num++;
}
return 0;
}