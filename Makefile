include paths.mk

LIBESTC3D_PATH = $(BUILD_ROOT)/libestc3d/
TESTAPP_PATH = $(BUILD_ROOT)/testapp/


all: libestc3dlib testapp

bin:
	mkdir -p $(BIN_DIR)

libestc3dlib: bin
	make -C $(LIBESTC3D_PATH)


testapp: bin  libestc3dlib
	make -C $(TESTAPP_PATH)

clean:
	make -C $(LIBESTC3D_PATH) clean
	make -C $(TESTAPP_PATH) clean







