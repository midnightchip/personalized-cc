TARGET := iphone:clang:latest:7.0
INSTALL_TARGET_PROCESSES = SpringBoard


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = writeanywhere

writeanywhere_FILES = Server.m
writeanywhere_CFLAGS = -fobjc-arc
writeanywhere_LIBRARIES = mryipc

include $(THEOS_MAKE_PATH)/tweak.mk
