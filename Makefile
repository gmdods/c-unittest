C = gcc
CFLAGS = -Wall -Wpedantic -Wextra -Wno-unused-variable \
	-Wno-unused-function -march=native -O3
DEPS = unittest.h
FILES = unittest.c

test: test.out
.PHONY: test

test.o: test.c $(DEPS) $(FILES)
	$(C) $(CFLAGS) -c $< -o $@

test.out: test.o
	$(C) $(CFLAGS) $? -o $@ && ./$@

clean:
	rm *.o *.out
