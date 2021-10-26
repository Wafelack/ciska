/*
 *  ciska - ciska is a screen-oriented text editor
 *  Copyright (C) 2021   Wafelack <wafelack@riseup.net>
 *
 *  ------------------------------------------------------
 *
 *     This file is part of ciska.
 *
 *  ciska is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ciska is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ciska.  If not, see <https://www.gnu.org/licenses/>.
 */
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
