FLAGS = -Iinclude -Werror -ggdb
BINS = bin/array.o bin/test-quicksort bin/quicksort.o bin/heap.o bin/test-heap \
        bin/binsearch.o bin/test-binsearch

all: ${BINS}

bin/quicksort.o: src/quicksort.c include/quicksort.h
	gcc ${FLAGS} -c -o bin/quicksort.o src/quicksort.c

test: bin/test-quicksort

bin/array.o: include/array.h src/array.c
	gcc ${FLAGS} -c -o bin/array.o src/array.c

bin/test-quicksort: test/test-quicksort.c bin/quicksort.o
	gcc ${FLAGS} -o bin/test-quicksort test/test-quicksort.c bin/quicksort.o bin/array.o

bin/heap.o: src/heap.c include/heap.h
	gcc ${FLAGS} -c -o bin/heap.o src/heap.c

bin/binsearch.o: src/binsearch.c include/binsearch.h
	gcc ${FLAGS} -c -o bin/binsearch.o src/binsearch.c

bin/test-heap: test/test-heap.c bin/heap.o include/heap.h
	gcc ${FLAGS} -o bin/test-heap test/test-heap.c bin/heap.o

bin/test-binsearch: test/test-binsearch.c bin/binsearch.o include/binsearch.h bin/array.o
	gcc ${FLAGS} -o bin/test-binsearch test/test-binsearch.c bin/binsearch.o bin/array.o

clean:
	rm ${BINS}
