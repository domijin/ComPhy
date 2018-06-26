# Problem 2
funct1: solver.o funct1.o # Route 1 f(x)=x^3-10x+10
	g++ solver.cpp funct1.cpp -o run1 -lm
funct2: solver.o funct2.o # Route 2 f(x)=x^2-10+10/x
	g++ solver.cpp funct2.cpp -o run2 -lm
clean:
	rm *.o run1 run2
