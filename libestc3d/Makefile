include ../paths.mk
include ../common_defs.mk

BINARY_NAME = libestc3d
BINARY_PATH = $(BIN_DIR)/$(BINARY_NAME).a

SRCS := estc3d.c
OBJS := $(foreach obj,$(SRCS), obj/$(obj).o ) 

.depend: $(SRCS)
	gcc -MM $^ -o $@

include .depend

.PHONY: $(BINARY_NAME)

$(BINARY_NAME): $(BINARY_PATH)



obj:
	mkdir -p obj

$(BINARY_PATH): obj $(OBJS)
	$(AR) rcs -o $@ $(OBJS)

clean:
	@rm -f $(OBJS) $(BINARY_PATH)


