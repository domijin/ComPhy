# Execuable file run1 ~ run 5 will generate file uniform.dat and import_sampling.dat
# For the Straightforward Monte Carlo Integration, the second output is Importance 
# Sampling with p(x)=1, so it should be same as Straightforward MC integrationnn
#
# Calculating PI
pi: pi.cpp
	g++ pi.cpp -o runPI
# Straightforward Monte Carlo Integration for x^(-1/3)+x/10 from 0 to 1
xfun1: xfun1.cpp mc_integral.cpp 
	g++ xfun1.cpp mc_integral.cpp -o run1 -lm
# Importance Sampling Monte Carlo Integration for x^(-1/3)+x/10 from 0 to 1, p(x)=2/3*x^(-1/3)
xfun2: xfun2.cpp mc_integral.cpp 
	g++ xfun2.cpp mc_integral.cpp -o run2 -lm
# Straightforward Monte Carlo Integration for exp(-x*x/2) from 0 to 1
exp1: exp1.cpp mc_integral.cpp
	g++ exp1.cpp mc_integral.cpp -o run3 -lm
# Importance Sampling Monte Carlo Integration for exp(-x*x/2) from -inf to inf, p(x)=1/sqrt(2*pi)*exp(-x*x/2)
exp2: exp2.cpp mc_integral.cpp
	g++ exp2.cpp mc_integral.cpp -o run4 -lm
# Importance Sampling Monte Carlo Integration for exp(-x*x/2)*sin(x) from -inf to inf, p(x)=1/sqrt(2*pi)*exp(-x*x/2)
expsin: expsin.cpp mc_integral.cpp
	g++ expsin.cpp mc_integral.cpp -o run5 -lm
# GSL library example for 3-D integration
gslmc: gslmc.cpp
	g++ gslmc.cpp -lgsl -o runGSL
clean:
	rm *.o run* *.dat 