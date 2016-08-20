FLAGS = -Iinclude -Werror
BINS = bin/test-quicksort bin/*o

all: bin/quicksort.o test

bin/quicksort.o: src/quicksort.c include/quicksort.h
	gcc ${FLAGS} -c -o bin/quicksort.o src/quicksort.c

test: bin/test-quicksort

bin/test-quicksort: test/test-quicksort.c bin/quicksort.o
	gcc ${FLAGS} -o bin/test-quicksort test/test-quicksort.c bin/quicksort.o

clean:
	rm ${BINS}
