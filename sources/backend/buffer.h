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
