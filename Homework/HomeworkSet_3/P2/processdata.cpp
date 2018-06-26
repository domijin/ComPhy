/****************
Problem 2
 File operation
     Dongming
****************/
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main()
{
  ifstream input;//file pointer to read
  ofstream output;//file pointer to write
  input.open("in.dat");
  output.open("out.dat");
  double temp;
  while(input>>temp)//read in from given file
    {
      output<<fixed<<sqrt(temp+1)<<endl;//output to file with required format
    }
  input.close();//close files
  output.close();
  return 0;
}
