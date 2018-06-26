/****************************
Coin flipping, plot every 10 
sets
             Dongming Jin
             Feb. 2014
****************************/
#include<iostream>
#include<stdlib.h>// library rand function
#include<time.h>// cpu time as random seed
#include<fstream>// file operation
#include<math.h>// round function
#include<random>// random function generator
using namespace std;
int main()
{
  int N;
  int p,sum;
  int hist[11]={0,0,0,0,0,0,0,0,0,0,0};// 0~10 enough, histogram
  int sum_pmtimesm=0;// for calculating mean
  int sum_pmtimesmsq=0;// for calcuating variance
  ofstream real,ideal;// output file pointer

  real.open("real.dat");
  ideal.open("ideal.dat");

  cout<<" How many times do you want to run the experiment?\n";
  cin>>N;
  srand (time(NULL));// cpu time as random seed

  for(int i=0;i<N;i++)// for each set of games
    {
      sum=0;
      for(int j=0;j<10;j++)// 10 times for each set
	{
	  p=round(rand()*1.0/RAND_MAX);// return 1 or 0 randomly as head or tail
	  sum=sum+p;
	}
      for(int k=0;k<11;k++)// make histogram
	if(sum==k) 
	  hist[k]=hist[k]+1;
    }
  
  // output histogram information
  for(int i=0;i<11;i++)
     real<<hist[i]<<endl;

  // calculate mean and variance
  for(int i=0;i<11;i++)
    {
      sum_pmtimesm+=i*hist[i];
      sum_pmtimesmsq+=i*i*hist[i];
    }
  double mean=(1.0*sum_pmtimesm)/(1.0*N);
  double variance=(1.0*sum_pmtimesmsq)/(1.0*N)-mean*mean;
  real<<"mean= "<<mean<<endl;
  real<<"variance= "<<variance<<endl;

  // gaussian distribution random number generator
  /* I get confused by generating an external file "ideal.dat" to put into a plotting routine to generate the "ideal" values. I think you ask us to plot an ideal gaussian plot of mean 0.5 and variance 2.5. Actually, it should be binomial distribution and that's what I use to reverse the ideal data.
   */

  //  /*  
  default_random_engine generator;
  binomial_distribution<int> distribution(10,0.5);
  int id[11]={};
  for(int i=0;i<N;i++)
    {
      p=distribution(generator);
      ++id[p];
    }
  for(int i=0;i<11;i++)
    ideal<<id[i]<<endl;
//  */

  ideal<<"Reminder: ideal mean =0.5; ideal variance =2.5\n";

  // release pointer to close file
  real.close();
  ideal.close();
  return(0);
}
