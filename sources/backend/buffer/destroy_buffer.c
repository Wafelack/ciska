#include <backend/buffer.h>
#include <stdlib.h>

void
destroy_buffer(struct buffer *buffer)
{
	if (buffer->content != NULL)
		free(buffer->content);
	free(buffer);
}
