//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
// You are allowed float.h
#include<math.h>

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

bool stringToFloat(const char input[], float& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...

bool stringToFloat(const char input[], float& value) {

  int sign = 0 ;
    int  count  = 0;
    int count1 = 0;
int sign1 = 0;
     value = 0;
    double value1 = 0;
    char currentdigitchar= input[0];
    int currentdigit = 0;
     int done = 0;
     int S = 1;

  while (!done)
  {
    char input1 = input[currentdigit];
    if(input1==' '||input1=='\t'||input1=='\n')
    {
      return false;
    }
    else if(input1=='\0')
    {
       value = double(value);


    value1 = value1*pow(10,-(count));

    value = value + value1;

    value = value*pow(10,count1);

     if(sign==1)
      value *= -1;
    if(sign==2)
    value*=1;
    return true;

    }
    else
    {
    switch (S)
    {
      case 1:
      switch (input1)
      {
        case '-':
        sign = 1;
        S = 2;

        break;

       case '+':
       sign= 2;
        S  = 2;
        break;

        case '.':
        S = 3;
        break;

        default:
        if(input1>='0'&& input1<='9')

        {

         value*= 10;
          int currentintvalue = input1 - '0';
          value += currentintvalue;
          S = 2;
        }
        else
        return false;

       break;
      }
      break;
    case 2:

      switch(input1)
      {

       case '.':
       S = 3;
       break;

        default:
        if(input1>='0' && input1<='9')
        {

        value*= 10;
        int currentintvalue = input1 - '0';
        value += currentintvalue;
        S = 2;

      }
      else
      return false;




    }
    break;


    case 3:

    switch(input1)

 {
   case 'e':

{
   int b = input[currentdigit+1] - '0';

      count1 = count1 + b;
     S = 3;
      currentdigit++;

     break;

   S = 3;
 }
   break;

   case 'E':
   {
      int b = input[currentdigit+1] - '0';

         count1 = count1 + b;
        S = 3;
         currentdigit++;

        break;

      S = 3;
    }
      break;


   default:

     if(input1>='0'&& input1<='9')
   {
      count++;
     value1*= 10;
     int currentintvalue = input1 - '0';
     value1 += currentintvalue;

     S = 3;


   }
   else
   return false;

   }
break;
}
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
int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....
  float argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
    return -1;
  }

  if (stringToFloat(argv[1],argv1))
    cout << "argv[1] is a float with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not a float. argv[1]: " <<argv[1] << endl;
  return 0;
}

#endif
