# Change between "cubic" and "xsinx" to get
# solutions for different functions.

CXX = g++

LDFLAGS=-lm

METHOD=newton

FN=cubic
#FN=xsinx

$(METHOD)soln: ${FN}.o $(METHOD).o 
	${CXX}  ${FN}.o $(METHOD).o -o $@ ${LDFLAGS}

clean:
	rm *.o  *~
