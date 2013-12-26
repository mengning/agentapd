#
# Makefile for utils dir
#
include ../make.h


OBJS = common.o os_unix.o radiotap.o

all:	$(OBJS) 
	$(AR) $(AR_FLAGS) $(UTILS_LIB) $(OBJS) 


.c.o:
	$(CC) $(CC_FLAGS)  $(COMMON_INCLUDE_DIRS) $<

clean:

	$(RM) -f  $(OBJS) $(UTILS_LIB) *.bak *~


