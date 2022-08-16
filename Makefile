CFLAGS += -Wall -Werror
CSRC = $(wildcard src/*.c)
OBJS = $(CSRC:%.c=%.o)
DEPS := $(CSRC:%.c=%.d)
all: libc.a
%.o:%.c; $(CC) -MMD -MF $*.d $(CFLAGS) -c -o $@ $<
clean:; $(RM) -r $(OBJS) $(DEPS) libc.a
libc.a:$(OBJS) $(DEPS); $(RM) $@; $(AR) ru $@ $^
$(DEPS):
include $(wildcard $(DEPS))
