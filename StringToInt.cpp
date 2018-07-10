//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

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

bool stringToInt(const char input[], int& value);



//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//



bool stringToInt(const char input[], int& value) {

int sign=0;
    value = 0;

  unsigned int currentdigit = 0;
  char currentdigitchar= input[0];
  unsigned int maxvalue = 2147483647;

   int done = 0;
   int S = 1;

while (!done)
{
  char input1 = input[currentdigit];
  if(input1==' '||input1=='\t'||input1=='\n')
  {
    return false;
  }
  switch (S)
  {
    case 1:
    switch (input1)
    {
      case '-':
      //currentdigit = 1;
      //currentdigitchar = input[1];
      sign = 1;
      S = 2;
      maxvalue = maxvalue + 1;
      break;


      case '+':
    //  currentdigit = 1;
      //currentdigitchar = input[1];
      sign= 2;
      S  = 2;
      maxvalue = maxvalue + 1;
      break;

      case '\0':
      return true;

      default:
      if(currentdigitchar < '0'|| currentdigitchar> '9')
      {
        return false;
      }
      else
      {  if(input[currentdigit]=='0')

          {
            value = '0' -'0';
          return true;
        }

        value*= 10;
        unsigned int currentintvalue = input1 - '0';
        if(currentintvalue > maxvalue-value)
        return false;
        value += currentintvalue;

        S = 2;
        //currentdigit++;
        break;

      }

     break;
    }
    break;
  case 2:

    switch(input1)
    {

      case '\0':
      if (sign==1)
        value=-value;
      if (sign==2)
       value=+value;

      return true;

      default:

      value*= 10;
      unsigned int currentintvalue = input1 - '0';
      if(currentintvalue > maxvalue-value)
      return false;
      value += currentintvalue;
      S = 2;
      break;

    }


    break;


  case 3:


  return true;
}
if((sign==1&&value>maxvalue)||(sign==2 && value >maxvalue))
{
  return false;
}

currentdigit++;


}






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
  int argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <int>" << endl;
    return -1;
  }

if(stringToInt(argv[1],argv1)==false)

    cout << "argv[1] is not an int." << endl;

  cout<<argv1;
  return 0;
}

#endif
