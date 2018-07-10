//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;


//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING


#endif

//////////////////////////////////////////////////////////////
//
// struct definitions
//
#ifndef MARMOSET_TESTING
struct Student{
	int studentID;
	int grade;
};

struct Dataset{
	int numStudents;
	Student* students;
};

struct Rejects{
	int numRejects;
	int* rejects;
};

struct Mode{
	int numModes;
	int* modes;
};

struct Statistics{
	int   minimum;
	float average;
	int   maximum;
	float popStdDev;
	float smplStdDev;
	Mode  mode;
	int   histogram[10];
};
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
int readCSV(const char filename[],const int minAcceptableID,
				const int maxAcceptableID,Dataset& data,
				Rejects& rejects);

int computeStatistics(Dataset& data, Statistics& stats);

int writeCSV(const char filename[], const Statistics& stats);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
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
int minimum(Dataset& data, const int size) {

int i;
	 int min = data.students[0].grade;
	for(i=0; i<size; i++){
	if(data.students[i].grade<min){
	min = data.students[i].grade;
	}
}


	return(min);
}
float average(Dataset& data, const int size) {
	float sum =0;
	float avg;
	int i;

	for(i=0;i<size;i++)
	{
	sum += data.students[i].grade;

}
	avg = sum/(size);

	return(avg);
}

int maximum(Dataset& data, const int size) {
int i;
int max;
max = data.students[0].grade;

for(i=0; i <size; i++){
if(data.students[i].grade>max){
max=data.students[i].grade;
}
}

return max;
}

float popStdDev(Dataset& data, const int size) {
	int i ;
	float avg = average(data,size);
	float sum1 = 0;
	float populationsd;

	for(i=0;i<size;i++){

 sum1 +=(data.students[i].grade-avg)*(data.students[i].grade-avg);
	}
	populationsd = sqrt(sum1/(size));


	return (populationsd);

}

float smplStdDev(Dataset& data, const int size) {
	int i;
	float sum1=0;
	float sd;
	int k = size-1;
	float avg = average(data,size);
	for(i=0;i<size;i++){
	sum1 +=(data.students[i].grade-avg)*(data.students[i].grade-avg);
	}
	sd = sqrt(sum1/k);


	return(sd);

}

float median(Dataset& data, const int size) {

	int i;
	int j ;
	int s = size;
	float a[size];
	for(i=0;i<size;i++)
	{
		a[i] = data.students[i].grade;
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
int mode(Statistics& stats, Dataset& data,const int size){
  int sign =0;
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
  a[i]=data.students[i].grade;
}

for(i=0;i<size;i++)
{
	cout<<"values of student array"<<a[i]<<endl;
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
			sign =1;
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



stats.mode.modes  = new int[counter1];
	if(sign!=1)
	{

		for(i=0;i<counter1;i++)
		{
			stats.mode.modes[i] = a[i];
		}
		return counter1;
	}


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
    stats.mode.modes[z]=a[i];
    z++;
  }

  counter2=1;
}
for(int i=0;i<counter;i++)
{
	cout<<stats.mode.modes[i];
}


return counter1;
}



