#include <tests/tests.h>
#include <tests/buffer.h>

void
run_tests(void)
{
	const char *module;
       


	/* Buffer */
	module = "buffer";

	puts("-- Buffer Tests --\n");

	RUN_TEST(nonexistent);
	RUN_TEST(existent);
	RUN_TEST(nowrite);
	RUN_TEST(noread);
}
