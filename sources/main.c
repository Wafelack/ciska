#include <assert.h>
#include <backend/buffer.h>
#include <misc/error.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <tests/tests.h>

int cerror = 0;

int
main(void)
{
	#ifndef RELEASE_MODE
	 run_tests();
	#endif
	return 0;
}
