sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk

$(D)generator := $(abspath generator/generator)

$(D)all: $(D)generator
	touch $(@D)/all

$(D)generator: $(D)generator.cpp
	g++ -o $@ $^

D := $(dirstack_$(sp))
sp := $(basename $(sp))
