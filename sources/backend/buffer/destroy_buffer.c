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
#include <stdlib.h>

void
destroy_buffer(struct buffer *buffer)
{
	if (buffer->content != NULL)
		free(buffer->content);
	free(buffer);
}
