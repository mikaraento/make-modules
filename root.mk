.SUFFIXES:
MAKEFLAGS += -r	

D := root
$(D) := root.mk

OUT := build

$(D)/cflags := -I.

SO := dylib
