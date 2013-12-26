#
# Makefile for common dir
#
include ../make.h


OBJS =	ieee802_11_common.o 

all:	$(OBJS) 
	$(AR) $(AR_FLAGS) $(COMMON_LIB) $(OBJS) 


.c.o:
	$(CC) $(CC_FLAGS)  $(COMMON_INCLUDE_DIRS) $<

clean:

	$(RM) -f  $(OBJS) $(COMMON_LIB) *.bak *~


