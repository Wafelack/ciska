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
#include <sys/stat.h>
#include <tests/buffer.h> 
#include <tests/tests.h>

int
nowrite(void)
{
	struct buffer *buf;
	char *filename = __buffer_test_genfile("");

	ENSURE(filename != NULL, NULL);
	ENSURE(chmod(filename, 0555) == 0, filename);

	buf = init_buffer(filename);
	ENSURE(buf != NULL, filename);

	ENSURE(buf->status == READ_ONLY, filename);
	ENSURE(buf->content != NULL, filename);

	ENSURE(remove(filename) == 0, filename);
	free(filename);
	destroy_buffer(buf);

	return 0;
}
