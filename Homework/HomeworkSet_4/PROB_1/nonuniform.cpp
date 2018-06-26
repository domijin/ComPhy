/**********************************
Nonuniform cards pile
                 Dongming Jin
                 Feb. 2014
 **********************************/
#include<iostream>
#include<stdlib.h>// for Rand function
#include<time.h>// cpu time
using namespace std;
int main()
{
  int p,N;
  int low=0,high=0;// since there are only 2 cases

  cout<<"How many times do you want to run the experiment?\n";
  cin>>N;
  srand (time(NULL));// using cpu time as random seed

  for(int k=0;k<N;k++)// for user specifed sets of games
    {
      p=14.*rand()/RAND_MAX;// maping 5-14 to 5-9 to make it double chances to have high cards
      if(p<=4)
	low++;
      if(p>4)
	high++;
    }
  cout<<endl;
  cout<<"number of low cards= "<<low<<" number of high cards= "<<high<<endl;

  double average=(low*2.+high*7.)/(1.*N);
  cout<<"Averge= "<<average<<endl;
  return(0);
}
