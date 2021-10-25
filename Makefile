BUILD_ROOT := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))


LIBESTC3D_PATH = $(BUILD_ROOT)/libestc3d/
TESTAPP_PATH = $(BUILD_ROOT)/testapp/


all: libestc3dlib


libestc3dlib:
	make -C $(LIBESTC3D_PATH)


clean:
	make -C $(LIBESTC3D_PATH) clean


