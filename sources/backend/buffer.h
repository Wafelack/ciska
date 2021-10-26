#ifndef _BUFFER_H
# define _BUFFER_H 1

# include <stdint.h>

enum buf_stat {
	MODIFIED,
	EVEN,
	READ_ONLY,
	NO_FILENAME
};

enum buf_mode {
	NORMAL,
	INSERT
};

struct buffer {
	const char	*fname;
	uint32_t	curX;
	uint32_t	curY;
	enum buf_stat	status;
	uint8_t		*content;
	enum buf_mode	mode;
};

struct buffer	*init_buffer(const char *);
void		destroy_buffer(struct buffer *);

#endif /* _BUFFER_H */
