FLAGS = -Iinclude -Werror
BINS = bin/array.o bin/test-quicksort bin/quicksort.o

all: ${BINS}

bin/quicksort.o: src/quicksort.c include/quicksort.h
	gcc ${FLAGS} -c -o bin/quicksort.o src/quicksort.c

test: bin/test-quicksort

bin/array.o: include/array.h src/array.c
	gcc ${FLAGS} -c -o bin/array.o src/array.c

bin/test-quicksort: test/test-quicksort.c bin/quicksort.o
	gcc ${FLAGS} -o bin/test-quicksort test/test-quicksort.c bin/quicksort.o bin/array.o

clean:
	rm ${BINS}
