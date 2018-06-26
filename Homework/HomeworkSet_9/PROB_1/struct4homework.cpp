/*************
Prob #1
*****************/
#include<iostream>
#include<string>
#include<math.h>

using namespace std;
const double PI=4.*atan(1);
const double Lsolar=3.846e26;
/********* Define struct type "stardata"*****/

struct  stardata{
  string name;
  double mass;
  double radius;
  double temperature;
} thesun,sirius;// Define another stardata sirius

/******* Define function properties that uses the struct data type ****/
void properties(stardata thesun)
{
  double dens=thesun.mass;
  dens=3.*thesun.mass/4./PI/thesun.radius/thesun.radius/thesun.radius;
  double sigma=5.6704e-8;
  double luminosity=4.*PI*sigma*pow(thesun.temperature,4)*pow(thesun.radius,2);
  cout<<"The density of "<<thesun.name<<" is "<<dens<<" kg/m^3\n";
  cout<<"The luminosity of "<<thesun.name<<" is "<<luminosity<<" W\n";
  cout<<"The absolute magnitude of "<<thesun.name<<" is "<<log10(luminosity/Lsolar)<<endl;
};

int main(){

  thesun.mass=1.981e30;
  thesun.name="the Sun";
  thesun.radius=6.96342e8;
  thesun.temperature=5700;

  //Assign basics to stardata Sirius for Sirius A
  sirius.mass=1.981e30*2.02;
  sirius.name="Sirius A";
  sirius.radius=6.96342e8*1.711;
  sirius.temperature=9940;
  
  properties(sirius);

  cout<<endl;

  //Assign basics to stardata Sirius for Sirius B
  sirius.mass=1.981e30*0.978;
  sirius.name="Sirius B";
  sirius.radius=6.96342e8*0.0084;
  sirius.temperature=25200;

  properties(sirius);

  return(0);}


