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
