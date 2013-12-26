#
# Makefile for ALL Workspace
#
include ./make.h

TARGETS	 =  agentapd

COMMON_OBJS = 
OBJS = main.o $(COMMON_OBJS)

all: $(LIBS) $(TARGETS)

$(TARGETS):$(OBJS)
	$(CC) $(CC_OUTPUT_FLAGS) $(TARGETS) $(OBJS)

.c.o:
	$(CC) $(CC_FLAGS)  $(COMMON_INCLUDE_DIRS)  $<

clean:
	$(RM) $(RM_FLAGS) $(OBJS) $(TARGETS)
	$(RM) $(RM_FLAGS) *.lib *.bak *.a *~


