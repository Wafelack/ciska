#include <assert.h>
#include <backend/buffer.h>
#include <misc/error.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


	struct buffer *
init_buffer(const char *fname)
{
	struct buffer *buf = malloc(sizeof(struct buffer));
	if (buf == NULL) {
		cerror = ALLOC_FAILED;
		return NULL;
	}

	buf->curX = 0;
	buf->curY = 0;
	buf->mode = NORMAL;
	buf->content = NULL;
	buf->fname = fname;

	if (fname == NULL)
		buf->status = NO_FILENAME;
	else if (access(fname, F_OK) == 0) {
		if (access(fname, R_OK) == 0) {
			FILE *fp;
			size_t flen, i;
			buf->status = access(fname, W_OK) == 0 ? EVEN : READ_ONLY;

			fp = fopen(fname, "rb");
			if (fp == NULL) {
				cerror = CANNOT_OPEN_FILE;

				free(buf);
				return NULL;
			}

			fseek(fp, 0, SEEK_END); /* Get file size */
			flen = ftell(fp);
			rewind(fp);

			buf->content = malloc(flen + 1); /* NULL terminator */
			if (buf->content == NULL) {
				cerror = ALLOC_FAILED;

				free(buf);
				return NULL;
			}

			for (i = 0; i < flen; i++)
				assert(fread(buf->content + i, 1, 1, fp) == 1);
			buf->content[flen] = 0;

			fclose(fp);
		} else {
			cerror = CANNOT_OPEN_FILE;

			free(buf);
			return NULL;
		}
	} else
		buf->status = MODIFIED;
	return buf;
}
