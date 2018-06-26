# Problem 3, just a makefile
CPP = g++
SRC = function.cpp rk4solver.cpp
FLG = -lm
compile: ${SRC:.cpp=.o}
	${CPP} ${SRC} -o rk4solve ${FLG}
clean:
	rm *.o rk4solve