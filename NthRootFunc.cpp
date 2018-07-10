//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <iostream>
#include <stdlib.h>
#include<limits>





//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING



using namespace std;

float NthRoot(const float S, const int N, const float precision);
float pow1(float x, const int N);
float absol(int x);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//
float pow1(float x, const int N)
{
  float T =1;
  int i;
 for(i=1;i<=N;i++)
 {
   T = T*x;

 }
return(T);
}

float absol(float x )
{
  if(x<0)
  {
    x = -x;
  }
  return(x);
}

float ps(float x)
{


}



float NthRoot(const float S, const int N, const float precision) {


  if(S<0 && N%2==0||N<=1||precision<=0)

    return std::numeric_limits<float>::quiet_NaN();

    else if (S==0)
    return S;


  float xi=1;

  float n = float(N);

 float  result = pow1(1500,2);

int counter = 1;

 while(result>=precision && counter<5000000)
 {


    xi = ((n-1)/n)*xi + S/(n*(pow1(xi,n-1)));
    result = absol((S - pow1(xi,n)));
    counter++;

}

return(xi);

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

  if (argc < 4) {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }

  float root = NthRoot(atof(argv[1]),atoi(argv[2]),atof(argv[3]));
  if (isNaN(root))
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
  else
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
	 << "(with precision " << argv[3] << ")" << endl;

  return 0;
}

#endif
