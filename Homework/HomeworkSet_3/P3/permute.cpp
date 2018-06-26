/*********************
Problem 3
Permutation of array
           Dongming
 ********************/
#include<iostream>
using namespace std;
int main()
{
  int a[4],N;
  for(int i=0;i<5;i++)
    a[i]=i+1;//Generate designed array
  cout<<"Enter the number of times you want to have 1 2 3 4 5 permuted"<<endl;
  cin>>N;
  cout<<" The permutation by "<<N<<" is:"<<endl;
  for(int i=0;i<5;i++)
    cout<<a[(i+N)%5]<<'\t';//Mod the sum of indice and permatation times by array length to get new indice rapidly
  cout<<endl;
  return 0;
}
