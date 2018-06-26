# Chance "xsinx" to cubic to get solver for
# 
CXX = g++

LDFLAGS=-lm

#FN=cubic
FN=xsinx
secsoln: ${FN}.o secant.o 
	${CXX}  ${FN}.o secant.o -o $@ ${LDFLAGS}

clean:
	rm *.o
