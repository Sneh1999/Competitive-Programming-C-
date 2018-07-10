#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

using namespace std;

int main( const int argc, const char* const argv[]){

if(argc == 1){
cerr << "Unable to compute statistics over data set because you didnt enter a numerical argument" << endl;
return -1;
}

int numFloats = argc-1;

cout << "Number of floating-point numbers: " << numFloats << endl;

int i =	1;

float sum = 0;
 
float max = -FLT_MAX;

float min = FLT_MAX;

while( i < argc){
float value = atof(argv[i]);
 	
sum += value;

if(value < min){
min = value;
}

if(value > max){
max = value;
}

i++;
}

float AVERAGE = float(sum / (argc - 1 ) );

cout << "Minimum floating-point number: " << min << endl;

cout << "Average floating-point number: " << AVERAGE << endl;

cout << "Maximum floating-point number: " << max << endl;

return 0;
}




