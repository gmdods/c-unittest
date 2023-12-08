#ifndef UNITTEST_MACROS
#define UNITTEST_MACROS

// indirection pattern
#define CAT(lhs, rhs) lhs##rhs
#define CONCAT(lhs, rhs) CAT(lhs, rhs)

// unused variable name anew
#define ANEW(var) CONCAT(var, __LINE__)

#endif // !UNITTEST_MACROS

#ifdef UNITTEST_MAIN
#include <assert.h>

#define unittest(str) if(1)
#define ensure(expr) assert(expr)

#else // !UNITTEST_MAIN

#define unittest(str) void ANEW(fn)(void)
#define ensure(expr) ((void *) 0)

#endif // UNITTEST_MAIN
