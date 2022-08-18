CFLAGS += -Wall -Werror -O3
CSRC = $(wildcard src/*.c)
OBJS = $(CSRC:%.c=%.o)
DEPS := $(CSRC:%.c=%.d)
all: src/lib.o
# all: libc.a
%.o:%.c; $(CC) -MD -MF $*.d $(CFLAGS) -c -o $@ $<
clean:; $(RM) -r $(OBJS) $(DEPS) libc.a
libc.a:$(OBJS); $(RM) $@; $(AR) ru $@ $^
$(DEPS):
include $(wildcard $(DEPS))
