CC ?= gcc
CFLAGS += -std=gnu89 -Wall -Wextra -Werror -Wno-variadic-macros -Wwrite-strings -lncurses -Isources/ -g

SRCS := $(shell find sources/ -name '*.c' -type f)
OBJS := $(SRCS:.c=.o)

all: options ciska
ciska: $(OBJS)
	@echo -e cc\\t\\t$^\\t$@
	@$(CC) -o $@ $^

%.o: %.c
	@echo -e cc\\t\\t$<
	@$(CC) $(CFLAGS) -o $@ -c $<

options:
	@echo -e "cc     = $(CC)"
	@echo -e "cflags = $(CFLAGS)"
	@echo

.PHONY: clean mrclean
clean:
	rm -f $(OBJS)
mrclean:
	rm -f ciska
