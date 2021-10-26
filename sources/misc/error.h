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
#ifndef _ERROR_H
# define _ERROR_H 1

# define OK (0)
# define NO_FILE (1)
# define CANNOT_OPEN_FILE (2)
# define ALLOC_FAILED (3)

extern int	cerror;

#endif /* _ERROR_H */
