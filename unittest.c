#ifndef UNITTEST_MAIN
#include "unittest.h"
#include <assert.h>
#include <stdlib.h>
#endif

unittest("2 + 2 == 4, not fish") { ensure(2 + 2 == 4); }

unittest("randomly fails") {
	int r = rand();
	ensure(r < RAND_MAX / 2);
}