int readCSV(const char filename[],const int minAcceptableID,
				const int maxAcceptableID,Dataset& data,
				Rejects& rejects){

					if(minAcceptableID>=maxAcceptableID){

						return -1;
					}
					int size = 0;
					int sign = 0;
					char filename1[100];
					for(int j=0; filename[j]!='\0';j++){
						filename1[j]=filename[j];

						size ++;
				}

	    for(int j =0;filename[j]!='\0';j++)
			{
				if(filename[j]=='.')
				{
					filename1[j+1]='c';
					filename1[j+2]='s';
					filename1[j+3] = 'v';
					filename1[j+4] = '\0';
					sign =1;

					break;
				}
			}

			 if(sign==0)
			 {
				 filename1[size]='.';
				 filename1[size+1]='c';
				 filename1[size+2]='s';
				 filename1[size+3]='v';
				 filename1[size+4] = '\0';


			 }
     cout<<filename;


					ifstream fin;

					fin.open(filename1);


					if(!fin.is_open())
					{
						return -1;
					}

					//int number = 0;
					//int grade = 0;
					int value = 0;
					int value1=0;
					int count = 0 ;
					int fileline =1;
					int filelinecount = 0;


					 rejects.rejects=  new int[100];
					   data.students = new Student[100];

					int i =0;
					int j =0;
					int index =0;
					int State = 1;



					    while(!fin.eof())
					      {
					        char a =0;
					         fin.get(a);



					       if(a==' '||a=='\t')
					       {

					       }
					      else  if(a=='\n')
					       {
									 if(value==0&&value1==0)
									 {
										 count++;

						           rejects.rejects[index]=fileline;
											 rejects.numRejects = count;
											 cout<<"rejects"<<rejects.rejects[index]<<endl;
											 cout<<"rejectsnumber"<<rejects.numRejects<<endl;
						           index++;

									 }
					         else if(value>=minAcceptableID&&value<=maxAcceptableID)
					         {

					         if(value1>100||value1<0)
					         { count++;

					           rejects.rejects[index]=fileline;
										 rejects.numRejects = count;
										 cout<<"rejects"<<rejects.rejects[index]<<endl;
										 cout<<"rejectsnumber"<<rejects.numRejects<<endl;
					           index++;
					         }

									 else
									 {

											data.students[j].studentID = value;
											data.students[j].grade = value1;
											data.numStudents= j+1;
											cout<<"datastudents id"<<data.students[j].studentID<<endl;
											cout<<"datagrade"<<data.students[j].grade<<endl;
											j++;

									 }
								 }


					         State = 1;
					         value1=0;
					         value = 0;
					         fileline++;

							}

							  else
					       {
					         switch(State)
					         {

					          case 1:
					           switch(a)
					           {

					            default:
                      if(a>='0'&&a<='9')
					            {
					            value = value*10 + a - '0';
					            State = 2;

										}
										else
										{

										}
					            break;
					            }
					          break;

					          case 2:
					          switch(a)
					          {
					            case ',':
					              State = 3;
												cout<<"value"<<value<<endl;


					              if((value>maxAcceptableID||value<minAcceptableID))
					              {
													count++;

														rejects.rejects[index]=fileline;
														rejects.numRejects = count;
														cout<<"rejects"<<rejects.rejects[index]<<endl;
														cout<<"rejectsnumber"<<rejects.numRejects<<endl;
														index++;
					              }


					              break;
					           default:
					          if((a>='0'&&a<='9')){
					           unsigned int currentintvalue = a - '0';
										 value = value*10 + a - '0';
					           State = 2;
										 }


					         }
					         break;

					        case 3:

					        switch(a)
					        {
					          default:
					          if((a>='0'&&a<='9'))
					          {
										value1 = value1*10 + a - '0';
					           State = 3;
										 cout <<"grade"<< value1 << endl;
					           }


					         else {}
					         //
					           break;
					         }
					     break;
					     }
					       }
							 }



          if(fin.get()!='\n')
				{
					if(value>=minAcceptableID&&value<=maxAcceptableID)
					{
					if(value1>100||value1<0)
					{
						count++;

							rejects.rejects[index]=count;
							rejects.numRejects = index + 1;
							cout<<"rejects"<<rejects.rejects[index]<<endl;
							cout<<"rejectsnumber"<<rejects.numRejects<<endl;
							index++;
					}
					else
					{

						 data.students[j].studentID = value;
						 data.students[j].grade = value1;
						 data.numStudents= j+1;
						 cout<<"datastudents id"<<data.students[j].studentID<<endl;
						cout<<"datagrade"<<data.students[j].grade<<endl;
						 j++;

					}
			   	}
					}

          if(rejects.numRejects>=10)
					{
					  return -1;
					}
					if(count>0)
					return 2;
					else
					return 0;

}

int computeStatistics(Dataset& data, Statistics& stats){


			stats.minimum = minimum(data,data.numStudents);
			stats.average = average(data,data.numStudents);
		  stats.maximum = maximum(data,data.numStudents);
		  stats.popStdDev = popStdDev(data,data.numStudents);
		  stats.smplStdDev = smplStdDev(data,data.numStudents);
		  stats.mode.numModes = mode(stats,data,data.numStudents);
			int counter=0;
			int counter1=0;
			int counter2=0;
			int counter3=0;
			int counter4=0;
			int counter5=0;
			int counter6 =0;
			int counter7 =0;
			int counter8=0;
			int counter9=0;

		 for(int i =0;i<10;i++)
		 {
			 stats.histogram[i] = 0;
		 }


			for(int i =0;i<data.numStudents ;i++)
			{
				if(data.students[i].grade>=0&&data.students[i].grade<=9)
				 {
					 counter++;
					 stats.histogram[0]=counter;

				 }
				 else if(data.students[i].grade>=10&&data.students[i].grade<=19)
				 {
					 counter1++;
					 stats.histogram[1]= counter1;
				 }
				 else if(data.students[i].grade>=20&&data.students[i].grade<=29)
				 {
					 counter2++;
					 stats.histogram[2]=counter2;
				 }
				 else if(data.students[i].grade>=30&&data.students[i].grade<=39)
				 {
					 counter3++;
					 stats.histogram[3]=counter3;
				 }
				 else if(data.students[i].grade>=40&&data.students[i].grade<=49)
				 {
					 counter4++;
					 stats.histogram[4]=counter4;
				 }
				 else if(data.students[i].grade>=50&&data.students[i].grade<=59)
				 {
					 counter5++;
					 stats.histogram[5]=counter5;
				 }
				 else if(data.students[i].grade>=60&&data.students[i].grade<=69)
				 {
					 counter6++;

					 stats.histogram[6]=counter6;
				 }
				 else if(data.students[i].grade>=70&&data.students[i].grade<=79)
				 {
					 counter7++;

					 stats.histogram[7]=counter7;
				 }
				 else if(data.students[i].grade>=80&&data.students[i].grade<=89)
				 {
					 counter8++;

					 stats.histogram[8]=counter8;
				 }
				 else if(data.students[i].grade>=90&&data.students[i].grade<=100)
				 {
					 counter9++;

					 stats.histogram[9]=counter9;
				 }


		}




	return 0;
}

