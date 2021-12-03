TARGET := iphone:clang:14.4:14.1
INSTALL_TARGET_PROCESSES = SpringBoard


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = ccbackground

ccbackground_FILES = $(shell find Sources/ccbackground -name '*.swift') $(shell find Sources/ccbackgroundC -name '*.m' -o -name '*.c' -o -name '*.mm' -o -name '*.cpp')
ccbackground_SWIFTFLAGS = -ISources/ccbackgroundC/include
ccbackground_CFLAGS = -fobjc-arc -ISources/ccbackgroundC/include
ccbackground_EXTRA_FRAMEWORKS += Cephei

include $(THEOS_MAKE_PATH)/tweak.mk
SUBPROJECTS += prefs
SUBPROJECTS += writeanywhere
include $(THEOS_MAKE_PATH)/aggregate.mk
