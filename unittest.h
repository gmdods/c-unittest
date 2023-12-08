#ifndef UNITTEST_MACROS
#define UNITTEST_MACROS

// indirection pattern
#define CAT(lhs, rhs) lhs##rhs
#define CONCAT(lhs, rhs) CAT(lhs, rhs)

// unused variable name anew
#define ANEW(var) CONCAT(var, __LINE__)

#endif // !UNITTEST_MACROS

#undef unittest
#undef ensure

#ifndef UNITTEST_MAIN

#define unittest(str) void ANEW(fn)(void)
#define ensure(expr) assert(expr)

#else // UNITTEST_MAIN

#ifndef UNITTEST_VERBOSE

#include <assert.h>

#define unittest(str) if (1)
#define ensure(expr) assert(expr)

#else // UNITTEST_VERBOSE

#include <stdio.h>

void unittest_result(const char * str, unsigned error) {
	if (error)
		printf("unittest `%s` had %u errors\n", str, error);
	else
		printf("unittest `%s` passed\n", str);
}

unsigned unittest_assert(const char * str, unsigned ok) {
	if (!ok) printf("assertion `%s` failed\n", str);
	return !ok;
}

#define unittest(str) \
	putchar('\n'); \
	for (unsigned unittest_error = 0, unittest_once = 0; \
	     !unittest_once || (unittest_result(str, unittest_error), 0); \
	     ++unittest_once)
#define ensure(expr) unittest_error += unittest_assert(#expr, (expr))

#endif // !UNITTEST_VERBOSE

#endif // !UNITTEST_MAIN
