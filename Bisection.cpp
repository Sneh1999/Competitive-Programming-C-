//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include<limits>
#include<cmath>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize,float precisoncompare,int count );
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize,float precisioncompare , int count)
          {





            if(right==left)
            return std::numeric_limits<float>::quiet_NaN();



            if(right<left)
            return std::numeric_limits<float>::quiet_NaN();


          if((f(left)<0&&f(right)<0)||(f(left)>0&&f(right)>0))
          return std::numeric_limits<float>::quiet_NaN();




            float midpoint = (right+left)/2;



            if ((abs(f(midpoint))<=precision)||(right-left<minIntervalSize))
            return midpoint;

            if(count<0)
            {
              return midpoint;


            }

            else
            {
              count--;


              if ((f(left)<0&&f(midpoint)<0)||(f(left)>0&&f(midpoint)>0))
            {
            bisectionHelper(midpoint, right, precision, minIntervalSize,precisioncompare,count);

            }

            else
           {
            bisectionHelper(left, midpoint, precision, minIntervalSize,precisioncompare,count);

          }


      }





          }

float bisection(const float left, const float right,
		const float precision, const float minIntervalSize) {

     float   midpoint = (left + right) /2;
      float precisioncompare = f(midpoint);

      if(precision<=0)
      return std::numeric_limits<float>::quiet_NaN();
      

int count= 100;
     float value = bisectionHelper(left,right,precision,minIntervalSize,precisioncompare,count);

      if(value==-1)
      return std::numeric_limits<float>::quiet_NaN();

       else if(value==-2)
      return std::numeric_limits<float>::quiet_NaN();

      else if(value==-3)
      return std::numeric_limits<float>::quiet_NaN();

      else if(value==-4)
      return std::numeric_limits<float>::quiet_NaN();

      else if(value==-5)
      return std::numeric_limits<float>::quiet_NaN();
      else if(value==-6)
      return std::numeric_limits<float>::quiet_NaN();

      else if(value==-7)
      return std::numeric_limits<float>::quiet_NaN();



      else
      return value;





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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....

  return 0;
}

#endif
