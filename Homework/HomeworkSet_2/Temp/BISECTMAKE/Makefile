# Problem 4
cubic: solver.o cubic.o # for function f(x)=x^3-10x+10
	g++ solver.cpp cubic.cpp -o run1 -lm
xsinx: bisect2.o xsinx.o # for function f(x)=x*sin(x)
	g++ solver.cpp xsinx.cpp -o run2 -lm
clean:
	rm *.o run1 run2
