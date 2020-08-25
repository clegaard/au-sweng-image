

# Building isort library

all : libisort.a

test : libisort.a test_insertion_sort_array.c
	gcc test_insertion_sort_array.c -L. -lisort

libisort.a : insertion_sort_array.o
	ar rcs $@ $?

insertion_sort_array.o : insertion_sort_array.c
	gcc -c $?

clean:
	rm *.o
	rm *.a 
	rm *.out




 