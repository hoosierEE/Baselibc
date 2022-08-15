CFLAGS += -Wall -Werror
CSRC = $(wildcard src/*.c)
OBJS = $(CSRC:.c=.o)
all: libc.a
clean:; $(RM) $(OBJS) libc.a
libc.a:$(OBJS); $(RM) $@; $(AR) ru $@ $^
%.o:%.c; $(CC) $(CFLAGS) -c -o $@ $<
