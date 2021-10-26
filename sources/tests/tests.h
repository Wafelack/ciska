#ifndef _TESTS_H
# define _TESTS_H 1

# include <stdio.h>
# include <stdlib.h>

# define RUN_TEST(fun) printf("%s:%s ... \033[0;%s\033[0m\n", module, #fun, fun() == 0 ? "32mok" : "31mfailed")

# define ENSURE(statement, fname)\
	if (!(statement)) {\
		printf("%s is FALSE. Aborting.\n", #statement);\
		if (fname != NULL) {\
			remove(fname); \
			free(fname);\
		}\
		return 1;\
	}

void run_tests(void);

#endif /* _TESTS_H */
