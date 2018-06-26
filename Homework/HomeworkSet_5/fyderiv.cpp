double fyderiv(double x, double l)
{
  double a,b,c;
  a=l*(l+1)/2;
  b=a*(l*l+l-2)/8.;
  c=b*(l*l+l-6)/18.;
  return(a+2*b*x+3*c*x*x);
}
