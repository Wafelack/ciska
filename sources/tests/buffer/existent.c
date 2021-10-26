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
#include <backend/buffer.h>
#include <misc/error.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tests/buffer.h>
#include <tests/tests.h>

char *
__buffer_test_genfile(const char *expected)
{
	FILE *fp;
	char filename[] = "foobarXXXXXX";
	size_t i, l;

	if (mkstemp(filename) == -1) return NULL;

	fp = fopen(filename, "w+");
	fputs(expected, fp);
	fclose(fp);

	l = strlen(filename);
	char *nfn = malloc(l);
	if (nfn == NULL) return nfn;
	for (i = 0; i < l; i++)
		nfn[i] = filename[i];
	nfn[l] = 0;
	return nfn;
}

int
existent(void)
{
	const char *expected = "Hello, World !";
	size_t i, l;
	struct buffer *buf;
	char *filename = __buffer_test_genfile(expected);
	
	ENSURE(filename != NULL, NULL);

	/* Test */
	buf = init_buffer(filename);
	ENSURE(buf != NULL, filename);
	
	ENSURE(buf->status == EVEN, filename);
	
	l = strlen(expected);
	for (i = 0; i < l; i++) {
		char a, b;

		a = buf->content[i];
		b = expected[i];

		ENSURE(a == b, filename);
	}

	/* Cleanup */
	ENSURE(remove(filename) == 0, filename);
	free(filename);
	destroy_buffer(buf);

	return 0;
}
