all:
	gcc ml.c -c -o ml.o -std=c11 -ffast-math -g -O2 -lc -lm
	ar rvs libml.a ml.o
clean:
	rm ml.o	libml.a
install:
	cp ml.h /usr/include/
	cp libml.a /usr/lib/
