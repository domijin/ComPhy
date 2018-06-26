// f=z(x,y,z)=y'
double f(double x, double y, double z)
{
  return(z);
}

// g=z'(x,y,y',l)=y"
double g(double x, double y, double z, double l)
{
  return(2*x/(1-x)/(1+x)*z-l*(l+1)/(1-x)/(1+x)*y);
}
