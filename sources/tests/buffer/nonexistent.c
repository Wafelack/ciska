#include <backend/buffer.h>
#include <misc/error.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <tests/buffer.h>
#include <tests/tests.h>

int
nonexistent(void)
{
	struct buffer *buf;
	char filename[] = "toto31415926535897932"; 

	cerror = 0;
	buf = init_buffer(filename);
	
	ENSURE(buf != NULL, NULL);
	ENSURE(buf->content == NULL, NULL);
	ENSURE(buf->status == MODIFIED, NULL);

	destroy_buffer(buf);

	return 0;
}
