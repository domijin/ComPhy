# just a makefile
CPP = g++
SRC = fg.cpp fy.cpp fyderiv.cpp solver.cpp
FLG = -lm
compile: ${SRC:.cpp=.o}
	${CPP} ${SRC} -o run ${FLG}
clean:
	rm *.o run