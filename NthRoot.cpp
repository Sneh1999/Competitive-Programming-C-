#include <iostream>
#include <stdlib.h>

using namespace std;
float power(float number, int pow);
float abs(float number);

int main(const int argc, const char* const argv[]){


if (argc < 4){
cerr << "Error: Unable to compute Nth root because insufficient amount of arguments; expecting 4." << endl;
return -1;
}

if (argc > 4){
cerr << "Warning: More entries than necessary; ignoring extraneous arguments." << endl;
}


int rootNum = atoi(argv[2]);
float precision = atof(argv[3]);
float num = atof(argv[1]);

float ans = num / rootNum;
float accuracy = 1;	
if(num < 0){		
if(rootNum % 2 == 0){
cerr << "Error: Unable to compute Nth root because input is invalid." << endl;
return -1;
}
}

if (rootNum < 2 || precision <= 0){
cerr << "Error: Unable to compute Nth root because input is invalid." << endl;
return -1;
}

if (num == 0){
ans = 0;
}


else{	

while(accuracy > precision){

float eqn1 = ((float)(rootNum - 1) / (float)(rootNum)) * ans;
float eqn2 = num / ((float)(rootNum) * (power(ans, rootNum - 1)));


ans = eqn1 + eqn2;


accuracy = abs(((num - power(ans, rootNum)) / num));
}	
}


cout << "Root (" << num << ", " << rootNum << ") = " << ans << "\n(with precision " << abs(accuracy) << ")" << endl;

return 0;
}

float power(float number, int pow){

if(pow == 0)
return 1;

else{
float result = 1;

while (pow > 0){
result *= number;
pow--;
}
return result;
}
}

float abs(float number){
if(number < 0)
number *= -1;

return number;
}