include ../paths.mk
include ../common_defs.mk

BINARY_NAME = libestc3d
BINARY_PATH = $(BIN_DIR)/$(BINARY_NAME).a

SRCS := estc3d.c
OBJS := $(foreach obj,$(SRCS), obj/$(obj).o ) 


.PHONY: $(BINARY_NAME)

$(BINARY_NAME): $(BINARY_PATH)

$(BINARY_PATH): $(OBJS)
	$(AR) rcs -o $@ $<

clean:
	@rm -f $(OBJS) $(BINARY_PATH)


