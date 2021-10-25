###############################################################################
#                 Root paths, paths for binary, etc..                         #
###############################################################################
BUILD_ROOT := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
BIN_DIR := $(BUILD_ROOT)/bin
