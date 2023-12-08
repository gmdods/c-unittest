# c-unittest
C patterns and macros for integrating unit tests.

- `unittest.h` contains macros for integration.
- `test.c` is the pattern for a main test file.
- `Makefile` has define macros for `unittest.h` options.
- `unittest.c` is an example of a test file.
    - Note the include guards!

Local variables in the macros have the prefix `unittest_`,
which should be uncommon/clear enough not to be used.

`unittest.h` only exports macros, no special functions.

