CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra \
	 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function \
	 -march=native -Og -g
DEPS = unittest.h
FILES = unittest.c


verbose: verbose.out
.PHONY: verbose

verbose.out: test.c $(DEPS) $(FILES)
	$(CC) $(CFLAGS) -DUNITTEST_VERBOSE $< -o $@ && ./$@

verbose.i: test.c $(DEPS) $(FILES)
	$(CC) $(CFLAGS) -DUNITTEST_VERBOSE -E $< -o $@

test: test.out
.PHONY: test

test.out: test.c $(DEPS) $(FILES)
	$(CC) $(CFLAGS) $< -o $@ && ./$@

test.i: test.c $(DEPS) $(FILES)
	$(CC) $(CFLAGS) -E $< -o $@

clean:
	rm *.i *.out
