all:
	gcc src/primitive.c -c -o src/primitive.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	gcc src/v2.c -c -o src/v2.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	gcc src/v3.c -c -o src/v3.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	gcc src/v4.c -c -o src/v4.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	gcc src/m2.c -c -o src/m2.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	gcc src/m3.c -c -o src/m3.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	gcc src/m4.c -c -o src/m4.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	gcc src/q.c -c -o src/q.o -I./include/ML -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	ar rvs libML.a src/primitive.o src/v2.o src/v3.o src/v4.o src/m2.o src/m3.o src/m4.o src/q.o
clean:
	rm libML.a src/*.o
install:
	mkdir -p /usr/include/ML
	cp include/ML/*.h /usr/include/ML
	cp libML.a /usr/lib/