int writeCSV(const char filename[], const Statistics& stats){

	std::ofstream fout;
	char a[100];
	int size = 0;
	int sign = 0;
	char filename1[100];

	for(int j=0; filename[j]!= '\0';j++){
		filename1[j]=filename[j];
		size ++;
}


for(int j =0;filename[j]!='\0';j++)
{
if(filename[j]=='.')
{
	filename1[j+1]='s';
	filename1[j+2]='t';
	filename1[j+3] = 'a';
	filename1[j+4] = 't';
	filename1[j+5]=  '\0';
	sign =1;

	break;
}
}

if(sign==0)
{
 filename1[size]='.';
 filename1[size+1]='s';
 filename1[size+2]='t';
 filename1[size+3]='a';
 filename1[size+4]='t';
 filename1[size+5] = '\0';




}
cout<<endl<<"filename1"<<filename1<<endl;



	fout.open(filename1);

	if(!fout.is_open())
	{
		return -1;
	}



	fout<<"Minimum: "<<stats.minimum<<std::endl;
	 fout<<"Average: "<<stats.average<<std::endl;
	 fout<<"Maximum: "<<stats.maximum<<std::endl;
	  fout<<"Population Standard Deviation: "<<stats.popStdDev <<std::endl;

     fout<<"Sample Standard Deviation: "<<stats.smplStdDev<<std::endl;
		  fout<<"Modes: "<<stats.mode.modes[0];
			for(int i =1;i<stats.mode.numModes;i++)
			{
				fout<<", "<<stats.mode.modes[i];
			}
			fout<<endl;
			fout<<"Histogram:"<<endl;
			 fout<<"[0-9]: "<<stats.histogram[0]<<endl;
			 fout<<"[10-19]: "<<stats.histogram[1]<<endl;
			 fout<<"[20-29]: "<<stats.histogram[2]<<endl;
			  fout<<"[30-39]: "<<stats.histogram[3]<<endl;
				fout<<"[40-49]: "<<stats.histogram[4]<<endl;
				fout<<"[50-59]: "<<stats.histogram[5]<<endl;
				fout<<"[60-69]: "<<stats.histogram[6]<<endl;
				fout<<"[70-79]: "<<stats.histogram[7]<<endl;
				fout<<"[80-89]: "<<stats.histogram[8]<<endl;
				fout<<"[90-100]: "<<stats.histogram[9]<<endl;

	return 0;
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

	// Some test driver code here ....
	int minAcceptableID = 20000000;
	int maxAcceptableID = 30000000;

	Dataset data = {0};
	Rejects rejects = {0};
	Statistics stats = {0};

	std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;


	if(readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects) <= 0)
	{
		std::cout << ".csv file could not be read" << std::endl;
	}
	 readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects);


	if (computeStatistics(data, stats) < 0)
	{
		std::cout << "Stats could not be computed" << std::endl;
	}

	if (writeCSV(argv[1], stats) < 0)
	{
		std::cout << ".stat file could not be written" << std::endl;
	}

	std::cout << "Average: " << stats.average << std::endl;
	std::cout << "Minimum: " << stats.minimum << std::endl;
	std::cout << "Maximum: " << stats.maximum << std::endl;
	std::cout << "Population standard deviation: " << stats.popStdDev << std::endl;
	std::cout << "Sample standard deviation: " << stats.smplStdDev << std::endl;


	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{
		std::cout << "Mode: " << stats.mode.modes[i] << std::endl;
	}

	for (unsigned char i = 0; i < 10; i++)
	{
		std::cout << "Histogram bin [" << (i*10) << ", " << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	}


	return 0;
}

#endif
