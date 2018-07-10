#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;

int main(const int argc,const char* const argv[]){
if(argc-1<1){
cerr<<"Error: Unable to compute statistics over data set because insufficient arguments";
}
int  i;
float min = atof(argv[1]);
float max = atof(argv[1]);
float avg;
float sum =0;
float populationsd;
float sd;
float sum1 =0;
int j ;
float a[50];
for(i=1; i <=(argc-1); i++){
a[i]= atof(argv[i]);
if(a[i]<min){
min = a[i];
}
if(a[i]>max){
max=a[i];
}
sum +=a[i];
}
cout<<"I"<<i;
avg= sum/(i-1);

for(j=1;j<=(argc-1);j++){
sum1 +=(a[j]-avg)*(a[j]-avg);
}
populationsd = sqrt(sum1/(i-1));
sd = sqrt(sum1/(i-2));
cout<<"Number of floating-point numbers: "<<(i-1)<<endl;
cout<<"Minimum floating-point number: "<<min<<endl;
cout<<"Average floating-point number: "<<avg<<endl;
cout<<"Maximum floating-point number: "<<max<<endl;
if ((i-1)==0)
cout<<"Population standard deviation: Infinity"<<endl;
if(i-1>0)
cout<<"Population standard deviation: "<<populationsd<<endl;
if((i-2==0))
cout<<"Sample standard deviation: Infinity"<<endl;
if((i-2>0))
cout<<"Sample standard deviation: "<<sd<<endl;

return 0;
}

