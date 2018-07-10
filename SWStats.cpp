#include<iostream>
#include<stdlib.h>
using namespace std;

int main(const int argc,const char*const argv[])
{
  if ((argc<=2)){
cerr<<"Error: Unable to compute statistics over data set because insufficient arguments.";
return -1;
}

  int windowsize = atof(argv[1]);
  float min = atof(argv[2]);
  float max = atof(argv[2]);
  float avg = atof(argv[2]);
  float sum = 0;
  float a[100];
if (windowsize<=0){
cerr<<"Error: Window size cannot be non-positive number"<<endl;
return -1;
}
if (windowsize == 1){
cerr << "Warning: Window size is 1."<<endl;
}
if (windowsize >= argc - 2){
cerr << "Warning: Window size is greater than the number of inputs; ignoring extraneous inputs."<<endl;
}

  int k;
  int i ;
  int j ;

  cout<<"Window Size:"<<windowsize<<endl;
  cout<<"Sample\t"<<"Value\t"<<"SWMinimum\t"<<"SWAverage\t"<<"SWMaximum"<<endl;
  for(i=1;i<=argc-2;i++)
  {
    a[i]= atof(argv[i+1]);

  }

  for(i=1;i<=argc-2;i++)
  {

    if(i<=windowsize)
    {

   if(min>a[i])
    {
      min=a[i];
    }
    if(a[i]>max)
    {
      max=a[i];
    }
    cout<<i<<"\t"<<a[i]<<"\t"<<min<<"\t"<<max<<"\t"<<endl;
  }

  else if(i>windowsize)
  {
    if(a[i]<a[i-(windowsize) + 1])
    {  if(min>a[i])
      min =a[i];
    }
    if(a[i]>a[i-(windowsize) +1])
    {
      if(max<a[i])
      max =a[i];
    }
    cout<<i<<"\t"<<a[i]<<"\t"<<min<<"\t"<<max<<"\t"<<endl;

  }
}



return 0;
}
