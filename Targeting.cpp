//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include<math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN()
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b,
							 const float w, float& theta);

bool hitTargetGivenAngle (const float h, const float m, const float theta,
							const float d, const float t, const float b,
							const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b,
							 const float w, float& theta) {
if(v<=0)
return false;
if(h<=0)
return false;
if(b*d<0)
return false;
if(w<=0)
return false;
						float g = 9.8;
						float var1 = g*((g*d*d) + (2*(t-h)*v*v));
						float var2 = v*v*v*v;
						float var3 = v*v;
						float var4 = g*d;
						float P = 3.141592;
	float theta1 = atan((var3 + sqrt(var2 - var1))/var4);
	float theta2 = atan((var3 - sqrt(var2 - var1))/var4);
	if(theta1==theta1)
	{
		theta1 = (theta1*180)/P;
	if(theta1>0&&theta1<90)
	{
		theta = theta1;

		return true;
	}
}
if(theta2==theta2)
{
	theta2 = (theta2*180)/P;
	 if(theta2>0&&theta1<90)
	{
		theta = theta2;

		return true;
	}
}


		return false;




}

bool hitTargetGivenAngle (const float h, const float m, const float theta,
							const float d, const float t, const float b,
							const float w, float& v) {

	             if(h<=0)
								return false;
								if(b*d<0)
								return false;
								if(w<=0)
								return false;
								if(theta>=90||theta<=0)
								return false;

float g = 9.8;
float P = 3.141592;
float	v1 = sqrt((d*d*g)/((d*sin(2*(theta*P/180)))-(2*(t-h)*cos(theta*P/180)*cos((theta*P)/180))));
	if(v1==v1)
{
	if(v1<=0)
	return false;
v = v1;
return true;

}
}


#ifndef MARMOSET_TESTING
int main() {

  // Some test driver code here ....

  float h = 50;
  float d = 60;
  float b = 40;
  float t = 0;
  float w = 30;
  float m = 1;

  float theta = 45; // Angle in degrees;
  float v = 45.21;

  cout << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity\n\n";
  }

  cout << "Given initial velocity: " << v << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenVelocity (h, v, m, d, t, b, w, theta)) {
    cout << "required angle: " << theta << endl << endl;
  }
  else {
    cout << "cannot calculate the angle\n\n";
  }
	cout<<theta;

  return 0;
}
#endif
