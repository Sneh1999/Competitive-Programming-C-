//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include<math.h>
#include<iostream>
#include <stdlib.h>
#include <float.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
	        float& popSD, float& smplSD, float& mdn);

float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool statistics(const float dataset[], const int size,
	   float& min, float& avg, float& max,
	   float& popSD, float& smplSD, float& mdn) {

    if(size>1)
    {

    min = minimum(dataset,size);
    avg = average(dataset,size);
    max = maximum(dataset,size);

    popSD = popStdDev(dataset,size);
    smplSD = smplStdDev(dataset,size);
    mdn = median(dataset,size);


    return(&min,&avg,&max,&popSD,&smplSD,&mdn);
  }

    else
    {
      return(false);
    }


}

float minimum(const float dataset[], const int size) {

int i;
   float min = FLT_MAX;
  for(i=0; i<size; i++){
  if(dataset[i]<min){
  min = dataset[i];
  }
}

  return(min);
}

float average(const float dataset[], const int size) {
  float sum =0;
  float avg;
  int i;

  for(i=0;i<size;i++)
  {
  sum += dataset[i];

}
  avg = sum/(size);

  return(avg);
}

float maximum(const float dataset[], const int size) {
int i;
float max;
max = -FLT_MAX;

for(i=0; i <size; i++){
if(dataset[i]>max){
max=dataset[i];
}
}

return max;
}

float popStdDev(const float dataset[], const int size) {
  int i ;
  float avg = average(dataset,size);
  double sum1 = 0;
  float populationsd;

  for(i=0;i<size;i++){

 sum1 +=(dataset[i]-avg)*(dataset[i]-avg);
  }
  populationsd = sqrt(sum1/(size));


  return (populationsd);

}

float smplStdDev(const float dataset[], const int size) {
  int i;
  double sum1=0;
  float sd;
  int k = size-1;
  float avg = average(dataset,size);
  for(i=0;i<size;i++){
  sum1 +=(dataset[i]-avg)*(dataset[i]-avg);
  }
  sd = sqrt(sum1/k);


  return(sd);

}

float median(const float dataset[], const int size) {

  int i;
  int j ;
  int s = size;
  float a[size];
  for(i=0;i<size;i++)
  {
    a[i] = dataset[i];
  }

  for(i=0;i<size;i++)
  {
       float help;
    for(j=i+1;j<size;j++)
    {
      if(a[i]>a[j])
      {

         help = a[i];
         a[i] = a[j];
         a[j] = help;


      }
    }

  }
   float median=0 ;
    int b = s/2;
    int d = (s+1)/2;
    if(size%2==0)
    {
      median = a[b-1] + a[b + 1];
    }
    if(!(s%2==0))
    {
      median = a[d-1];
    }
return(median);

}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  int size = 5;
  float dataset[] = {5,1,2,3,4};
  float min;
  float avg;
  float max;
  float popStDev;
  float smplStDev;
  float median;

  if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
    cout << "Minimum: " << min << endl
	 << "Average: " << avg << endl
	 << "Median:  " << median << endl
	 << "Maximum: " << max << endl
	 << "Population Standard Deviation: " << popStDev << endl
	 << "Sample Standard Deviation:     " << smplStDev << endl;
  }
  else
    cout << "Error: unable to compute statistics" << endl;

  return 0;
}

#endif
