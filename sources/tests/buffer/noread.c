#include <backend/buffer.h>
#include <misc/error.h>
#include <sys/stat.h>
#include <tests/buffer.h>
#include <tests/tests.h>

int
noread(void)
{
	struct buffer *buf;
	cerror = 0;
	char *filename = __buffer_test_genfile("");

	ENSURE(filename != NULL, NULL);
	ENSURE(chmod(filename, 0) == 0, filename);

	
	buf = init_buffer(filename);
	ENSURE(buf == NULL, filename);
	ENSURE(cerror == CANNOT_OPEN_FILE, filename);

	ENSURE(remove(filename) == 0, filename);
	free(filename);

	return 0;
}
