include ../paths.mk
include ../common_defs.mk

BINARY_NAME = testapp
BINARY_PATH = $(BIN_DIR)/$(BINARY_NAME)

#Sources and other dependencies
SRCS := main.c
LIBS := estc3d


OBJS := $(SRCS:.c=.o) 
LDLIBS += $(addprefix  -l, $(LIBS))
LDLIBS_PATHS := $(foreach lib,$(LIBS), $(BIN_DIR)/lib$(lib).a ) 


.PHONY: $(BINARY_NAME)

$(BINARY_NAME): $(BINARY_PATH)

$(BINARY_PATH): $(OBJS) $(LDLIBS_PATHS)
	$(LD) $(LDFLAGS) -o $@ $< $(LDLIBS)

clean:
	@rm -f $(OBJS) $(BINARY_PATH) .depend

.depend: $(SRCS)
	gcc -MM $^ -o $@

include .depend		


