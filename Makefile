all:
	gcc ML.c -c -o ML.o -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	ar rvs libML.a ML.o
clean:
	rm ML.o	libML.a
install:
	cp ML.h /usr/include/
	cp libML.a /usr/lib/
