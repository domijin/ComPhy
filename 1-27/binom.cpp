/********************************************************
 *      For PHYSCS 6352  Program written Jan 8, 2014    *
 *  Computing mean and variance for 10 coin flips. One  *
 *  can think of tails as 0 and heads as 1.             *
 *  The user specifies N, the number of times that the  *
 *  "experiment" of doing 10 coin flips will be done.   *
 *******************************************************/

#include<iostream>
#include<stdlib.h>           // needed for RAND
#include<time.h>             // needed for true randomness

using namespace std;


int N;
int x,k,m,j,sum;
int p[12]={0,0,0,0,0,0,0,0,0,0,0,0};  
int sum_pmtimesm=0;            //for calculating mean
int sum_pmtimesmsq=0;          //for calcuating variance


int main()
{
  cout<<" How many times do you want to run the experiment?\n";
  cin>>N;
  srand (time(NULL));            //so that "rand" gives a true random variable


  //START OUTER LOOP
 for(k=0;k<N;k++)   
   {
     sum=0; 
             //START INNER LOOP
     for(j=0;j<10;j++)            //the inner loop; each loop is one set of 10
              {                   //coin flips
                x=(1.0*rand()/1.0/RAND_MAX+.5);
		sum=sum+x;
		}
	      
               for(m=0;m<11;m++)    //update the p array that keeps track of how
		 {                  //many times a particular set of heads occurred.
		if(sum==m) p[m]=p[m]+1;
	
		 }
	       //END INNER LOOP
   }
//END OUTER LOOP	      	        

//START WRITE-OUT SECTION
cout<<"   \n";

// display the whole distribution from 0 heads to 10 heads
cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<" "<<p[4]<<" "<<p[5]<<" "<<p[6]<<" "<<p[7]<<" "<<p[8]<<" "<<p[9]<<" "<<p[10]<<endl;

 for(m=1;m<11;m++)
               {
		 sum_pmtimesm+=m*p[m];
		 sum_pmtimesmsq+=m*m*p[m];
		}

 double mean=(1.0*sum_pmtimesm)/(1.0*N);
 double variance=(1.0*sum_pmtimesmsq)/(1.0*N)-mean*mean;



 cout<<"mean= "<<mean<<endl;

 cout<<"variance= "<<variance<<endl;

 cout<<"Reminder: ideal mean =0.5; ideal variance =2.5\n";

  return(0);
}
