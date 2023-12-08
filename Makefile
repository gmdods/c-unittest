C = gcc
CFLAGS = -Wall -Wpedantic -Wextra -Wno-unused-variable \
	-Wno-unused-function -march=native -O3
DEPS = unittest.h
FILES = unittest.c


verbose: verbose.out
.PHONY: verbose
verbose.out: test.c $(DEPS) $(FILES)
	$(C) $(CFLAGS) -DUNITTEST_VERBOSE $< -o $@ && ./$@

test: test.out
.PHONY: test
test.out: test.c $(DEPS) $(FILES)
	$(C) $(CFLAGS) $< -o $@ && ./$@

clean:
	rm *.out
