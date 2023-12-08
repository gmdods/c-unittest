#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNITTEST_MAIN
#include "unittest.h"

int main(int argc, const char * argv[]) {
	srand(time(NULL));

#include "unittest.c"

	summary();
	return 0;
}
