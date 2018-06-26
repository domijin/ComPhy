double fy(double x, double l)
{
  double a,b,c;
  a=l*(l+1)/2;
  b=a*(l*l+l-2)/8.;
  c=b*(l*l+l-6)/18.;
  return(1+a*x+b*x*x+c*x*x*x);
}
