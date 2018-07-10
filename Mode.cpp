//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include<limits.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int range(const int dataset[], const int size);
int mode(const int dataset[], const int size, int mode[]);
bool sort(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
//

void selection(int i,int dataset[],const int size)
{
      if(i==size-1)
      {
        return;
      }

    for(int j= i+1;j<size;j++)
    {
     if(dataset[i]>dataset[j])
     {
       int help;
       help = dataset[i];
       dataset[i]=dataset[j];
       dataset[j] = help;
     }
   }

     selection(i+1,dataset,size);


}


int range(const int dataset[], const int size){

    int i ;
    int max = dataset[0];
    int min = dataset[0];

    if(size==0)
    {
      return -1;
    }

    for(i=0;i<size;i++)
    {
      if(dataset[i]>max)
      {
        max = dataset[i];
      }
      if(dataset[i]<min)
      {
        min = dataset[i];
      }
    }

    if(max ==INT_MAX)
    {
      return INT_MAX - min;
    }

   int range = max - min;


   return(range);

}
int mode(const int dataset[], const int size, int mode[]){

  int s = size;
  int counter = 1;
  int counter1 =0;
  int counter2 = 1;
  int i;
  int j;

  int a[size];
int k [size];

for(i=0;i<size;i++)
{
  a[i]=dataset[i];
}



  for(i=0;i<size;i++)
  {
    for(j=i+1;j<size;j++)
    {
      if(a[i]==a[j])
      counter++;

    }
    if(counter>1)
    {
      k[i]=counter;
      counter =1;
    }
    else
    k[i]=0;

  }
  selection(0,k,s);



  int num = k[size-1];


  for(i=0;i<size;i++)
  {
    if(k[i]==num)
    {
      counter1++;
    }

  }


  selection(0,a,s);


   mode[counter1];

int z=0;
  for(i=0;i<size;i++)
  {
    for(j=i+1;j<size;j++)
    {
      if(a[i]==a[j])
      {
        counter2++;
      }
    }

  if(counter2==num)
  {
    mode[z]=a[i];
    z++;
  }

  counter2=1;
}


return counter1;
}
bool sort(int dataset[], const int size){

int i =0;
  selection(i,dataset,size);

return true;


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

  // Some test driver code here ....
  int data[] = {9996 , 10000 , 9998 , 9998 , 9996 , 10000 , 10000 , 9997 , 9995 , 9997 , 9997 , 9998 , 9995 , 9997 , 10000};
  int size = 15;
  //change this to however many modes you expect to find
  int modeArray[100]={0};
  int rng = range(data, size);
  int modes = mode(data, size, modeArray);
  cout << "range: " << rng << " number of Modes: " << modes << " Modes are this: ";
  for(int i = 0; i<modes;i++){
  	cout<< modeArray[i];
  	if(i<modes-1){
  		cout << ", ";
  	}
  }
  cout<<endl;
  return 0;
}

#endif
