TARGET := iphone:clang:14.4:14.1

include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = prefs

prefs_FILES = $(shell find Sources/prefs -name '*.swift') $(shell find Sources/prefsC -name '*.m' -o -name '*.c' -o -name '*.mm' -o -name '*.cpp')
prefs_INSTALL_PATH = /Library/PreferenceBundles
prefs_SWIFTFLAGS = -ISources/prefsC/include
prefs_EXTRA_FRAMEWORKS += Cephei CepheiPrefs
prefs_LIBRARIES = mryipc
prefs_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/bundle.mk
