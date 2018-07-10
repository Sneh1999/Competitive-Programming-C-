//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>

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

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {




   double P = 3.141592;

 float var1 =  v*v*sin((2*P*theta)/360)*sin((2*P*theta)/360);
 float var2 = 2*9.8*h;
 float var3 = (v*v*sin(2*((2*P*theta)/360)))/9.8;

 float D = (var3*(1 + sqrt(1 + (var2/var1))))/2;

  if(d==b)
  {
    destX = b;
    destY = 0;
  }
  else if(theta==90||v==0)
  {
    destX = 0;
    destY = h;
  }
  else if(d<b)
  {
    destX = D;
    destY = 0;
  }
  else if(((d>b)&&(d<=w)))
  {
    destX = D;
    destY = t;
  }
  else if(d>w)
  {
    destX = D;
    destY = 0;
  }

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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....

  float h = 10;
  float v = 10;
  float m = 10;
  float theta = 45;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 5;
  float b = 97;
  float w = 5;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
